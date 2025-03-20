#include "createprojectwindow.h"
#include "ui_createprojectwindow.h"
#include <fstream>

#include <QFileDialog>
#include <QProcess>
#include <QThread>
#include <iostream>

CreateProjectWindow::CreateProjectWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateProjectWindow)
{
    ui->setupUi(this);
    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &CreateProjectWindow::createProject);
    connect(ui->selectDirButton, &QPushButton::released, this, &CreateProjectWindow::openSelectFolder);
    connect(ui->locationPath, &QLineEdit::textChanged, this, &CreateProjectWindow::checkDir);
    connect(ui->projectName, &QLineEdit::textChanged, this, &CreateProjectWindow::checkName);
    ui->checkPathLabel->setVisible(false);
    ui->badNameLabel->setVisible(true);
    ui->checkPathLabel->setStyleSheet("QLabel {color: red;}");
    ui->badNameLabel->setStyleSheet("QLabel {color: red;}");
}

QString CreateProjectWindow::getProjectConfigPath()
{
    return ui->locationPath->text() + '/' + ui->projectName->text() + '/' + ui->projectName->text() + ".config";
}

void CreateProjectWindow::createProject()
{
    QString name = ui->projectName->text();
    QString memorySize = ui->memorySize->text();
    QString path = ui->locationPath->text();
    std::ofstream out;
    std::ofstream sampleCodeOut;
    if(!name.isEmpty() && !memorySize.isEmpty() && !path.isEmpty())
    {
        QString file = "setMemory("+memorySize+")\n"
                       +"startAt(0)\n"+"setAt(src/main.asm,0)\n"+"setSP(128)";
        path += '/' + name;
        QDir().mkdir(path);
        QDir().mkdir(path+"/src");
        out.open(path.toStdString()+'/'+name.toStdString()+".config");
        if(out.is_open())
        {
            out << file.toStdString();
            out.close();
        }
        sampleCodeOut.open(path.toStdString()+"/src/main.asm");
        if(sampleCodeOut.is_open())
        {
            sampleCodeOut << "//Start";
            sampleCodeOut.close();
        }
        createGitRepo(path);
    }

}
void CreateProjectWindow::createGitRepo(const QString &path)
{
    QProcess* process = new QProcess();
    process->startCommand("git init " +path);
    if(!process->waitForFinished(3000))
        std::cerr<<"Could not initialize git repository"<<std::endl;
    delete process;
}
void CreateProjectWindow::openSelectFolder()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory", "./"));
    if(path != "")
    {
        ui->locationPath->setText(path);
    }
}
void CreateProjectWindow::checkDir()
{
    if(ui->locationPath->text().isEmpty() || !QDir(ui->locationPath->text()).exists())
    {
        ui->checkPathLabel->setVisible(true);
    }
    else{
        ui->checkPathLabel->setVisible(false);
    }
}
void CreateProjectWindow::checkName()
{
    if(ui->locationPath->text().isEmpty() || QDir(ui->locationPath->text() + '/' + ui->projectName->text()).exists())
    {
        ui->badNameLabel->setVisible(true);
    }
    else{
        ui->badNameLabel->setVisible(false);
    }
}

CreateProjectWindow::~CreateProjectWindow()
{
    delete ui;
}
