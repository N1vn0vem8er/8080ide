#include "instinmemorydialog.h"
#include "ui_instinmemorydialog.h"
#include <sstream>

InstInMemoryDialog::InstInMemoryDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::InstInMemoryDialog)
{
    ui->setupUi(this);
    connect(ui->countButton, &QPushButton::clicked, this, &InstInMemoryDialog::count);
}

void InstInMemoryDialog::setText(QString text)
{
    this->text = text;
}

InstInMemoryDialog::~InstInMemoryDialog()
{
    delete ui;
}

void InstInMemoryDialog::count()
{
    QTextStream stream(&text);
    int lineNumber = 1;
    int address = 0;
    while(!stream.atEnd() && lineNumber < ui->input->text().toInt())
    {
        QString line = stream.readLine();
        if(line.contains("STRING"))
        {
            bool startCount = false;
            for(const QChar& i : std::as_const(line))
            {
                if(i == '\"')
                {
                    if(startCount)
                    {
                        break;
                    }
                    startCount = true;
                    continue;
                }
                if(startCount)
                    address++;
            }
            goto end;
        }
        for(const QString& i : std::as_const(oneByteInsts))
        {
            if(line.contains(i))
            {
                address++;
                goto end;
            }
        }
        for(const QString& i : std::as_const(twoByteInsts))
        {
            if(line.contains(i))
            {
                address+=2;
                goto end;
            }
        }
        for(const QString& i : std::as_const(threeByteInsts))
        {
            if(line.contains(i))
            {
                address+=3;
                goto end;
            }
        }
        end:
        lineNumber++;
    }
        std::stringstream ss;
        ss << std::hex << address + ui->offset->text().toInt();
        ui->output->setText(QString::fromStdString(ss.str()));
}


