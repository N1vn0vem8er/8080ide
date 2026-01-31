#include "screensettingspage.h"
#include "idesettings.h"
#include "ui_screensettingspage.h"

ScreenSettingsPage::ScreenSettingsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ScreenSettingsPage)
{
    ui->setupUi(this);
    connect(ui->applyButton, &QPushButton::clicked, this, &ScreenSettingsPage::apply);
    ui->openGraphicsScreenComboBox->setCurrentIndex(IDESettings::openScreenType == IDESettings::OpenScreenType::window ? 0 : 1);
}

ScreenSettingsPage::~ScreenSettingsPage()
{
    delete ui;
}

void ScreenSettingsPage::apply()
{
    IDESettings s;
    s.openScreenType = ui->openGraphicsScreenComboBox->currentIndex() == 0 ? IDESettings::OpenScreenType::window : IDESettings::OpenScreenType::tab;
    s.saveSettings();
}
