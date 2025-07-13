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
    int lineNumberWidth() const;
    void lineNumberAreaPaint(QPaintEvent* event) const;
    QString getFilePath() const;
    void setFilePath(QString path);
    void commentCurrentLine();
    void setHighlighterEnabled(bool val);
    bool isHighlighterEnabled();
    void commentMultiLine() const;
    void highlightTextSequence(const QString &text);
    void replaceTextSequence(const QString &find, const QString &replace);
    void clearSearchFormatting();
    void setSpellCheckEnabled(bool val);
    void setSaved(bool val);
    void setProjectPath(const QString& path);
    void setPartOfProject(bool val);
    bool isSaved() const;
    bool isPartOfProject() const;
    void setLineBreakpoint();
    bool hasBreakPoints() const;
    QVector<int> getBreakPoints();
    void highlightLine(int line);
    void stepLineHightlight(int line);
    QString getInstructionFromSelectedLine();
    bool isSpellcheckEnabled() const;
    void increaseFontSize();
    void decreaseFontSize();
    void setFontSize(int size);
    void mergeSelectedLines();
    void deleteSelected() const;
    void deleteAll();
    QString getName() const;
    bool isSaveWarningEnabled() const;
    void setSaveWarningEnabled(bool val);

protected:
    void resizeEvent(QResizeEvent *event) override;
    void focusInEvent(QFocusEvent *e) override;
    void keyPressEvent(QKeyEvent *e) override;
    void dropEvent(QDropEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragLeaveEvent(QDragLeaveEvent* event) override;
    void wheelEvent(QWheelEvent *event) override;

private slots:
    void insertCompletion(const QString& completion);
    void updateWordsList(const QStringList& list);
private:
    void updateLineNumberWidth(int count);
    void updateLineNumber(const QRect &rect, int dy);
    void startGettingLabels();
    void updateBreakpoints(int newCount);
    int oldLineCount = 0;
    bool saveWarningEnabled {true};
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

signals:
    void fontSizeChanged(int size);

};

#endif // CODEEDITOR_H
