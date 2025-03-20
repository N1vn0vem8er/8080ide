#include "numberconverterwidget.h"
#include "ui_numberconverterwidget.h"
#include <bitset>
#include <sstream>

NumberConverterWidget::NumberConverterWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::NumberConverterWidget)
{
    ui->setupUi(this);
    connect(ui->input, &QLineEdit::textChanged, this, &NumberConverterWidget::input);
    connect(ui->inComboBox, &QComboBox::currentIndexChanged, this, &NumberConverterWidget::input);
    connect(ui->outComboBox, &QComboBox::currentIndexChanged, this, &NumberConverterWidget::input);
    connect(ui->inComboBox, &QComboBox::currentIndexChanged, this, &NumberConverterWidget::changeMaxInLength);
}

NumberConverterWidget::~NumberConverterWidget()
{
    delete ui;
}
void NumberConverterWidget::input()
{
    if(ui->input->text().isEmpty())
    {
        ui->output->clear();
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
            ss << std::hex << ui->input->text().toInt();
            ui->output->setText(QString::fromStdString(ss.str()));
        }
        break;
        case DEC_OUT:
        {
            ui->output->setText(ui->input->text());
        }
        break;
        case BIN_OUT:
            ui->output->setText(QString::fromStdString(std::bitset<32>(ui->input->text().toInt()).to_string()));
            break;
        }
        break;
    case HEX_IN:
        switch(ui->outComboBox->currentIndex())
        {
        case HEX_OUT:
        {
            ui->output->setText(ui->input->text());
        }
        break;
        case DEC_OUT:
        {
            std::stringstream ss;
            ss << ui->input->text().toStdString();
            int dec;
            ss >> std::hex >> dec;
            ui->output->setText(QString::number(dec));
        }
        break;
        case BIN_OUT:
        {
            std::stringstream ss;
            ss << ui->input->text().toStdString();
            int dec;
            ss >> std::hex >> dec;
            ui->output->setText(QString::fromStdString(std::bitset<32>(dec).to_string()));
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
            ss << std::hex << std::stoi(ui->input->text().toStdString(), nullptr, 2);
            ui->output->setText(QString::fromStdString(ss.str()));
        }
        break;
        case DEC_OUT:
        {
            ui->output->setText(QString::number(std::bitset<64>(ui->input->text().toStdString()).to_ulong()));
        }
        break;
        case BIN_OUT:
            ui->output->setText(ui->input->text());
            break;
        }
        break;
    }
}

void NumberConverterWidget::changeMaxInLength()
{
    ui->input->clear();
    switch(ui->inComboBox->currentIndex())
    {
    case DEC_IN:
        ui->input->setMaxLength(9);
        break;
    case HEX_IN:
        ui->input->setMaxLength(7);
        break;
    case BIN_IN:
        ui->input->setMaxLength(64);
        break;
    }
}
