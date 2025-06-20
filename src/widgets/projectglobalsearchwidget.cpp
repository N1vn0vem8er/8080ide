#include "projectglobalsearchwidget.h"
#include "qdir.h"
#include "qdiriterator.h"
#include "qstringlistmodel.h"
#include "ui_projectglobalsearchwidget.h"

ProjectGlobalSearchWidget::ProjectGlobalSearchWidget(QString projectPath, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ProjectGlobalSearchWidget)
{
    ui->setupUi(this);
    this->projectPath = projectPath;
    connect(ui->searchButton, &QPushButton::clicked, this, &ProjectGlobalSearchWidget::search);
    connect(ui->replaceAllButton, &QPushButton::clicked, this, &ProjectGlobalSearchWidget::replaceAll);
    connect(ui->replaceSelectedButton, &QPushButton::clicked, this, &ProjectGlobalSearchWidget::replaceSelected);
}

ProjectGlobalSearchWidget::~ProjectGlobalSearchWidget()
{
    delete ui;
}

void ProjectGlobalSearchWidget::search()
{
    pathsLocations.clear();
    found.clear();
    QDirIterator it(projectPath, QStringList() << "*.asm", QDir::Files, QDirIterator::Subdirectories);
    while(it.hasNext())
    {
        QString text = ui->searchLine->text();
        QString path = it.next();
        QVector<int> indexes = findInFile(path, text);
        if(!indexes.isEmpty())
        {
            found.insert(path, indexes);
        }
    }
    QStringList foundList;
    for(auto i : found.asKeyValueRange())
    {
        for(const auto& j : std::as_const(i.second))
        {
            QString text = i.first + tr(" on position: ") + QString::number(j);
            foundList.append(text);
            pathsLocations.append(qMakePair(i.first, j));
        }
    }
    QStringListModel* model = new QStringListModel(foundList);
    ui->resoultList->setModel(model);
}

void ProjectGlobalSearchWidget::replaceSelected()
{
    QModelIndexList selected = ui->resoultList->selectionModel()->selectedIndexes();
    if(!selected.isEmpty())
    {
        for(const QModelIndex& i : std::as_const(selected))
        {
            QFile file(pathsLocations[i.row()].first);
            file.open(QIODevice::ReadWrite);
            if(file.isOpen())
            {
                QString content = file.readAll();
                content.replace(pathsLocations[i.row()].second, ui->searchLine->text().length(), ui->replaceLine->text());
                file.seek(0);
                file.write(content.toUtf8());
                file.close();
            }
        }
    }
}

void ProjectGlobalSearchWidget::replaceAll()
{
    search();
    for(auto i : found.asKeyValueRange())
    {
        QFile file(i.first);
        file.open(QIODevice::ReadWrite);
        if(file.isOpen())
        {
            QString content = file.readAll();
            content.replace(ui->searchLine->text(), ui->replaceLine->text());
            file.seek(0);
            file.write(content.toUtf8());
            file.close();
        }
    }
}

QVector<int> ProjectGlobalSearchWidget::findInFile(const QString &path, const QString &text)
{
    QVector<int> found;
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    if(file.isOpen())
    {
        QString content = file.readAll();
        int index = content.indexOf(text);
        while (index != -1)
        {
            found.push_back(index);
            index = content.indexOf(text, index + text.length());
        }
        file.close();
    }
    return found;
}
