#ifndef LINENUMBERAREA_H
#define LINENUMBERAREA_H
#include "codeeditor.h"
#include "qwidget.h"
class LineNumberArea : public QWidget
{
public:
    LineNumberArea(CodeEditor *editor) : QWidget(editor), codeEditor(editor)
    {}

    QSize sizeHint() const override
    {
        return QSize(codeEditor->lineNumberWidth(), 0);
    }

protected:
    void paintEvent(QPaintEvent *event) override
    {
        codeEditor->lineNumberAreaPaint(event);
    }

private:
    CodeEditor *codeEditor;
};
#endif // LINENUMBERAREA_H
