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

public slots:
    void setPixelColor(int x, int y, int color);

private:
    int width;
    int height;
    QMap<QPair<int, int>,QColor> colors;

signals:

protected:
    void paintEvent(QPaintEvent *event) override;
};

#endif // SCREENWIDGET_H
