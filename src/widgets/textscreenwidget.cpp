#include "textscreenwidget.h"
#include <QPainter>
#include <QScrollBar>

TextScreenWidget::TextScreenWidget(QWidget *parent)
    : QAbstractScrollArea{parent}
{
    QFont font("Consolas", 10);
    font.setStyleHint(QFont::Monospace);
    setFont(font);
    QFontMetrics fm(font);
    lineHeight = fm.height();
}

void TextScreenWidget::appendText(const QString &text)
{
    if(!lines.isEmpty() && !text.contains("\n") && lines.last().size() < verticalScreenSize)
    {
        lines.last().append(text);
    }
    else
    {
        if(text == "\n")
            lines.append("");
        else
        {
            const QStringList newLines = text.split('\n', Qt::SkipEmptyParts);
            for(const QString& line : newLines)
            {
                if(lines.size() >= maxLines)
                    lines.removeFirst();
                lines.append(line);
            }
        }
    }
    updateScrollBars();
    QScrollBar* vBar = verticalScrollBar();
    bool autoScroll = (vBar->value() == vBar->maximum());
    if(autoScroll)
        vBar->setValue(vBar->maximum());
    viewport()->update();
}

void TextScreenWidget::clear()
{
    lines.clear();
    updateScrollBars();
    viewport()->update();
}

void TextScreenWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(viewport());
    painter.setFont(font());
    painter.fillRect(viewport()->rect(), Qt::black);
    painter.setPen(Qt::white);

    int linesOnScreen = viewport()->height() / lineHeight + 2;
    int startLine = verticalScrollBar()->value();
    int endLine = qMin(startLine + linesOnScreen, lines.size());
    int y = 0;
    for(int i = startLine; i < endLine; ++i)
    {
        painter.drawText(5, y + lineHeight - 3, lines[i]);
        y += lineHeight;
    }
}

void TextScreenWidget::resizeEvent(QResizeEvent *event)
{
    updateScrollBars();
    verticalScreenSize = viewport()->width() / 5;
    QAbstractScrollArea::resizeEvent(event);
}

void TextScreenWidget::updateScrollBars()
{
    int visibleLines = viewport()->height() / lineHeight;
    verticalScrollBar()->setRange(0, qMax(0, lines.size() - visibleLines));
    verticalScrollBar()->setPageStep(visibleLines);
}
