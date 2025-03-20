#include "memorywindow.h"
#include "ui_memorywindow.h"

#include <QStandardItemModel>
#include<sstream>

MemoryWindow::MemoryWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemoryWindow)
{
    ui->setupUi(this);
    connect(this, &QDialog::accepted, this, &MemoryWindow::userMemoryUpdate);
}

MemoryWindow::~MemoryWindow()
{
    delete model;
    delete ui;
}

void MemoryWindow::updateMemory(QString memory, const int &size)
{
    if(model != nullptr)
    {
        delete model;
    }
    this->size = size;
    this->memory = memory;
    model = new QStandardItemModel(ui->tableView);
    model->setHorizontalHeaderItem(0, new QStandardItem("0x0"));
    model->setHorizontalHeaderItem(1, new QStandardItem("0x1"));
    model->setHorizontalHeaderItem(2, new QStandardItem("0x2"));
    model->setHorizontalHeaderItem(3, new QStandardItem("0x3"));
    model->setHorizontalHeaderItem(4, new QStandardItem("0x4"));
    model->setHorizontalHeaderItem(5, new QStandardItem("0x5"));
    model->setHorizontalHeaderItem(6, new QStandardItem("0x6"));
    model->setHorizontalHeaderItem(7, new QStandardItem("0x7"));
    model->setHorizontalHeaderItem(8, new QStandardItem("0x8"));
    model->setHorizontalHeaderItem(9, new QStandardItem("0x9"));
    model->setHorizontalHeaderItem(10, new QStandardItem("0xa"));
    model->setHorizontalHeaderItem(11, new QStandardItem("0xb"));
    model->setHorizontalHeaderItem(12, new QStandardItem("0xc"));
    model->setHorizontalHeaderItem(13, new QStandardItem("0xd"));
    model->setHorizontalHeaderItem(14, new QStandardItem("0xe"));
    model->setHorizontalHeaderItem(15, new QStandardItem("0xf"));
    int rowIndex = 0;
    for(int i=0;i<this->size;i+=16)
    {
        QList<QStandardItem*> list;
        for(int j=0;j<16 && j+i<size && j+i+1<size;j+=1)
        {
            std::stringstream ss;
            ss << std::hex << +this->memory[i+j].cell();
            list.append(new QStandardItem(QString::fromStdString(ss.str())));
        }
        model->insertRow(rowIndex, list);
        std::stringstream ss;
        ss << "0x" << std::hex << i;
        model->setVerticalHeaderItem(rowIndex, new QStandardItem(QString::fromStdString(ss.str())));
        rowIndex++;
    }
    delete ui->tableView->model();
    ui->tableView->setModel(model);
}

void MemoryWindow::userMemoryUpdate()
{
    int index = 0;
    for(int r = 0; r < model->rowCount(); r++)
    {
        for(int c = 0; c < model->columnCount(); c++)
        {
            assert(index < size);
            unsigned char m = strtol(model->index(r, c).data().toString().toStdString().c_str(), nullptr, 16);
            memory[index] = QChar(m);
            index++;
        }
    }
    emit changedMemory(memory, size);
}
