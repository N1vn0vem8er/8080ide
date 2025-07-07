#ifndef FILESYSTEMTREE_H
#define FILESYSTEMTREE_H

#include <QTreeView>
#include <QObject>
#include <QFileSystemModel>
#include <QList>

class FileSystemTree : public QTreeView
{
    Q_OBJECT
public:
    FileSystemTree(QWidget* parent = nullptr);
    ~FileSystemTree();
    struct MimeApplication{
        QString name;
        QString icon;
        QString exec;
        QList<QString> mimeTypes;
    };
    void open(const QString &path);
    void setDirectory(const QString &path);
    QString getSelectedItem(const QModelIndex &index);
    bool getHasGitRepository() const;
    void setHasGitRepository(bool newHasGitRepository);

private:
    QFileSystemModel* model {nullptr};
    QMenu* contextMenu {nullptr};
    bool hasGitRepository {false};
    void openOnFileContextMenu(const QString &path);
    void openOnDirContextMenu(const QString &path);
    void openAnywhereContextMenu();
    QList<MimeApplication> apps;
    QThread* mimeFinderThread {nullptr};
    void startSearch();

private slots:
    void openContextMenu(const QPoint &point);
    void createFile();
    void createDir();
    void createDirInRoot();
    void createFileInRoot();
    void addToGitRepository();
    void openIn(const QString& exec, const QString& path);
    void openFilePressed();
    void openDirPressed();
    void renamePressed();
    void mimeSearchResultsReady(QList<FileSystemTree::MimeApplication> resoults);

signals:
    void openFile(const QString& path);
    void startMimeSearch();
};

#endif // FILESYSTEMTREE_H
