#include "terminalwidget.h"
#include "ui_terminalwidget.h"
#include <csignal>
#include <qtermwidget6/qtermwidget.h>

TerminalWidget::TerminalWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TerminalWidget)
{
    ui->setupUi(this);
    terminal = new QTermWidget(this);
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
    connect(ui->copyButton, &QPushButton::clicked, terminal, &QTermWidget::copyClipboard);
    connect(ui->pasteButton, &QPushButton::clicked, terminal, &QTermWidget::pasteClipboard);

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

QStringList TerminalWidget::getThemes()
{
    return terminal->getAvailableColorSchemes();
}

void TerminalWidget::setTheme(const QString &theme)
{
    terminal->setColorScheme(theme);
}

void TerminalWidget::increaseFontSize()
{
    terminal->zoomIn();
}

void TerminalWidget::decreaseFontSize()
{
    terminal->zoomOut();
}

void TerminalWidget::resetFontSize()
{
    setFontSize(10);
}

void TerminalWidget::setFontSize(int size)
{
    QFont font = terminal->getTerminalFont();
    font.setPointSize(size);
    terminal->setTerminalFont(font);
}

void TerminalWidget::copy()
{
    terminal->copyClipboard();
}

void TerminalWidget::paste()
{
    terminal->pasteClipboard();
}

void TerminalWidget::pasteSelected()
{
    terminal->pasteSelection();
}

void TerminalWidget::scrollToEnd()
{
    terminal->scrollToEnd();
}

void TerminalWidget::wheelEvent(QWheelEvent *event)
{
    if(event->modifiers() == Qt::ControlModifier)
    {
        if(event->angleDelta().y() > 0)
        {
            increaseFontSize();
        }
        else
        {
            decreaseFontSize();
        }
        event->accept();
    }
    else
        QWidget::wheelEvent(event);
}
