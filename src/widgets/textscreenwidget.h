#ifndef TEXTSCREENWIDGET_H
#define TEXTSCREENWIDGET_H

#include "qabstractscrollarea.h"
#include <QWidget>

class TextScreenWidget : public QAbstractScrollArea
{
    Q_OBJECT
public:
    explicit TextScreenWidget(QWidget *parent = nullptr);
    void appendText(const QString &text);
    void clear();

protected:
    void paintEvent(QPaintEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void updateScrollBars();
    QStringList lines;
    int lineHeight;
    int verticalScreenSize {0};
    int maxLines = 5000;
};

#endif // TEXTSCREENWIDGET_H
