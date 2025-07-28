#include "hovertooltipwidget.h"
#include "qboxlayout.h"

HoverTooltipWidget::HoverTooltipWidget(QWidget *parent)
    : QWidget{parent}
{
    setMouseTracking(true);
    QVBoxLayout* hoverTooltipWidgetLayout = new QVBoxLayout(this);
    hoverTooltipLabel = new QLabel(this);
    hoverTooltipWidgetLayout->addWidget(hoverTooltipLabel);
    setLayout(hoverTooltipWidgetLayout);
    setWindowFlag(Qt::ToolTip);
}

void HoverTooltipWidget::setText(const QString &text)
{
    hoverTooltipLabel->setText(text);
}

bool HoverTooltipWidget::isHovering() const
{
    return hovering;
}

void HoverTooltipWidget::enterEvent(QEnterEvent *event)
{
    QWidget::enterEvent(event);
    hovering = true;
}

void HoverTooltipWidget::leaveEvent(QEvent *event)
{
    QWidget::leaveEvent(event);
    hovering = false;
}
