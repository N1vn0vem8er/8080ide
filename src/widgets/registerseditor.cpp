#include "registerseditor.h"
#include "ui_registerseditor.h"

RegistersEditor::RegistersEditor(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::RegistersEditor)
{
    ui->setupUi(this);
    connect(ui->applyButton, &QPushButton::pressed, this, &RegistersEditor::apply);
    ui->errorOut->setVisible(false);
}

RegistersEditor::~RegistersEditor()
{
    delete ui;
}

void RegistersEditor::setRegisterValues(const QString &a, const QString &b, const QString &c, const QString &d, const QString &e, const QString &h, const QString &l, const QString &PC, const QString &SP)
{
    ui->aReg->setText(a);
    ui->bReg->setText(b);
    ui->cReg->setText(c);
    ui->dReg->setText(d);
    ui->eReg->setText(e);
    ui->hReg->setText(h);
    ui->lReg->setText(l);
    ui->pcReg->setText(PC);
    ui->spReg->setText(SP);
}

void RegistersEditor::apply()
{
    ui->errorOut->setVisible(false);
    char* endptr = nullptr;
    errno = 0;
    unsigned char a,b,c,d,e,h,l;
    a = strtol(ui->aReg->text().toStdString().c_str(), &endptr, 16);
    if(endptr == ui->aReg->text().toStdString().c_str())
    {
        error("Areg parsing error");
        return;
    }
    if(errno == ERANGE)
    {
        error("Areg value out of range");
        return;
    }
    errno = 0;
    b = strtol(ui->bReg->text().toStdString().c_str(), &endptr, 16);
    if(endptr == ui->bReg->text().toStdString().c_str())
    {
        error("Breg parsing error");
        return;
    }
    if(errno == ERANGE)
    {
        error("Breg value out of range");
        return;
    }
    errno = 0;
    c = strtol(ui->cReg->text().toStdString().c_str(), &endptr, 16);
    if(endptr == ui->cReg->text().toStdString().c_str())
    {
        error("Creg parsing error");
        return;
    }
    if(errno == ERANGE)
    {
        error("Creg value out of range");
        return;
    }
    errno = 0;
    d = strtol(ui->dReg->text().toStdString().c_str(), &endptr, 16);
    if(endptr == ui->dReg->text().toStdString().c_str())
    {
        error("Dreg parsing error");
        return;
    }
    if(errno == ERANGE)
    {
        error("Dreg value out of range");
        return;
    }
    errno = 0;
    e = strtol(ui->eReg->text().toStdString().c_str(), &endptr, 16);
    if(endptr == ui->eReg->text().toStdString().c_str())
    {
        error("Ereg parsing error");
        return;
    }
    if(errno == ERANGE)
    {
        error("Ereg value out of range");
        return;
    }
    errno = 0;
    h = strtol(ui->hReg->text().toStdString().c_str(), &endptr, 16);
    if(endptr == ui->hReg->text().toStdString().c_str())
    {
        error("Hreg parsing error");
        return;
    }
    if(errno == ERANGE)
    {
        error("Hreg value out of range");
        return;
    }
    errno = 0;
    l = strtol(ui->lReg->text().toStdString().c_str(), &endptr, 16);
    if(endptr == ui->lReg->text().toStdString().c_str())
    {
        error("Lreg parsing error");
        return;
    }
    if(errno == ERANGE)
    {
        error("Lreg value out of range");
        return;
    }
    unsigned short pc,sp;
    errno = 0;
    pc = strtol(ui->pcReg->text().toStdString().c_str(), nullptr, 16);
    if(endptr == ui->pcReg->text().toStdString().c_str())
    {
        error("PC parsing error");
        return;
    }
    if(errno == ERANGE)
    {
        error("PC value out of range");
        return;
    }
    errno = 0;
    sp = strtol(ui->spReg->text().toStdString().c_str(), nullptr, 16);
    if(endptr == ui->spReg->text().toStdString().c_str())
    {
        error("SP parsing error");
        return;
    }
    if(errno == ERANGE)
    {
        error("SP value out of range");
        return;
    }
    emit changeRegisters(a, b, c, d, e, h, l, pc, sp);
}

void RegistersEditor::error(const QString &message)
{
    ui->errorOut->setText(message);
    ui->errorOut->setVisible(true);
}


