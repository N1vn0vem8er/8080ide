#ifndef FILESYSTEMTREE_H
#define FILESYSTEMTREE_H

#include <QTreeView>
#include <QObject>
#include <QFileSystemModel>

class FileSystemTree : public QTreeView
{
private:
    QFileSystemModel* model;
    QMenu* contextMenu;
    void openContextMenu(QPoint point);
    void createFile();
    void createDir();
    void addToGitRepository();
public:
    explicit FileSystemTree(QWidget* parent = nullptr) : QTreeView(parent){};
    void init(QString path);
    void setDirectory(QString path);
    QString getSelectedItem(QModelIndex index);
    ~FileSystemTree();
};

#endif // FILESYSTEMTREE_H
