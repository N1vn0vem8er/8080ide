#include "helpwidget.h"
#include "ui_helpwidget.h"

HelpWidget::HelpWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HelpWidget)
{
    ui->setupUi(this);
}

void HelpWidget::openHelp(QString instruction) const
{
    if(helpInstructions.contains(instruction))
    {
        ui->tabWidget->setCurrentIndex(1);
        ui->tab_2->openInstructionHelp(instruction.toLower());
    }
    else if(helpPseudoInstructions.contains(instruction))
    {
        ui->tabWidget->setCurrentIndex(2);
        ui->tab_3->openInstructionHelp(instruction.toLower());
    }
}

HelpWidget::~HelpWidget()
{
    delete ui;
}
