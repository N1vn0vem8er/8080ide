#ifndef GITBRANCHDIALOG_H
#define GITBRANCHDIALOG_H

#include <QDialog>

namespace Ui {
class GitBranchDialog;
}

class GitBranchDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GitBranchDialog(QString path, QStringList branches, QWidget *parent = nullptr);
    ~GitBranchDialog();

private:
    Ui::GitBranchDialog *ui;
    QString repoPath;
signals:
    void setBranch(QString name);
};

#endif // GITBRANCHDIALOG_H
