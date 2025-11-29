#include "starttabwidget.h"
#include "qscrollbar.h"
#include "qstringlistmodel.h"
#include "ui_starttabwidget.h"
#include <fstream>

#include <QDir>
#include <QMessageBox>
#include "idesettings.h"

StartTabWidget::StartTabWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StartTabWidget)
{
    ui->setupUi(this);
    connect(ui->newProjectLabel, &QLabel::linkActivated, this, &StartTabWidget::linkClicked);
    connect(ui->openProjectLabel, &QLabel::linkActivated, this, &StartTabWidget::linkClicked);
    connect(ui->newFileLabel, &QLabel::linkActivated, this, &StartTabWidget::linkClicked);
    connect(ui->openFileLabel, &QLabel::linkActivated, this, &StartTabWidget::linkClicked);
    connect(ui->recentFiles, &QAbstractItemView::doubleClicked, this, &StartTabWidget::openFileFromRecent);
    connect(ui->recentProjects, &QAbstractItemView::doubleClicked, this, &StartTabWidget::openProjectFromRecent);
    connect(ui->clearRecentFilesButton, &QPushButton::clicked, this, &StartTabWidget::clearRecentFiles);
    connect(ui->clearRecentProjectsButton, &QPushButton::clicked, this, &StartTabWidget::clearRecentProjects);
    connect(ui->refreshFilesButton, &QPushButton::clicked, this, &StartTabWidget::loadRecentFilesList);
    connect(ui->refreshProjectsButton, &QPushButton::clicked, this, &StartTabWidget::loadRecentProjectsList);
    refresh();
}

StartTabWidget::~StartTabWidget()
{
    delete ui;
}

void StartTabWidget::refresh()
{
    loadRecentFilesList();
    loadRecentProjectsList();
}

void StartTabWidget::linkClicked(const QString &link)
{
    emit linkActivated(link);
}

void StartTabWidget::loadRecentFilesList()
{
    QStringListModel* model = new QStringListModel(ui->recentFiles);
    model->setStringList(IDESettings::recentFiles);
    ui->recentFiles->setModel(model);
    ui->recentFiles->horizontalScrollBar()->setValue(ui->recentFiles->horizontalScrollBar()->maximum());
}

void StartTabWidget::loadRecentProjectsList()
{
    const QString path = IDESettings::dataPath + "/.ide8080ide.recentprojects";
    QStringList projectsLocations;
    std::fstream file(path.toStdString());
    if(file.is_open())
    {
        while(!file.eof())
        {
            std::string line;
            getline(file, line);
            projectsLocations.append(QString::fromStdString(line));
        }
        file.close();
    }
    QStringListModel* model = new QStringListModel(ui->recentProjects);
    model->setStringList(projectsLocations);
    ui->recentProjects->setModel(model);
    ui->recentProjects->horizontalScrollBar()->setValue(ui->recentFiles->horizontalScrollBar()->maximum());
}

void StartTabWidget::openFileFromRecent()
{
    QModelIndex index = ui->recentFiles->currentIndex();
    QString path = index.data().toString();
    if(path != "")
    {
        emit openFileFromPath(path);
    }
}

void StartTabWidget::openProjectFromRecent()
{
    QModelIndex index = ui->recentProjects->currentIndex();
    QString path = index.data().toString();
    if(path!="")
    {
        emit openProjectFromPath(path);
    }
}

void StartTabWidget::clearRecentFiles()
{
    auto reply = QMessageBox::question(this, tr("Clear recent"), tr("Are you sure you want to clear recent files?"));
    if(reply == QMessageBox::Yes)
    {
        IDESettings::recentFiles.clear();
        QStringListModel* model = new QStringListModel(ui->recentFiles);
        model->setStringList(IDESettings::recentFiles);
        ui->recentFiles->setModel(model);
        emit clearedRecentFiles();
    }
}

void StartTabWidget::clearRecentProjects()
{
    auto reply = QMessageBox::question(this, tr("Clear recent"), tr("Are you sure you want to clear recent projects?"));
    if(reply == QMessageBox::Yes)
    {
        const QString path = IDESettings::dataPath + "/.ide8080ide.recentprojects";
        QStringList projectsLocations;
        std::fstream file(path.toStdString(), std::ios_base::out);
        if(file.is_open())
        {
            file << "";
            file.close();
        }
        QStringListModel* model = new QStringListModel(ui->recentProjects);
        model->setStringList(projectsLocations);
        ui->recentProjects->setModel(model);
    }
}
