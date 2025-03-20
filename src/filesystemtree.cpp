#include "filesystemtree.h"
#include "qdialog.h"
#include "qmenu.h"
#include "dialogs/textinputdialog.h"
#include <fstream>
#include <qprocess.h>
void FileSystemTree::init(QString path)
{
    model = new QFileSystemModel();
    model->setFilter(QDir::NoDotAndDotDot | QDir::AllDirs | QDir::Files);
    model->setRootPath(path);
    setModel(model);
    setRootIndex(model->index(path));
    hideColumn(1);
    hideColumn(2);
    hideColumn(3);
    hideColumn(4);
    contextMenu = new QMenu();
    QAction* createFileAction = new QAction(tr("New File"), contextMenu);
    connect(createFileAction, &QAction::triggered, this, &FileSystemTree::createFile);
    contextMenu->addAction(createFileAction);
    QAction* createDirAction = new QAction(tr("New Folder"), contextMenu);
    connect(createDirAction, &QAction::triggered, this, &FileSystemTree::createDir);
    contextMenu->addAction(createDirAction);
    QAction* gitAddAction = new QAction(tr("Git Add"), contextMenu);
    connect(gitAddAction, &QAction::triggered, this, &FileSystemTree::addToGitRepository);
    contextMenu->addAction(gitAddAction);
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QTreeView::customContextMenuRequested, this, &FileSystemTree::openContextMenu);
}
void FileSystemTree::setDirectory(QString path)
{
    if(model != NULL)
        setRootIndex(model->index(path));
}
QString FileSystemTree::getSelectedItem(QModelIndex index)
{
    return model->filePath(index);
}

FileSystemTree::~FileSystemTree()
{
    delete model;
    delete contextMenu;
}
void FileSystemTree::openContextMenu(QPoint point)
{
    contextMenu->popup(mapToGlobal(point));
}
void FileSystemTree::createFile()
{
    if(selectionModel()->selectedIndexes().count() > 0)
    {
        QString path = getSelectedItem(selectionModel()->selectedIndexes()[0]);
        if(QFileInfo(path).isDir())
        {
            TextInputDialog* dialog = new TextInputDialog();
            if(dialog->exec() == QDialog::Accepted)
            {
                QString name = dialog->getText();
                if(!name.isEmpty())
                {
                    std::ofstream file;
                    file.open(path.toStdString() + '/' + name.toStdString());
                    if(file.is_open())
                    {
                        file.close();
                    }
                }
            }
        }
    }
}
void FileSystemTree::createDir()
{
    if(selectionModel()->selectedIndexes().count() > 0)
    {
        QString path = getSelectedItem(selectionModel()->selectedIndexes()[0]);
        if(QFileInfo(path).isDir())
        {
            TextInputDialog* dialog = new TextInputDialog();
            if(dialog->exec() == QDialog::Accepted)
            {
                QString name = dialog->getText();
                if(!name.isEmpty())
                {
                    QDir().mkdir(path + '/' + name);
                }
            }
        }
    }
}
void FileSystemTree::addToGitRepository()
{
    if(selectionModel()->selectedIndexes().count() > 0)
    {
        QString path = getSelectedItem(selectionModel()->selectedIndexes()[0]);
        if(QFileInfo(path).isFile())
        {
            std::string oldDir = std::filesystem::current_path();
            auto tmp1 = QFileInfo(path).absolutePath().toStdString();
            std::filesystem::current_path(tmp1);
            std::string tmp = "git add " + path.toStdString();
            std::system(tmp.c_str());
            std::filesystem::current_path(oldDir);
        }
    }
}
