#include "projectconfigurationwidget.h"
#include "ui_projectconfigurationwidget.h"
#include <QStandardItemModel>

ProjectConfigurationWidget::ProjectConfigurationWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProjectConfigurationWidget)
{
    ui->setupUi(this);
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

}

void ProjectConfigurationWidget::setName(const QString &name)
{
    ui->projectNameLineEdit->setText(name);
}

void ProjectConfigurationWidget::setMemorySize(int memorySize)
{
    ui->memorySizeSpinBox->setValue(memorySize);
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
