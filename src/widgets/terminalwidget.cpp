#include "terminalwidget.h"
#include "ui_terminalwidget.h"
#include <csignal>
#include "idesettings.h"
#include <qtermwidget6/qtermwidget.h>

TerminalWidget::TerminalWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TerminalWidget)
{
    ui->setupUi(this);
    terminal = new QTermWidget(this);
    connect(ui->intButton, &QPushButton::clicked, this, &TerminalWidget::sigint);
    connect(ui->tstpButton, &QPushButton::clicked, this, &TerminalWidget::sigtstp);
    connect(ui->quitButton, &QPushButton::clicked, this, &TerminalWidget::sigterm);
    connect(ui->copyButton, &QPushButton::clicked, terminal, &QTermWidget::copyClipboard);
    connect(ui->pasteButton, &QPushButton::clicked, terminal, &QTermWidget::pasteClipboard);

    if(!IDESettings::terminalTheme.isEmpty() && terminal->availableColorSchemes().contains(IDESettings::terminalTheme))
        terminal->setColorScheme(IDESettings::terminalTheme);

    setFontSize(IDESettings::defaultTerminalFontSize);

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
    IDESettings::terminalTheme = theme;
    IDESettings().saveSettings();
}

void TerminalWidget::setTerminalFont(const QFont &font)
{
    terminal->setTerminalFont(font);
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

void TerminalWidget::sigstop()
{
    int id = terminal->getForegroundProcessId();
    kill(id, SIGSTOP);
}

void TerminalWidget::sigint()
{
    int id = terminal->getForegroundProcessId();
    kill(id, SIGINT);
}

void TerminalWidget::sigterm()
{
    int id = terminal->getForegroundProcessId();
    kill(id, SIGTERM);
}

void TerminalWidget::sigkill()
{
    int id = terminal->getForegroundProcessId();
    kill(id, SIGKILL);
}

void TerminalWidget::sigquit()
{
    int id = terminal->getForegroundProcessId();
    kill(id, SIGQUIT);
}

void TerminalWidget::sighup()
{
    int id = terminal->getForegroundProcessId();
    kill(id, SIGHUP);
}

void TerminalWidget::sigtstp()
{
    int id = terminal->getForegroundProcessId();
    kill(id, SIGTSTP);
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
