#ifndef GITFETCHDIALOG_H
#define GITFETCHDIALOG_H

#include <QDialog>

namespace Ui {
class GitFetchDialog;
}

class GitFetchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GitFetchDialog(const QString& path, QWidget *parent = nullptr);
    ~GitFetchDialog();

private:
    Ui::GitFetchDialog *ui;
    QString repoPath;
    void fetch();
};

#endif // GITFETCHDIALOG_H
