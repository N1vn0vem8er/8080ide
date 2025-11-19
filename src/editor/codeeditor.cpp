#include "codeeditor.h"
#include "LineNumberArea.h"
#include "labelfinder.h"
#include "qabstractitemview.h"
#include "qfileinfo.h"
#include "qmimedata.h"
#include <QTimer>
#include <QCompleter>
#include <QPainter>
#include <QTextBlock>
#include <QStringListModel>
#include <QScrollBar>
#include <QCryptographicHash>
#include <idesettings.h>
#include <QMenu>
#include <QClipboard>

CodeEditor::CodeEditor(QWidget *parent) : QPlainTextEdit(parent)
{
    setMouseTracking(true);
    lineNumberArea = new LineNumberArea(this);
    connect(this, &CodeEditor::blockCountChanged, this, &CodeEditor::updateLineNumberWidth);
    connect(this, &CodeEditor::updateRequest, this, &CodeEditor::updateLineNumber);
    connect(this, &QPlainTextEdit::textChanged, this,  &CodeEditor::startGettingLabels);
    connect(this, &CodeEditor::blockCountChanged, this, &CodeEditor::updateBreakpoints);
    connect(this, &CodeEditor::undoAvailable, this, [&](bool val){undoAvaliable = val;});
    connect(this, &CodeEditor::redoAvailable, this, [&](bool val){redoAvaliable = val;});
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &CodeEditor::customContextMenuRequested, this, &CodeEditor::showContextMenu);
    updateLineNumberWidth(0);
    highLighter = new SyntaxHighLighter(this->document());
    instructions << "MVI" << "MOV" << "STAX" << "LDAX" << "LDA" << "STA" <<
                "RZN" << "RZC" << "RPO" << "RP" << "JNZ" << "JNC" <<
                "JPO" << "JP" << "JMP" << "CNZ" << "CNC" << "CPO" <<
                "CP" << "RST" << "RET" << "PCHL" << "RZ" << "RC" <<
                "RPE" << "RM" << "JZ" << "JC" << "JPE" << "JM" <<
                "CZ" << "CC" << "CPE" << "CM" << "CALL" << "RNC" <<
                "INR" << "DCR" << "RLC" << "RAL" << "bAA" << "STC" <<
                "RRC" << "RAR" << "CMA" << "CMC" << "ADD" << "SUB" <<
                "ADC" << "SBB" << "ANA" << "XRA" << "ORA" << "CMP" <<
                "ADI" << "SUI" << "ANI" << "ORI" << "ACI" << "SBI" <<
                "XRI" << "CPI" << "LXI" << "SHLD" << "LHLD" << "POP" <<
                "PUSH" << "SPHL" << "XCHG"<< "NOP" << "HLT" << "OUT" <<
                "IN" << "DI" << "EI" << "INX"<<"DAD"<<"DCX" << "DAA" <<
                "STRING" << "ARRAY" << "EQU" << "SET" <<
                "ENDIF" << "IF" << "ENDM" << "MACRO" << "DW" << "DB";
    wordsList << instructions;
    compliter = new QCompleter(wordsList, this);
    compliter->setWidget(this);
    compliter->setCompletionMode(QCompleter::PopupCompletion);
    compliter->setModelSorting(QCompleter::CaseInsensitivelySortedModel);
    compliter->setCaseSensitivity(Qt::CaseSensitive);
    compliter->setWrapAround(false);
    connect(compliter, QOverload<const QString&>::of(&QCompleter::activated), this, &CodeEditor::insertCompletion);
    defaultFormat = textCursor().charFormat();
    waitingForInput = false;
    connect(this, &QPlainTextEdit::textChanged, this, &CodeEditor::clearChearchFormattingAfterTextChanged);
    isApplyingSpellCheck = false;
    spellCheckEnabled = true;
    connect(this, &QPlainTextEdit::textChanged, this, &CodeEditor::checkChanged);
    saved = true;
    startGettingLabels();

    hoverTimer = new QTimer(this);
    connect(hoverTimer, &QTimer::timeout, this, [&]{
        hoverTooltipWidget->show();
    });
    hoverTimer->setSingleShot(true);
    hoverTooltipWidget = new HoverTooltipWidget(this);
}

