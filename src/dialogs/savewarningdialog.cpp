#include "savewarningdialog.h"
#include "ui_savewarningdialog.h"

SaveWarningDialog::SaveWarningDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SaveWarningDialog)
{
    ui->setupUi(this);
}

void SaveWarningDialog::setFilePath(const QString &path)
{
    setWindowTitle(path);
}

SaveWarningDialog::~SaveWarningDialog()
{
    delete ui;
}
