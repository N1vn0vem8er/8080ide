#ifndef COMMITDIALOG_H
#define COMMITDIALOG_H

#include <QDialog>
#include <unordered_set>

namespace Ui {
class CommitDialog;
}

class CommitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CommitDialog(QWidget *parent = nullptr);
    ~CommitDialog();
    void init(QString path);

private:
    QString repoPath;
    void addFileToList(QString name);
    Ui::CommitDialog *ui;
    std::unordered_set<QString> filesToCommit;
    std::vector<QString> allFiles;
    void startCommit(std::string path, QString message);
    void commit();
};

#endif // COMMITDIALOG_H
