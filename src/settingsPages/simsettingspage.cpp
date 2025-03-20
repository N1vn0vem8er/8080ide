#include "simsettingspage.h"
#include "idesettings.h"
#include "qvalidator.h"
#include "ssettings.h"
#include "ui_simsettingspage.h"

#include <qmessagebox.h>

SimSettingsPage::SimSettingsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SimSettingsPage)
{
    ui->setupUi(this);
    ui->startAddress->setValidator(new QIntValidator(0, 64000, this));
    ui->memorySize->setValidator(new QIntValidator(0, 64000, this));
    ui->memorySize->setText(QString::number(IDESettings::simMemorySize));
    ui->startAddress->setText(QString::number(IDESettings::simStartAddress));
    connect(ui->applyButton, &QPushButton::clicked, this, &SimSettingsPage::apply);
}

SimSettingsPage::~SimSettingsPage()
{
    delete ui;
}

void SimSettingsPage::apply()
{
    if(ui->memorySize->text().isEmpty() ||  ui->startAddress->text().isEmpty() || ui->memorySize->text().toInt() > 64000 || ui->startAddress->text().toInt() > 64000 || ui->startAddress->text().toInt() < 0)
    {
        QMessageBox::critical(this, tr("Error"), tr("Memory ammount and start address must be between 0 and 64000."));
        return;
    }
    Ssettings::memSize = ui->memorySize->text().toInt();
    Ssettings::memStart = ui->startAddress->text().toInt();
    IDESettings::simMemorySize = Ssettings::memSize;
    IDESettings::simStartAddress = Ssettings::memStart;
    IDESettings s;
    s.saveSettings();
}
