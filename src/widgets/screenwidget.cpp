#include "screenwidget.h"
#include "qpainter.h"
#include <QTimer>

ScreenWidget::ScreenWidget(QWidget *parent)
    : QWidget{parent}
{
    setScreenSize(256, 256);
    for(int c = 0; c < 256; c++)
    {
        int r = (c >> 5) & 0x07;
        int g = (c >> 2) & 0x07;
        int b = c & 0x03;
        int R = r * 255 / 7;
        int G = g * 255 / 7;
        int B = b * 255 / 3;
        colors[c] = qRgba(R, G, B, 255);
    }
    setAutoFillBackground(false);
}

void ScreenWidget::setScreenSize(int width, int height)
{
    this->width = width;
    this->height = height;
    imageBuffer = QImage(width, height, QImage::Format_ARGB32_Premultiplied);
    imageBuffer.fill(Qt::black);
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
    {
        QRgb* line = reinterpret_cast<QRgb*>(imageBuffer.scanLine(y));
        line[x] = colors[color & 0xFF];
        scheduleRepaint();
    }
}

void ScreenWidget::executeCommand(int x, int y, Commands command)
{

}

void ScreenWidget::scheduleRepaint()
{
    if(repaintScheduled) return;
    repaintScheduled = true;
    QTimer::singleShot(0, this, [this]{
        repaintScheduled = false;
        update();
    });
}

QRect ScreenWidget::getRectScale() const
{
    double s  = std::min((static_cast<double>(rect().width()) / static_cast<double>(width)), (static_cast<double>(rect().height()) / static_cast<double>(height)));
    int drawW = int(std::round(width * s));
    int drawH = int(std::round(height * s));
    int ox = (rect().width()  - drawW) / 2;
    int oy = (rect().height() - drawH) / 2;
    return QRect(ox, oy, drawW, drawH);

}

void ScreenWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setRenderHint(QPainter::SmoothPixmapTransform, false);
    painter.drawImage(getRectScale(), imageBuffer);
}
