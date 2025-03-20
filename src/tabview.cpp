#include "tabview.h"
#include "qpainter.h"

void TabView::paintEvent(QPaintEvent* e )
{
    QTabWidget::paintEvent(e);
    QPainter painter(this);
    if(!count())
    {
        painter.setPen(QColor::fromRgb(122, 122, 122));
        painter.drawText(rect(), Qt::AlignCenter, tr("CTRL + N - New File\n\nCTRL + O - Open File\n\nCTRL + SHIFT + O - Open Directory\n\nCTRL + S - Save file\n\nCTRL + SHIFT + S - Save file as\n\nCTRL + W - Close file"));
    }
}