int CodeEditor::lineNumberWidth() const
{
    int digits = 1;
    int max = qMax(1, blockCount());
    while (max >= 10)
    {
        max /= 10;
        ++digits;
    }
    int space = 3 + fontMetrics().horizontalAdvance(QLatin1Char('9')) * digits;
    if(hasBreakpoints)
        space += fontMetrics().horizontalAdvance("●");
    return space;
}
void CodeEditor::lineNumberAreaPaint(QPaintEvent* event) const
{
    QPainter painter(lineNumberArea);
    painter.fillRect(event->rect(), QColor::fromRgb(27, 25, 26));
    QTextBlock block = firstVisibleBlock();
    int blockNumber = block.blockNumber();
    int top = qRound(blockBoundingGeometry(block).translated(contentOffset()).top());
    int bottom = top + qRound(blockBoundingRect(block).height());
    while (block.isValid() && top <= event->rect().bottom())
    {
        if (block.isVisible() && bottom >= event->rect().top())
        {
            QString number = QString::number(blockNumber + 1);
            if(hasBreakpoints)
                if(linesWithBreakpoint.contains(blockNumber))
                    number = "●" + number;
            painter.setPen(QColor::fromRgb(148, 138, 138));
            painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(), Qt::AlignRight, number);
        }
        block = block.next();
        top = bottom;
        bottom = top + qRound(blockBoundingRect(block).height());
        ++blockNumber;
    }
}

void CodeEditor::updateLineNumberWidth(int)
{
    setViewportMargins(lineNumberWidth(), 0, 0, 0);
}
void CodeEditor::updateLineNumber(const QRect &rect, int dy)
{
    if (dy)
        lineNumberArea->scroll(0, dy);
    else
        lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());
    if (rect.contains(viewport()->rect()))
        updateLineNumberWidth(0);
}

void CodeEditor::startGettingLabels()
{
    if(labelFinder != nullptr)
    {
        labelFinder->requestInterruption();
        labelFinder->wait();
        labelFinder->deleteLater();
        labelFinder = nullptr;
    }
    labelFinder = new LabelFinder();
    connect(labelFinder, &LabelFinder::resoultsReady, highLighter, &SyntaxHighLighter::updateLabels);
    connect(labelFinder, &LabelFinder::resoultsReady, this, &CodeEditor::updateWordsList);
    labelFinder->setText(document()->toPlainText());
    labelFinder->setProjectMode(partOfProject);
    if(isPartOfProject())
        labelFinder->setProjectPath(projectPath);
    labelFinder->start();
}

void CodeEditor::updateBreakpoints(int newCount)
{
    if(oldLineCount > newCount && linesWithBreakpoint.contains(oldLineCount - 1))
    {
        linesWithBreakpoint.removeAll(oldLineCount - 1);
        if(linesWithBreakpoint.isEmpty())
        {
            hasBreakpoints = false;
            updateLineNumberWidth(0);
        }
    }
    oldLineCount = newCount;
}

QString CodeEditor::textUnderCursor() const
{
    QTextCursor tc = textCursor();
    tc.select(QTextCursor::WordUnderCursor);
    return tc.selectedText();
}

void CodeEditor::clearChearchFormattingAfterTextChanged()
{
    if(waitingForInput)
    {
        waitingForInput = false;
        clearSearchFormatting();
    }
}

void CodeEditor::checkChanged()
{
    if(saveWarningEnabled)
        setSaved(toPlainText() == orginalContent ? true : false);
    else
        setSaved(true);
}

void CodeEditor::resizeEvent(QResizeEvent *event)
{
    QPlainTextEdit::resizeEvent(event);

    QRect cr = contentsRect();
    lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberWidth(), cr.height()));
}

void CodeEditor::focusInEvent(QFocusEvent *e)
{
    QPlainTextEdit::focusInEvent(e);
}

void CodeEditor::commentCurrentLine()
{
    QTextCursor cursor = this->textCursor();
    if(cursor.selectedText().isEmpty())
    {
        int pos = cursor.position();
        cursor.movePosition(QTextCursor::StartOfLine);
        QTextBlock curretLine = this->document()->findBlockByLineNumber(cursor.blockNumber());
        if(curretLine.text().length() >=2 && curretLine.text().at(0) == '/' && curretLine.text().at(1) == '/')
        {
            cursor.deleteChar();
            cursor.deleteChar();
            cursor.setPosition(pos - 2);
        }
        else
        {
            cursor.insertText("//");
            this->insertPlainText(cursor.selectedText());
            cursor.setPosition(pos + 2);
        }
        this->setTextCursor(cursor);
    }
    else
    {
        commentMultiLine();
    }
}

