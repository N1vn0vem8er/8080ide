#ifndef HOVERTOOLTIPWIDGET_H
#define HOVERTOOLTIPWIDGET_H

#include "qlabel.h"
#include <QWidget>

class HoverTooltipWidget : public QWidget
{
    Q_OBJECT
public:
    explicit HoverTooltipWidget(QWidget *parent = nullptr);
    void setText(const QString& text);
    bool isHovering() const;

signals:

private:
    QLabel* hoverTooltipLabel;
    bool hovering = false;

protected:
    void enterEvent(QEnterEvent *event) override;
    void leaveEvent(QEvent *event) override;
};

#endif // HOVERTOOLTIPWIDGET_H
