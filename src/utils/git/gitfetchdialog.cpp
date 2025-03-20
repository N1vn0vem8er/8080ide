#include "gitfetchdialog.h"
#include "qprocess.h"
#include "ui_gitfetchdialog.h"

GitFetchDialog::GitFetchDialog(const QString &path, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::GitFetchDialog)
{
    ui->setupUi(this);
    repoPath = path;
    connect(ui->pushButton, &QPushButton::clicked, this, &GitFetchDialog::fetch);
}

GitFetchDialog::~GitFetchDialog()
{
    delete ui;
}

void GitFetchDialog::fetch()
{
    QProcess* process = new QProcess();
    process->setWorkingDirectory(repoPath);
    QString command = "git fetch";
    process->startCommand(command);
    process->waitForStarted();
    process->waitForFinished();
    process->waitForReadyRead();
    ui->plainTextEdit->appendPlainText(process->readAll());
    delete process;
}
