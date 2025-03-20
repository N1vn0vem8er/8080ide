#ifndef CREATEPROJECTWINDOW_H
#define CREATEPROJECTWINDOW_H

#include <QDialog>

namespace Ui {
class CreateProjectWindow;
}

class CreateProjectWindow : public QDialog
{
    Q_OBJECT

public:
    explicit CreateProjectWindow(QWidget *parent = nullptr);
    QString getProjectConfigPath();
    ~CreateProjectWindow();

private:
    Ui::CreateProjectWindow *ui;
    void createProject();
    void openSelectFolder();
    void checkDir();
    void checkName();
    void createGitRepo(const QString& path);
};

#endif // CREATEPROJECTWINDOW_H
