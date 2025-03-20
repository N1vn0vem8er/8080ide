#include "gitpushdialog.h"
#include "qprocess.h"
#include "ui_gitpushdialog.h"

GitPushDialog::GitPushDialog(const QString &path, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GitPushDialog)
{
    ui->setupUi(this);
    repoPath = path;
    connect(ui->pushButton, &QPushButton::clicked, this, &GitPushDialog::push);
}

GitPushDialog::~GitPushDialog()
{
    delete ui;
}

void GitPushDialog::push()
{
    QProcess* process = new QProcess();
    process->setWorkingDirectory(repoPath);
    QString command = "git push";
    process->startCommand(command);
    process->waitForStarted();
    process->waitForFinished();
    process->waitForReadyRead();
    ui->plainTextEdit->appendPlainText(process->readAllStandardOutput());
    ui->plainTextEdit->appendPlainText(process->readAllStandardError());
    delete process;
}
