#include "exampleswidget.h"
#include "ui_exampleswidget.h"

ExamplesWidget::ExamplesWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ExamplesWidget)
{
    ui->setupUi(this);
}

ExamplesWidget::~ExamplesWidget()
{
    delete ui;
}
