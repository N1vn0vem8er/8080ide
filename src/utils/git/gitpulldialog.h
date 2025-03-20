#ifndef GITPULLDIALOG_H
#define GITPULLDIALOG_H

#include <QDialog>

namespace Ui {
class GitPullDialog;
}

class GitPullDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GitPullDialog(const QString& path, QWidget *parent = nullptr);
    ~GitPullDialog();

private:
    Ui::GitPullDialog *ui;
    QString repoPath;
    void pull();
};

#endif // GITPULLDIALOG_H