void CodeEditor::setHighlighterEnabled(bool val)
{
    highlighterEnabled = val;
    if(highlighterEnabled)
        highLighter->setDocument(this->document());
    else
        highLighter->setDocument(0);
}

bool CodeEditor::isHighlighterEnabled()
{
    return highlighterEnabled;
}

void CodeEditor::commentMultiLine() const
{
    QTextCursor cursor = this->textCursor();
    int pos = cursor.position();
    int start = cursor.selectionStart();
    int end = cursor.selectionEnd();
    QTextBlock startBlock = document()->findBlock(start);
    QTextBlock endBlock = document()->findBlock(end);
    int numberOfLines = endBlock.blockNumber() - startBlock.blockNumber() + 1;
    cursor.beginEditBlock();
    cursor.setPosition(start);
    for(int i = 0; i < numberOfLines; i++)
    {
        if(document()->findBlockByLineNumber(cursor.blockNumber()).text().length() >= 2 && document()->findBlockByLineNumber(cursor.blockNumber()).text()[0] == '/' && document()->findBlockByLineNumber(cursor.blockNumber()).text()[1] == '/')
        {
            cursor.movePosition(QTextCursor::StartOfBlock);
            cursor.deleteChar();
            cursor.deleteChar();
            cursor.movePosition(QTextCursor::NextBlock);
        }
        else
        {
            cursor.movePosition(QTextCursor::StartOfBlock);
            cursor.insertText("//");
            cursor.movePosition(QTextCursor::NextBlock);
        }
    }
    cursor.setPosition(pos);
    cursor.endEditBlock();
}

void CodeEditor::highlightTextSequence(const QString& text, bool caseSensitive)
{
    QList<QTextEdit::ExtraSelection> found;
    QTextCharFormat highlightFormat;
    highlightFormat.setBackground(Qt::yellow);
    QRegularExpressionMatchIterator i = QRegularExpression(caseSensitive ? text : text.toUpper()).globalMatch(caseSensitive ? toPlainText() : toPlainText().toUpper());
    while(i.hasNext())
    {
        QRegularExpressionMatch match = i.next();
        QTextEdit::ExtraSelection es;
        es.format = highlightFormat;
        es.cursor = textCursor();
        es.cursor.setPosition(match.capturedStart());
        es.cursor.setPosition(match.capturedEnd(), QTextCursor::KeepAnchor);
        found.append(es);
    }
    setExtraSelections(found);
    waitingForInput = true;
}

void CodeEditor::highlightTextSequenceInSelected(const QString &text, bool caseSensitive)
{
    QList<QTextEdit::ExtraSelection> found;
    QTextCharFormat highlightFormat;
    highlightFormat.setBackground(Qt::yellow);
    int starts = textCursor().selectionStart();
    QRegularExpressionMatchIterator i = QRegularExpression(caseSensitive ? text : text.toUpper()).globalMatch(caseSensitive ? textCursor().selectedText() : textCursor().selectedText().toUpper());
    while(i.hasNext())
    {
        QRegularExpressionMatch match = i.next();
        QTextEdit::ExtraSelection es;
        es.format = highlightFormat;
        es.cursor = textCursor();
        es.cursor.setPosition(starts + match.capturedStart());
        es.cursor.setPosition(starts + match.capturedEnd(), QTextCursor::KeepAnchor);
        found.append(es);
    }
    setExtraSelections(found);
    waitingForInput = true;
}

void CodeEditor::replaceTextSequence(const QString &find, const QString &replace, bool caseSensitive)
{
    QTextCursor cursor = textCursor();
    cursor.setPosition(0);
    while(true)
    {
        if(caseSensitive)
            cursor = document()->find(find, cursor.position(), QTextDocument::FindFlag::FindCaseSensitively);
        else
            cursor = document()->find(find, cursor.position());
        if(cursor.isNull())
        {
            break;
        }
        cursor.removeSelectedText();
        cursor.insertText(replace);
        setTextCursor(cursor);
    }
}

void CodeEditor::replaceTextSequenceIsSelected(const QString &find, const QString &replace, bool caseSensitive)
{
    QTextCursor cursor = textCursor();
    if(cursor.hasSelection())
    {
        QString selected = cursor.selectedText();
        selected.replace(find, replace, caseSensitive ? Qt::CaseSensitivity::CaseSensitive : Qt::CaseSensitivity::CaseInsensitive);
        cursor.insertText(selected);
        setTextCursor(cursor);
    }
}

