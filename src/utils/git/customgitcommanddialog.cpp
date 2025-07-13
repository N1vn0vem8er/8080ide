#include "customgitcommanddialog.h"
#include "qprocess.h"
#include "ui_customgitcommanddialog.h"

CustomGitCommandDialog::CustomGitCommandDialog(const QString &path, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::CustomGitCommandDialog)
{
    repoPath = path;
    ui->setupUi(this);
    connect(ui->runButton, &QPushButton::clicked, this, &CustomGitCommandDialog::runCommand);
}

CustomGitCommandDialog::~CustomGitCommandDialog()
{
    delete ui;
}

void CustomGitCommandDialog::runCommand() const
{
    QProcess process;
    process.setWorkingDirectory(repoPath);
    process.startCommand(ui->input->text());
    process.waitForStarted();
    process.waitForFinished();
    process.waitForReadyRead();
    ui->output->appendPlainText(process.readAllStandardOutput());
    ui->output->appendPlainText(process.readAllStandardError());
}
