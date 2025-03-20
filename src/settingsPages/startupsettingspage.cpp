#include "startupsettingspage.h"
#include "ui_startupsettingspage.h"
#include "idesettings.h"

StartupSettingsPage::StartupSettingsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartupSettingsPage)
{
    ui->setupUi(this);
    connect(ui->startPageComboBox, &QComboBox::currentIndexChanged, this, [=](int index){IDESettings::startupWidgetsVisibitity.startPage = index == 0 ? IDESettings::hide : IDESettings::show;});
    connect(ui->simulatorComboBox, &QComboBox::currentIndexChanged, this, [=](int index){IDESettings::startupWidgetsVisibitity.simulator = index == 0 ? IDESettings::hide : IDESettings::show;});
    connect(ui->diagnosticsComboBox, &QComboBox::currentIndexChanged, this, [=](int index){IDESettings::startupWidgetsVisibitity.diagnostics = index == 0 ? IDESettings::hide : IDESettings::show;});
    connect(ui->converterComboBox, &QComboBox::currentIndexChanged, this, [=](int index){IDESettings::startupWidgetsVisibitity.converter = index == 0 ? IDESettings::hide : IDESettings::show;});
    connect(ui->fileTreeComboBox, &QComboBox::currentIndexChanged, this, [=](int index){IDESettings::startupWidgetsVisibitity.fileTree = index == 0 ? IDESettings::hide : IDESettings::show;});
    connect(ui->applyButton, &QPushButton::clicked, this, &StartupSettingsPage::apply);

    ui->startPageComboBox->setCurrentIndex(IDESettings::startupWidgetsVisibitity.startPage ? IDESettings::show : IDESettings::hide);
    ui->simulatorComboBox->setCurrentIndex(IDESettings::startupWidgetsVisibitity.simulator ? IDESettings::show : IDESettings::hide);
    ui->diagnosticsComboBox->setCurrentIndex(IDESettings::startupWidgetsVisibitity.diagnostics ? IDESettings::show : IDESettings::hide);
    ui->converterComboBox->setCurrentIndex(IDESettings::startupWidgetsVisibitity.converter ? IDESettings::show : IDESettings::hide);
    ui->fileTreeComboBox->setCurrentIndex(IDESettings::startupWidgetsVisibitity.fileTree ? IDESettings::show : IDESettings::hide);
}

StartupSettingsPage::~StartupSettingsPage()
{
    delete ui;
}

void StartupSettingsPage::apply()
{
    IDESettings s;
    s.saveSettings();
}
