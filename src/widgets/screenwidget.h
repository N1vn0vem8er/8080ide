#ifndef SCREENWIDGET_H
#define SCREENWIDGET_H

#include <QWidget>

class ScreenWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ScreenWidget(QWidget *parent = nullptr);
    void setScreenSize(int width, int height);
    int getWidth() const;
    void setWidth(int newWidth);
    int getHeight() const;
    void setHeight(int newHeight);
    enum class Commands{
        CLEAR,
        LINESELECT1,
        LINESELECT2,
        CANCEL = 0xff
    };

public slots:
    void setPixelColor(int x, int y, int color);
    void executeCommand(int x, int y, ScreenWidget::Commands command);

private:
    int width;
    int height;
    QImage imageBuffer;
    std::array<QRgb, 256> colors;
    bool repaintScheduled = false;
    QPair<int, int> lineSelect1 {0, 0};
    QPair<int, int> lineSelect2 {0, 0};
    enum class Modes{
        PIXEL,
        LINE,
    };

    Modes mode {Modes::PIXEL};

private:
    void scheduleRepaint();
    QRect getRectScale() const;

signals:

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // SCREENWIDGET_H