void CodeEditor::clearSearchFormatting()
{
    QTextCursor cursor = textCursor();
    cursor.select(QTextCursor::Document);
    cursor.setCharFormat(defaultFormat);
    cursor.clearSelection();
    setTextCursor(cursor);
}

void CodeEditor::setSpellCheckEnabled(bool val)
{
    spellCheckEnabled = val;
    highLighter->setSpellChackEnabled(val);
    highLighter->rehighlight();
}

void CodeEditor::setSaved(bool val)
{
    saved = val;
    emit savedChanged(val);
}

void CodeEditor::setProjectPath(const QString &path)
{
    projectPath = path;
}

void CodeEditor::setPartOfProject(bool val)
{
    partOfProject = val;
}

bool CodeEditor::isSaved() const
{
    return saved;
}

bool CodeEditor::isPartOfProject() const
{
    return partOfProject;
}

void CodeEditor::keyPressEvent(QKeyEvent *e)
{
    if(compliter->popup()->isVisible())
    {
        switch (e->key()) {
        case Qt::Key_Enter:
        case Qt::Key_Return:
        case Qt::Key_Escape:
        case Qt::Key_Tab:
        case Qt::Key_Backtab:
            e->ignore();
            return;
            break;
        default:
            break;
        }
    }
    const bool isShortcut = (e->modifiers().testFlag(Qt::ControlModifier) && e->key() == Qt::Key_E);
    if(!isShortcut)
    {
        QPlainTextEdit::keyPressEvent(e);
    }
    const bool ctrlOrShift = e->modifiers().testFlag(Qt::ControlModifier) || e->modifiers().testFlag(Qt::ShiftModifier);
    if(ctrlOrShift && e->text().isEmpty())
        return;
    static QString eow("~!@#$%^&*()_+{}|:\"<>?,./;'[]\\-=");
    const bool hasModifier = (e->modifiers() != Qt::NoModifier) && !ctrlOrShift;
    QString completionPrefix = textUnderCursor();

    if (!isShortcut && (hasModifier || e->text().isEmpty()|| completionPrefix.length() < 1 || eow.contains(e->text().right(1))))
    {
        compliter->popup()->hide();
        return;
    }
    if(completionPrefix != compliter->completionPrefix())
    {
        compliter->setCompletionPrefix(completionPrefix);
        compliter->popup()->setCurrentIndex(compliter->completionModel()->index(0, 0));
    }
    QRect cr = cursorRect();
    cr.setWidth(compliter->popup()->sizeHintForColumn(0) + compliter->popup()->verticalScrollBar()->sizeHint().width());
    compliter->complete(cr);
}

void CodeEditor::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();
    if(mimeData->hasUrls())
    {
        QFile file(mimeData->urls().at(0).path());
        file.open(QIODevice::ReadOnly);
        if(file.isOpen())
        {
            appendPlainText(file.readAll());
            file.close();
        }
    }
    else if(mimeData->hasText())
    {
        appendPlainText(mimeData->text());
    }
}

void CodeEditor::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void CodeEditor::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void CodeEditor::wheelEvent(QWheelEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->angleDelta().y() > 0)
        {
            increaseFontSize();
        }
        else
        {
            decreaseFontSize();
        }
        event->accept();
    }
    else
        QPlainTextEdit::wheelEvent(event);
}

void CodeEditor::mouseMoveEvent(QMouseEvent *event)
{
    QPlainTextEdit::mouseMoveEvent(event);

    QTextCursor tc = cursorForPosition(event->pos());
    if(!tc.isNull())
    {
        tc.select(QTextCursor::WordUnderCursor);
        QString text = tc.selectedText();
        if(hoverHints.contains(text))
        {
            hoverTimer->stop();
            hoverTooltipWidget->setText(hoverHints.value(text));
            hoverTooltipWidget->move(QCursor::pos());
            hoverTimer->start(500);
        }
        else
        {
            hoverTimer->stop();
            hoverTooltipWidget->hide();
        }
    }
    else
    {
        hoverTooltipWidget->hide();
    }
}

void CodeEditor::leaveEvent(QEvent *event)
{
    QPlainTextEdit::leaveEvent(event);
    hoverTimer->stop();
    hoverTooltipWidget->hide();
}

