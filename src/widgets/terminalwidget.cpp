#include "terminalwidget.h"
#include "ui_terminalwidget.h"
#include <csignal>
#include <qtermwidget6/qtermwidget.h>

TerminalWidget::TerminalWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TerminalWidget)
{
    ui->setupUi(this);
    connect(ui->intButton, &QPushButton::clicked, this, [&]{
        int id = terminal->getForegroundProcessId();
        kill(id, SIGINT);
    });
    connect(ui->tstpButton, &QPushButton::clicked, this, [&]{
        int id = terminal->getForegroundProcessId();
        kill(id, SIGTSTP);
    });
    connect(ui->quitButton, &QPushButton::clicked, this, [&]{
        int id = terminal->getForegroundProcessId();
        kill(id, SIGTERM);
    });
    terminal = new QTermWidget(this);
    if(terminal->availableColorSchemes().contains("BreezeModified"))
        terminal->setColorScheme("BreezeModified");

    QHBoxLayout* layout = static_cast<QHBoxLayout*>(this->layout());
    layout->addWidget(terminal);
    layout->setStretch(1, 1);
}

TerminalWidget::~TerminalWidget()
{
    delete ui;
}
