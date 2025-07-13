#include "stylesettingspage.h"
#include "ui_stylesettingspage.h"

#include <QStyleFactory>
#include <idesettings.h>

StyleSettingsPage::StyleSettingsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StyleSettingsPage)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &StyleSettingsPage::apply);
    ui->comboBox->addItems(QStyleFactory::keys());
    if(QStyleFactory::keys().contains(IDESettings::theme))
    {
        ui->comboBox->setCurrentText(IDESettings::theme);
    }
}

StyleSettingsPage::~StyleSettingsPage()
{
    delete ui;
}

void StyleSettingsPage::apply() const
{
    QApplication::setStyle(ui->comboBox->currentText());
    IDESettings s;
    s.saveSettings();
}
