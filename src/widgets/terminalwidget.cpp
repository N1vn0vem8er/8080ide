#include "terminalwidget.h"
#include "ui_terminalwidget.h"

TerminalWidget::TerminalWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TerminalWidget)
{
    ui->setupUi(this);
    connect(ui->intButton, &QPushButton::clicked, this, [&]{ui->plainTextEdit->sigint();});
    connect(ui->tstpButton, &QPushButton::clicked, this, [&]{ui->plainTextEdit->sigtstp();});
    connect(ui->quitButton, &QPushButton::clicked, this, [&]{ui->plainTextEdit->sigquit();});
}

TerminalWidget::~TerminalWidget()
{
    delete ui;
}
