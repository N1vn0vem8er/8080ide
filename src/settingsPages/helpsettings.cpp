#include "helpsettings.h"
#include "ui_helpsettings.h"
#include "idesettings.h"

HelpSettings::HelpSettings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::HelpSettings)
{
    ui->setupUi(this);
    connect(ui->applyButton, &QPushButton::clicked, this, &HelpSettings::apply);
    ui->helpCode->setCurrentIndex(IDESettings::showHelpTypeCode);
    ui->helpAnywhere->setCurrentIndex(IDESettings::showHelpTypeAny);
}

HelpSettings::~HelpSettings()
{
    delete ui;
}

void HelpSettings::apply() const
{
    IDESettings::showHelpTypeCode = ui->helpCode->currentIndex() ? IDESettings::tab : IDESettings::window;
    IDESettings::showHelpTypeAny = ui->helpAnywhere->currentIndex() ? IDESettings::tab : IDESettings::window;
    IDESettings::showHelpDialogSize = resolutions[ui->comboBox->currentIndex() < resolutions.size()? ui->comboBox->currentIndex() : 0];
    IDESettings s;
    s.saveSettings();
}