void CodeEditor::insertCompletion(const QString &completion)
{
    QTextCursor tc = textCursor();
    int extra = completion.length() - compliter->completionPrefix().length();
    tc.movePosition(QTextCursor::Left);
    tc.movePosition(QTextCursor::EndOfWord);
    tc.insertText(completion.right(extra));
    setTextCursor(tc);
}

void CodeEditor::updateWordsList(const QStringList &list)
{
    bool found = false;
    for(const QString& i : list)
    {
        if(instructions.contains(i))
            return;
    }
    for(const QString& i : std::as_const(previousLabelsList))
    {
        if(!list.contains(i))
        {
            wordsList.removeAll(i);
        }
    }
    for(const QString& i : list)
    {
        if(!wordsList.contains(i))
        {
            wordsList.append(i);
            found = true;
        }
    }
    if(found)
    {
        compliter->model()->deleteLater();
        QStringListModel* model = new QStringListModel(wordsList);
        compliter->setModel(model);
    }
    previousLabelsList = list;
}

void CodeEditor::showContextMenu(const QPoint &pos)
{
    QMenu menu(this);
    QAction undo(tr("Undo"), &menu);
    undo.setIcon(QIcon::fromTheme("edit-undo"));
    undo.setEnabled(undoAvaliable);
    connect(&undo, &QAction::triggered, this, &CodeEditor::undo);
    menu.addAction(&undo);
    QAction redo(tr("Redo"), &menu);
    redo.setIcon(QIcon::fromTheme("edit-redo"));
    redo.setEnabled(redoAvaliable);
    connect(&redo, &QAction::triggered, this, &CodeEditor::redo);
    menu.addAction(&redo);
    menu.addSeparator();
    QAction cut(tr("Cut"), &menu);
    cut.setIcon(QIcon::fromTheme("edit-cut"));
    cut.setEnabled(textCursor().hasSelection());
    connect(&cut, &QAction::triggered, this, &CodeEditor::cut);
    menu.addAction(&cut);
    QAction copy(tr("Copy"), &menu);
    copy.setIcon(QIcon::fromTheme("edit-copy"));
    copy.setEnabled(textCursor().hasSelection());
    connect(&copy, &QAction::triggered, this, &CodeEditor::copy);
    menu.addAction(&copy);
    QAction paste(tr("Paste"), &menu);
    paste.setIcon(QIcon::fromTheme("edit-paste"));
    paste.setEnabled(!QGuiApplication::clipboard()->text().isEmpty());
    connect(&paste, &QAction::triggered, this, &CodeEditor::paste);
    menu.addAction(&paste);
    QAction pasteFromFile(tr("Paste from file"), &menu);
    pasteFromFile.setIcon(QIcon::fromTheme("edit-paste"));
    connect(&pasteFromFile, &QAction::triggered, this, [&]{emit this->pasteFromFile();});
    menu.addAction(&pasteFromFile);
    QAction deleteSelected(tr("Delete"), &menu);
    deleteSelected.setIcon(QIcon::fromTheme("edit-delete"));
    connect(&deleteSelected, &QAction::triggered, this, &CodeEditor::deleteSelected);
    menu.addAction(&deleteSelected);
    QAction mergeLines(tr("Merge lines"), &menu);
    connect(&mergeLines, &QAction::triggered, this, &CodeEditor::mergeSelectedLines);
    menu.addAction(&mergeLines);
    menu.addSeparator();
    QAction selectAll(tr("Select All"), &menu);
    selectAll.setIcon(QIcon::fromTheme("edit-select-all"));
    connect(&selectAll, &QAction::triggered, this, &CodeEditor::selectAll);
    menu.addAction(&selectAll);
    menu.addSeparator();
    QAction addBreakpointAction(tr("Breakpoint"), &menu);
    addBreakpointAction.setIcon(QIcon::fromTheme("media-record"));
    connect(&addBreakpointAction, &QAction::triggered, this, [&]{setBreakpointAtLine(cursorForPosition(pos).blockNumber());});
    menu.addAction(&addBreakpointAction);
    menu.exec(QCursor::pos());
}

void CodeEditor::setBreakpointAtLine(int line)
{
    if(linesWithBreakpoint.contains(line)){
        linesWithBreakpoint.removeAll(line);
        if(linesWithBreakpoint.isEmpty())
            hasBreakpoints = false;
    }
    else{
        linesWithBreakpoint.push_back(line);
        hasBreakpoints = true;
    }
    updateLineNumberWidth(0);
}

