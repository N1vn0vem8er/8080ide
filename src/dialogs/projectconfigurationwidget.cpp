#include "projectconfigurationwidget.h"
#include "ui_projectconfigurationwidget.h"

ProjectConfigurationWidget::ProjectConfigurationWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProjectConfigurationWidget)
{
    ui->setupUi(this);
}

ProjectConfigurationWidget::~ProjectConfigurationWidget()
{
    delete ui;
}
