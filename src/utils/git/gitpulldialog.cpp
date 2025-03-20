#include "gitpulldialog.h"
#include "qprocess.h"
#include "ui_gitpulldialog.h"

GitPullDialog::GitPullDialog(const QString &path, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GitPullDialog)
{
    ui->setupUi(this);
    repoPath = path;
    connect(ui->pushButton, &QPushButton::clicked, this, &GitPullDialog::pull);
}

GitPullDialog::~GitPullDialog()
{
    delete ui;
}

void GitPullDialog::pull()
{
    QProcess* process = new QProcess();
    process->setWorkingDirectory(repoPath);
    QString command = "git pull";
    process->startCommand(command);
    process->waitForStarted();
    process->waitForFinished();
    process->waitForReadyRead();
    ui->plainTextEdit->appendPlainText(process->readAll());
    delete process;
}
