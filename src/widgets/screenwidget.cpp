#include "screenwidget.h"
#include "qpainter.h"

ScreenWidget::ScreenWidget(QWidget *parent)
    : QWidget{parent}
{
    setScreenSize(256, 256);
    setAutoFillBackground(false);
}

void ScreenWidget::setScreenSize(int width, int height)
{
    this->width = width;
    this->height = height;
    for(int i=0;i<this->width;i++)
    {
        for(int j=0;j<this->height;j++)
        {
            colors[QPair(i,j)] = QColor::fromRgb(0, 0, 0);
        }
    }
}

int ScreenWidget::getWidth() const
{
    return width;
}

void ScreenWidget::setWidth(int newWidth)
{
    width = newWidth;
}

int ScreenWidget::getHeight() const
{
    return height;
}

void ScreenWidget::setHeight(int newHeight)
{
    height = newHeight;
}

void ScreenWidget::setPixelColor(int x, int y, int color)
{
    if(x < width && y < height)
        colors[QPair(x, y)] = QColor::fromRgb((color >> 5) * 255 / 7, ((color >> 2) & 0x07) * 255 /7, (color & 0x03) * 255 / 3);
}

void ScreenWidget::paintEvent(QPaintEvent *event)
{
    QWidget::paintEvent(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);
    const double cellSize = std::min(static_cast<double>(rect().width()) / width, static_cast<double>(rect().height()) / height);
    const double offsetX = (rect().width() - (cellSize * width)) / 2.0;
    const double offsetY = (rect().height() - (cellSize * height)) / 2.0;
    for(int i=0;i<width;i++)
    {
        for(int j=0;j<height;j++)
        {
            QRectF rect(offsetX + i * cellSize, offsetY + j * cellSize, cellSize, cellSize);
            painter.fillRect(rect, colors.value(QPair(i, j)));
        }
    }
}
