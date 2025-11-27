#include "projectconfigurationwidget.h"
#include "ui_projectconfigurationwidget.h"
#include <QStandardItemModel>

ProjectConfigurationWidget::ProjectConfigurationWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProjectConfigurationWidget)
{
    ui->setupUi(this);
    connect(ui->addFileButton, &QPushButton::clicked, this, &ProjectConfigurationWidget::addFile);
    connect(ui->removeFileButton, &QPushButton::clicked, this, &ProjectConfigurationWidget::removeFile);
}

ProjectConfigurationWidget::~ProjectConfigurationWidget()
{
    delete ui;
}

QString ProjectConfigurationWidget::getName() const
{
    return ui->projectNameLineEdit->text();
}

int ProjectConfigurationWidget::getMemorySize() const
{
    return ui->memorySizeSpinBox->value();
}

int ProjectConfigurationWidget::getStartAt() const
{
    return ui->startAtSpinBox->value();
}

QList<QPair<QString, int> > ProjectConfigurationWidget::getFilesInMemory() const
{
    QList<QPair<QString, int>> filesInMemory;
    if(ui->tableView->model())
    {
        QStandardItemModel* model = static_cast<QStandardItemModel*>(ui->tableView->model());
        for(int i=0;i<model->rowCount(); i++)
        {
            if(!model->item(i, 0)->text().isEmpty())
                filesInMemory.append({model->item(i, 0)->text(), model->item(i, 1)->text().toInt()});
        }
    }
    return filesInMemory;
}

int ProjectConfigurationWidget::getStackPointer() const
{
    return ui->stackPointerSpinBox->value();
}

void ProjectConfigurationWidget::setName(const QString &name)
{
    ui->projectNameLineEdit->setText(name);
}

void ProjectConfigurationWidget::setMemorySize(int memorySize)
{
    ui->memorySizeSpinBox->setValue(memorySize);
    ui->stackPointerSpinBox->setMaximum(memorySize);
    ui->startAtSpinBox->setMaximum(memorySize - 1);
}

void ProjectConfigurationWidget::setStartAt(int startAt)
{
    ui->startAtSpinBox->setValue(startAt);
}

void ProjectConfigurationWidget::setFilesInMemory(const QList<QPair<QString, int> > files)
{
    if(ui->tableView->model())
        ui->tableView->model()->deleteLater();
    QStandardItemModel* model = new QStandardItemModel(ui->tableView);
    model->setHorizontalHeaderLabels({tr("File"), tr("Position in memory")});
    for(const auto& file : files)
    {
        model->appendRow({new QStandardItem(file.first), new QStandardItem(QString::number(file.second))});
    }
    ui->tableView->setModel(model);
}

void ProjectConfigurationWidget::setStackPointer(int stackPointer)
{
    ui->stackPointerSpinBox->setValue(stackPointer);
}

void ProjectConfigurationWidget::addFile()
{
    if(ui->tableView->model())
    {
        static_cast<QStandardItemModel*>(ui->tableView->model())->appendRow({new QStandardItem(""), new QStandardItem(QString::number(0))});
    }
}

void ProjectConfigurationWidget::removeFile()
{
    if(ui->tableView->model() && !ui->tableView->selectionModel()->selectedRows().empty())
    {
        for(const auto& i : ui->tableView->selectionModel()->selectedRows())
        {
            ui->tableView->model()->removeRow(i.row());
        }
    }
}
