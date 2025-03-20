#ifndef GITDIALOG_H
#define GITDIALOG_H

#include <QDialog>

namespace Ui {
class GitDialog;
}

class GitDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GitDialog(QWidget *parent = nullptr);
    void setupForLog(QString path);
    void setupForDiff(QString path, QString filePath);
    void setupForStatus(QString path);
    ~GitDialog();

private slots:
    void gitStartLog(const QString path);
signals:
    void gitLogReady(const QString& resoult);

private:
    Ui::GitDialog *ui;
};

#endif // GITDIALOG_H
