#include "tabledatageneratordialog.h"
#include "qclipboard.h"
#include "ui_tabledatageneratordialog.h"

TableDataGeneratorDialog::TableDataGeneratorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TableDataGeneratorDialog)
{
    ui->setupUi(this);
    connect(ui->generateButton, &QPushButton::clicked, this, &TableDataGeneratorDialog::generate);
    connect(ui->clearButton, &QPushButton::clicked, this, [&](){ui->output->clear(); ui->input->clear();});
    connect(ui->copyButton, &QPushButton::clicked, this, &TableDataGeneratorDialog::copy);
}

TableDataGeneratorDialog::~TableDataGeneratorDialog()
{
    delete ui;
}

void TableDataGeneratorDialog::generate()
{
    QString text = ui->input->toPlainText();
    if(!text.isEmpty())
    {
        int i = 0;
        QString out;
        if(text.length() % 2 == 1)
        {
            i = 1;
            out+=QString("DB 0").append(text[0]).append('\n').toUpper();
        }
        for(; i<text.length() && i<text.length() + 1; i+=2)
        {
            out += QString("DB ").append(text[i]).append(text[i+1]).append('\n').toUpper();
        }
        ui->output->setPlainText(out);
    }
}

void TableDataGeneratorDialog::copy()
{
    if(!ui->output->toPlainText().isEmpty())
    {
        QClipboard* clipBoard = QApplication::clipboard();
        clipBoard->setText(ui->output->toPlainText());
    }
}

