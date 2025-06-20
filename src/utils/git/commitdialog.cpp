#include "commitdialog.h"
#include "qdiriterator.h"
#include "qlabel.h"
#include "ui_commitdialog.h"

#include <QCheckBox>
#include <iostream>
#include <qprocess.h>
#include<thread>
#include<QStringListModel>

CommitDialog::CommitDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CommitDialog)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &CommitDialog::commit);

}

void CommitDialog::addFileToList(QString name)
{
    QLayout* layout = new QHBoxLayout();
    QLabel* fileNameLabel = new QLabel();
    QCheckBox* includeInCommit = new QCheckBox();
    includeInCommit->setCheckState(Qt::Unchecked);
    fileNameLabel->setText(name);
    layout->addWidget(includeInCommit);
    layout->addWidget(fileNameLabel);
}

void CommitDialog::init(QString path)
{
    repoPath = path;
    QDirIterator it(path, QDir::Files, QDirIterator::Subdirectories);
    QProcess* process = new QProcess();
    process->setWorkingDirectory(path);
    process->startCommand("git status --short");
    process->waitForStarted(3000);
    process->waitForFinished(3000);
    auto resoult = process->readAllStandardOutput();
    QStringList sl;
    QString tmp;
    for(const auto& i : std::as_const(resoult))
    {
        if(i=='\n')
        {
            sl << tmp;
            tmp.clear();
            continue;
        }
        tmp+=i;
    }
    auto model = new QStringListModel();
    model->setStringList(sl);
    ui->listView->setModel(model);
    ui->listView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    delete process;
}
void CommitDialog::commit()
{
    std::thread t1(&CommitDialog::startCommit, this, repoPath.toStdString(), ui->plainTextEdit->toPlainText());
    t1.detach();
}
void CommitDialog::startCommit(std::string path, QString message)
{
    QProcess* process = new QProcess();
    process->setWorkingDirectory(QString::fromStdString(path));
    process->startCommand("git commit -am \"" + message + "\"");
    process->waitForStarted(3000);
    process->waitForFinished(3000);
    std::cout<<process->readAllStandardOutput().toStdString();
    delete process;
}

CommitDialog::~CommitDialog()
{
    delete ui;
}
