#include "terminalsettingspage.h"
#include "idesettings.h"
#include "ui_terminalsettingspage.h"
#include <qtermwidget6/qtermwidget.h>

TerminalSettingsPage::TerminalSettingsPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TerminalSettingsPage)
{
    ui->setupUi(this);
    ui->fontLineEdit->setText(QString::number(IDESettings::defaultTerminalFontSize));
    ui->themeComboBox->addItems(QTermWidget::availableColorSchemes());
    ui->themeComboBox->setCurrentText(IDESettings::terminalTheme);
    ui->fontComboBox->setCurrentFont(QFont(IDESettings::defaultTerminalFont));
    connect(ui->themeComboBox, &QComboBox::currentTextChanged, this, [&](const QString& text){IDESettings::terminalTheme = text;});
    connect(ui->applyButton, &QPushButton::clicked, this, [&]{
        IDESettings::defaultTerminalFontSize = ui->fontLineEdit->text().toInt();
        IDESettings::defaultTerminalFont = ui->fontComboBox->currentFont().family();
        IDESettings().saveSettings();
    });
}

TerminalSettingsPage::~TerminalSettingsPage()
{
    delete ui;
}
