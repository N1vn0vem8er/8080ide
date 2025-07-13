#include "numberconverterdialog.h"
#include "ui_numberconverterdialog.h"
#include <bitset>
#include <sstream>

NumberConverterDialog::NumberConverterDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NumberConverterDialog)
{
    ui->setupUi(this);
    ui->inLine->setMaxLength(9);
    connect(ui->inLine, &QLineEdit::textChanged, this, &NumberConverterDialog::input);
    connect(ui->inComboBox, &QComboBox::currentIndexChanged, this, &NumberConverterDialog::input);
    connect(ui->outComboBox, &QComboBox::currentIndexChanged, this, &NumberConverterDialog::input);
    connect(ui->inComboBox, &QComboBox::currentIndexChanged, this, &NumberConverterDialog::changeMaxInLength);
}

NumberConverterDialog::~NumberConverterDialog()
{
    delete ui;
}

void NumberConverterDialog::input() const
{
    if(ui->inLine->text().isEmpty())
    {
        ui->outLine->clear();
        return;
    }
    switch(ui->inComboBox->currentIndex())
    {
    case DEC_IN:
        switch(ui->outComboBox->currentIndex())
        {
        case HEX_OUT:
        {
            std::stringstream ss;
            ss << std::hex << ui->inLine->text().toInt();
            ui->outLine->setText(QString::fromStdString(ss.str()));
        }
            break;
        case DEC_OUT:
        {
            ui->outLine->setText(ui->inLine->text());
        }
            break;
        case BIN_OUT:
            ui->outLine->setText(QString::fromStdString(std::bitset<32>(ui->inLine->text().toInt()).to_string()));
            break;
        }
        break;
    case HEX_IN:
        switch(ui->outComboBox->currentIndex())
        {
        case HEX_OUT:
        {
            ui->outLine->setText(ui->inLine->text());
        }
        break;
        case DEC_OUT:
        {
            std::stringstream ss;
            ss << ui->inLine->text().toStdString();
            int dec;
            ss >> std::hex >> dec;
            ui->outLine->setText(QString::number(dec));
        }
        break;
        case BIN_OUT:
        {
            std::stringstream ss;
            ss << ui->inLine->text().toStdString();
            int dec;
            ss >> std::hex >> dec;
            ui->outLine->setText(QString::fromStdString(std::bitset<32>(dec).to_string()));
        }
            break;
        }
        break;
    case BIN_IN:
        switch(ui->outComboBox->currentIndex())
        {
        case HEX_OUT:
        {
            std::stringstream ss;
            ss << std::hex << std::stoi(ui->inLine->text().toStdString(), nullptr, 2);
            ui->outLine->setText(QString::fromStdString(ss.str()));
        }
        break;
        case DEC_OUT:
        {
            ui->outLine->setText(QString::number(std::bitset<64>(ui->inLine->text().toStdString()).to_ulong()));
        }
        break;
        case BIN_OUT:
            ui->outLine->setText(ui->inLine->text());
            break;
        }
        break;
    }
}

void NumberConverterDialog::changeMaxInLength() const
{
    ui->inLine->clear();
    switch(ui->inComboBox->currentIndex())
    {
    case DEC_IN:
        ui->inLine->setMaxLength(9);
        break;
    case HEX_IN:
        ui->inLine->setMaxLength(7);
        break;
    case BIN_IN:
        ui->inLine->setMaxLength(64);
        break;
    }
}
