#include "screenwidget.h"
#include "qpainter.h"
#include <QPainterPath>
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
        switch(mode)
        {
        case Modes::PIXEL:
        {
            QRgb* line = reinterpret_cast<QRgb*>(imageBuffer.scanLine(y));
            line[x] = colors[color & 0xFF];
        }
            break;
        case Modes::LINE:
        {
            QPainter painter(&imageBuffer);
            painter.setPen(QColor(colors[color]));
            painter.drawLine(lineSelect1.first, lineSelect1.second, lineSelect2.first, lineSelect2.second);
            mode = Modes::PIXEL;
        }
            break;
        case Modes::FIGURE:
        {
            QPainter painter(&imageBuffer);
            painter.setPen(QColor(colors[color]));
            QPolygon polygon;
            for(const auto& point : std::as_const(select))
            {
                polygon.append(QPoint(point.first, point.second));
            }
            painter.drawPolygon(polygon);
            select.clear();
            mode = Modes::PIXEL;
        }
            break;
        case Modes::FILL:
        {
            QPainter painter(&imageBuffer);
            painter.setBrush(QBrush(QColor(colors[color])));
            painter.setPen(QColor(colors[color]));
            QPolygon polygon;
            for(const auto& point : std::as_const(select))
            {
                polygon.append(QPoint(point.first, point.second));
            }
            painter.drawPolygon(polygon);
            select.clear();
            mode = Modes::PIXEL;
        }
            break;
        }
        scheduleRepaint();
    }
}

void ScreenWidget::executeCommand(int x, int y, Commands command)
{
    switch(command)
    {
    case Commands::CLEAR:
        imageBuffer.fill(Qt::black);
        break;
    case Commands::CANCEL:
        mode = Modes::PIXEL;
        break;
    case Commands::LINESELECT1:
        lineSelect1 = QPair(x, y);
        break;
    case Commands::LINESELECT2:
        lineSelect2 = QPair(x, y);
        mode = Modes::LINE;
        break;
    case Commands::FILLSELECT:
        select.append(QPair(x, y));
        mode = Modes::FILL;
        break;
    case Commands::FIGURESELECT:
        select.append(QPair(x, y));
        mode = Modes::FIGURE;
        break;
    }
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
