#include "guiprojectconfigwidget.h"
#include "ui_guiprojectconfigwidget.h"

GuiProjectConfigWidget::GuiProjectConfigWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::GuiProjectConfigWidget)
{
    ui->setupUi(this);
}

GuiProjectConfigWidget::~GuiProjectConfigWidget()
{
    delete ui;
}
