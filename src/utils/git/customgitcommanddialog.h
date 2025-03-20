#ifndef CUSTOMGITCOMMANDDIALOG_H
#define CUSTOMGITCOMMANDDIALOG_H

#include <QDialog>

namespace Ui {
class CustomGitCommandDialog;
}

class CustomGitCommandDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CustomGitCommandDialog(const QString& path, QWidget *parent = nullptr);
    ~CustomGitCommandDialog();

private:
    Ui::CustomGitCommandDialog *ui;
    void runCommand();
    QString repoPath;
};

#endif // CUSTOMGITCOMMANDDIALOG_H
