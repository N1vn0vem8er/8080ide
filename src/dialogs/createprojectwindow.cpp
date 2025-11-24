#include "createprojectwindow.h"
#include "ui_createprojectwindow.h"
#include "utils/projectconfig.h"
#include <fstream>

#include <QFileDialog>
#include <QProcess>
#include <QThread>

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
    return ui->locationPath->text() + '/' + ui->projectName->text() + '/' + ui->projectName->text() + ".json";
}

void CreateProjectWindow::createProject()
{
    const QString name = ui->projectName->text();
    const QString memorySize = ui->memorySize->text();
    QString path = ui->locationPath->text();
    std::ofstream out;
    std::ofstream sampleCodeOut;
    if(!name.isEmpty() && !memorySize.isEmpty() && !path.isEmpty())
    {
        ProjectConfig projectConfig;
        projectConfig.setName(name);
        projectConfig.setMemorySize(memorySize.toInt());
        projectConfig.setStartAt(0);
        projectConfig.setStackPointer(128);
        path += '/' + name;
        projectConfig.setFilesInMemory({{"src/main.asm", 0}});
        QDir().mkdir(path);
        QDir().mkdir(path+"/src");
        QFile file(path + "/src/main.asm");
        if(file.open(QIODevice::WriteOnly))
        {
            file.write("//Start");
            file.close();
        }
        projectConfig.toFile(path + "/" + name + ".json");
        createGitRepo(path);
    }

}
void CreateProjectWindow::createGitRepo(const QString &path) const
{
    QProcess process;
    process.startCommand("git init " +path);
    process.waitForStarted(3000);
    if(!process.waitForFinished(3000))
        qDebug() << "Could not initialize git repository";
}
void CreateProjectWindow::openSelectFolder()
{
    const QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory", "./"));
    if(path != "")
    {
        ui->locationPath->setText(path);
    }
}
void CreateProjectWindow::checkDir() const
{
    if(ui->locationPath->text().isEmpty() || !QDir(ui->locationPath->text()).exists())
    {
        ui->checkPathLabel->setVisible(true);
    }
    else{
        ui->checkPathLabel->setVisible(false);
    }
}
void CreateProjectWindow::checkName() const
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
