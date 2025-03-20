#ifndef SAVEWARNINGDIALOG_H
#define SAVEWARNINGDIALOG_H

#include <QDialog>

namespace Ui {
class SaveWarningDialog;
}

class SaveWarningDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SaveWarningDialog(QWidget *parent = nullptr);
    void setFilePath(const QString& path);
    ~SaveWarningDialog();

private:
    Ui::SaveWarningDialog *ui;
};

#endif // SAVEWARNINGDIALOG_H
