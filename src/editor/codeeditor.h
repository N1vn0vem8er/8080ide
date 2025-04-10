#ifndef CODEEDITOR_H
#define CODEEDITOR_H
#include "labelfinder.h"
#include "qlineedit.h"
#include "qobject.h"
#include "qtmetamacros.h"
#include "qwidget.h"
#include "qplaintextedit.h"
#include "syntaxhighlighter.h"
class CodeEditor : public QPlainTextEdit
{
    Q_OBJECT

public:
    CodeEditor(QWidget *parent = nullptr);
    ~CodeEditor();
    int lineNumberWidth();
    void lineNumberAreaPaint(QPaintEvent* event);
    QString getFilePath();
    void setFilePath(QString path);
    void commentCurrentLine();
    void setHighlighterEnabled(bool val);
    bool isHighlighterEnabled();
    void commentMultiLine();
    void highlightTextSequence(const QString &text);
    void replaceTextSequence(const QString &find, const QString &replace);
    void clearSearchFormatting();
    void setSpellCheckEnabled(bool val);
    void setSaved(bool val);
    void setProjectPath(const QString& path);
    void setPartOfProject(bool val);
    bool isSaved();
    bool isPartOfProject();
    void setLineBreakpoint();
    bool hasBreakPoints();
    QVector<int> getBreakPoints();
    void highlightLine(int line);
    void stepLineHightlight(int line);
    QString getInstructionFromSelectedLine();
    bool isSpellcheckEnabled() const;

protected:
    void resizeEvent(QResizeEvent *event) override;
    void focusInEvent(QFocusEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;
    void dropEvent(QDropEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragLeaveEvent(QDragLeaveEvent* event) override;
private slots:
    void insertCompletion(const QString& completion);
    void updateWordsList(const QStringList& list);
private:
    void updateLineNumberWidth(int count);
    void updateLineNumber(const QRect &rect, int dy);
    void startGettingLabels();
    void updateBreakpoints(int newCount);
    int oldLineCount = 0;
    QWidget* lineNumberArea;
    SyntaxHighLighter* highLighter = nullptr;
    QString filePath;
    QCompleter* compliter = nullptr;
    QString textUnderCursor() const;
    QTextCharFormat defaultFormat;
    bool waitingForInput;
    void clearChearchFormattingAfterTextChanged();
    bool isApplyingSpellCheck;
    int cursorLocation;
    bool spellCheckEnabled;
    bool saved;
    LabelFinder* labelFinder = nullptr;
    QStringList wordsList;
    QStringList previousLabelsList;
    bool partOfProject = false;
    QString projectPath = "";
    QStringList instructions;
    bool hasBreakpoints = false;
    QVector<int> linesWithBreakpoint;
    void checkChanged();
    QString orginalContent;
};

#endif // CODEEDITOR_H
