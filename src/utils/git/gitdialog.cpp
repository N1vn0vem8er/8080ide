#include "gitdialog.h"
#include "qcombobox.h"
#include "qplaintextedit.h"
#include "qprocess.h"
#include "qpushbutton.h"
#include "ui_gitdialog.h"
#include<thread>

GitDialog::GitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GitDialog)
{
    ui->setupUi(this);
}
void GitDialog::setupForLog(QString path)
{
    QLayout* layout = new QHBoxLayout();
    QPlainTextEdit* txtEdit = new QPlainTextEdit();
    txtEdit->setReadOnly(true);
    QProcess* process = new QProcess();
    process->setWorkingDirectory(path);
    process->startCommand("git log");
    process->waitForStarted(3000);
    process->waitForFinished(3000);
    process->waitForReadyRead(3000);
    txtEdit->setPlainText(process->readAllStandardError());
    txtEdit->appendPlainText(process->readAllStandardOutput());
    layout->addWidget(txtEdit);
    ui->mainWidget->setLayout(layout);
    delete process;
}
void GitDialog::setupForDiff(QString path, QString filePath)
{
    QLayout* layout = new QHBoxLayout();
    QPlainTextEdit* txtEdit = new QPlainTextEdit();
    txtEdit->setReadOnly(true);
    QProcess* process = new QProcess();
    process->setWorkingDirectory(path);
    QString command = "git diff " + filePath;
    process->startCommand(command);
    process->waitForStarted();
    process->waitForFinished();
    process->waitForReadyRead(3000);
    txtEdit->setPlainText(process->readAllStandardError());
    txtEdit->appendPlainText(process->readAllStandardOutput());
    layout->addWidget(txtEdit);
    ui->mainWidget->setLayout(layout);
    delete process;
}

void GitDialog::setupForStatus(QString path)
{
    QLayout* layout = new QHBoxLayout();
    QPlainTextEdit* txtEdit = new QPlainTextEdit();
    txtEdit->setReadOnly(true);
    QProcess* process = new QProcess();
    process->setWorkingDirectory(path);
    process->startCommand("git status");
    process->waitForStarted(3000);
    process->waitForFinished(3000);
    process->waitForReadyRead(3000);
    txtEdit->setPlainText(process->readAllStandardOutput());
    layout->addWidget(txtEdit);
    ui->mainWidget->setLayout(layout);
    delete process;
}


GitDialog::~GitDialog()
{
    delete ui;
}

void GitDialog::gitStartLog(const QString path)
{

}
