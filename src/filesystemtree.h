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
    void openContextMenu(const QPoint &point);
    void createFile();
    void createDir();
    void addToGitRepository();
public:
    explicit FileSystemTree(QWidget* parent = nullptr) : QTreeView(parent){};
    void init(const QString &path);
    void setDirectory(const QString &path);
    QString getSelectedItem(const QModelIndex &index);
    ~FileSystemTree();
};

#endif // FILESYSTEMTREE_H
