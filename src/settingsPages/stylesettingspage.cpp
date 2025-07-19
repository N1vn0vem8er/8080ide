#include "stylesettingspage.h"
#include <QColorDialog>
#include "ui_stylesettingspage.h"

#include <QStyleFactory>
#include "idesettings.h"

StyleSettingsPage::StyleSettingsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StyleSettingsPage)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &StyleSettingsPage::apply);
    ui->comboBox->addItems(QStyleFactory::keys());
    ui->lineWrapCheckBox->setChecked(IDESettings::defaultLinesWrap);
    ui->fontLineEdit->setText(QString::number(IDESettings::defaultFontSize));
    ui->fontComboBox->setCurrentFont(QFont(IDESettings::defaultEditorFont));
    if(QStyleFactory::keys().contains(IDESettings::theme))
    {
        ui->comboBox->setCurrentText(IDESettings::theme);
    }
    connect(ui->selectLineHighlightColorButton, &QPushButton::clicked, this, [&]{
        QColorDialog dialog;
        dialog.setCurrentColor(IDESettings::lineHighlightColor);
        if(dialog.exec() == QDialog::Accepted)
        {
            IDESettings::lineHighlightColor = dialog.currentColor();
        }
    });
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
    IDESettings::defaultEditorFont = ui->fontComboBox->currentFont().family();
    IDESettings().saveSettings();
}
