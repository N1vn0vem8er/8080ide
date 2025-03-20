#include "stringtablegeneratordialog.h"
#include "ui_stringtablegeneratordialog.h"
#include <QClipboard>
#include <sstream>

StringTableGeneratorDialog::StringTableGeneratorDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::StringTableGeneratorDialog)
{
    ui->setupUi(this);
    connect(ui->generateButton, &QPushButton::clicked, this, &StringTableGeneratorDialog::generate);
    connect(ui->clearButton, &QPushButton::clicked, this, [=](){ui->output->clear(); ui->input->clear();});
    connect(ui->copyButton, &QPushButton::clicked, this, &StringTableGeneratorDialog::copy);
}

StringTableGeneratorDialog::~StringTableGeneratorDialog()
{
    delete ui;
}

void StringTableGeneratorDialog::generate()
{
    QString text = ui->input->toPlainText();
    if(!text.isEmpty())
    {
        QString out;
        for(auto i : text)
        {
            out += QString("DB ").append(toHex(i)).append('\n');
        }
        ui->output->setPlainText(out);
    }
}

void StringTableGeneratorDialog::copy()
{
    if(!ui->output->toPlainText().isEmpty())
    {
        QClipboard* clipBoard = QApplication::clipboard();
        clipBoard->setText(ui->output->toPlainText());
    }
}

QString StringTableGeneratorDialog::toHex(QChar ch)
{
    std::stringstream ss;
    ss << std::hex << +ch.toLatin1();
    return QString::fromStdString(ss.str()).toUpper();
}
