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
    ui->lineWrapCheckBox->setChecked(IDESettings::defaultLinesWrap);
    ui->fontLineEdit->setText(QString::number(IDESettings::defaultFontSize));
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
    IDESettings::theme = ui->comboBox->currentText();
    IDESettings::defaultFontSize = ui->fontLineEdit->text().toInt();
    IDESettings::defaultLinesWrap = ui->lineWrapCheckBox->isChecked();
    IDESettings().saveSettings();
}