void CodeEditor::highlightLine(int line)
{

    QTextCursor cursor(document()->findBlockByLineNumber(line));
    cursor.joinPreviousEditBlock();
    cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
    QTextCharFormat format;
    format.setBackground(Qt::red);
    cursor.mergeCharFormat(format);
    cursor.movePosition(QTextCursor::StartOfBlock, QTextCursor::MoveAnchor);
    cursor.endEditBlock();
    setTextCursor(cursor);
}

void CodeEditor::stepLineHightlight(int line)
{
    clearSearchFormatting();
    QTextCursor cursor(document()->findBlockByLineNumber(line));
    cursor.joinPreviousEditBlock();
    cursor.movePosition(QTextCursor::EndOfBlock, QTextCursor::KeepAnchor);
    QTextCharFormat format;
    format.setBackground(IDESettings::lineHighlightColor);
    cursor.mergeCharFormat(format);
    cursor.movePosition(QTextCursor::StartOfBlock, QTextCursor::MoveAnchor);
    cursor.endEditBlock();
    setTextCursor(cursor);
}

QString CodeEditor::getInstructionFromSelectedLine()
{
    QTextCursor cursor = this->textCursor();
    QString line = document()->findBlock(cursor.position()).text();
    int index;
    for(const auto& i : std::as_const(instructions))
    {
        if(i == "IN" && line.indexOf("STRING") != -1) continue;
        if(i == "DI" && line.indexOf("ENDIF") != -1) continue;
        index = line.indexOf(i);
        if(index!= -1)
        {
            return line.mid(index, index + i.length());
        }
    }
    return "";
}

bool CodeEditor::isSpellcheckEnabled() const
{
    return highLighter->getSpellcheckEnabled();
}

void CodeEditor::increaseFontSize()
{
    QFont font = this->font();
    font.setPointSize(font.pointSize() + 1);
    setFont(font);
    emit fontSizeChanged(font.pointSize());
}

void CodeEditor::decreaseFontSize()
{
    QFont font = this->font();
    font.setPointSize(font.pointSize() - 1);
    setFont(font);
    emit fontSizeChanged(font.pointSize());
}

void CodeEditor::setFontSize(int size)
{
    QFont font = this->font();
    font.setPointSize(size);
    setFont(font);
    emit fontSizeChanged(font.pointSize());
}

void CodeEditor::mergeSelectedLines()
{
    QTextCursor cursor = textCursor();
    if(cursor.hasSelection())
    {
        cursor.insertText(cursor.selectedText().replace(QChar(8233), ' '));
        setTextCursor(cursor);
    }
}

void CodeEditor::deleteSelected() const
{
    textCursor().removeSelectedText();
}

void CodeEditor::deleteAll()
{
    selectAll();
    textCursor().removeSelectedText();
}

QString CodeEditor::getName() const
{
    return QFileInfo(filePath).fileName();
}

bool CodeEditor::isSaveWarningEnabled() const
{
    return saveWarningEnabled;
}

void CodeEditor::setSaveWarningEnabled(bool val)
{
    saveWarningEnabled = val;
}

void CodeEditor::setLineBreakpoint()
{
    setBreakpointAtLine(textCursor().blockNumber());
}

bool CodeEditor::hasBreakPoints() const
{
    return hasBreakpoints;
}

QVector<int> CodeEditor::getBreakPoints()
{
    return linesWithBreakpoint;
}

QString CodeEditor::getFilePath() const
{
    return this->filePath;
}
void CodeEditor::setFilePath(QString path)
{
    this->filePath = path;
    if(QFileInfo(path).completeSuffix() == "config")
    {
        setSpellCheckEnabled(false);
        setHighlighterEnabled(false);
    }
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    if(file.isOpen())
    {
        orginalContent = file.readAll();
    }

}
CodeEditor::~CodeEditor()
{
    if(highLighter)
        highLighter->deleteLater();
    if(compliter->model())
        compliter->model()->deleteLater();
    if(compliter)
        compliter->deleteLater();
    if(lineNumberArea)
        lineNumberArea->deleteLater();
    if(labelFinder)
    {
        labelFinder->requestInterruption();
        labelFinder->wait();
        labelFinder->deleteLater();
    }
}

QMap<QString, QString> CodeEditor::hoverHints;
