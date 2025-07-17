#include "settings.h"
#include "qstringlistmodel.h"
#include "ui_settings.h"
#include <QStyleFactory>

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::settings)
{
    ui->setupUi(this);
    QStringList items;
    items << tr("Appearance") << tr("Simulator") << tr("Help settings") << tr("Syntax Highlighting") << tr("After startup") << tr("Terminal");
    QStringListModel* model = new QStringListModel(ui->settingsSelector);
    model->setStringList(items);
    ui->settingsSelector->setModel(model);
    connect(ui->settingsSelector, &QListView::clicked, this, &Settings::changePage);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::changePage(const QModelIndex &index) const
{
    ui->stackedWidget->setCurrentIndex(index.row());
}
