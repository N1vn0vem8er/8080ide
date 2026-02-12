#include "terminalwidget.h"
#include "ui_terminalwidget.h"
#include "idesettings.h"
#ifndef Q_OS_WIN
#include <csignal>
#include <qtermwidget6/qtermwidget.h>
#else
#include <QLabel>
#endif

TerminalWidget::TerminalWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::TerminalWidget)
{
    ui->setupUi(this);

#ifdef Q_OS_WIN
    unsupportedLabel = new QLabel(tr("Terminal unsupported on Windows"), this);
    unsupportedLabel->setAlignment(Qt::AlignCenter);
#else

    terminal = new QTermWidget(this);
    connect(ui->intButton, &QPushButton::clicked, this, &TerminalWidget::sigint);
    connect(ui->tstpButton, &QPushButton::clicked, this, &TerminalWidget::sigtstp);
    connect(ui->quitButton, &QPushButton::clicked, this, &TerminalWidget::sigterm);
    connect(ui->copyButton, &QPushButton::clicked, terminal, &QTermWidget::copyClipboard);
    connect(ui->pasteButton, &QPushButton::clicked, terminal, &QTermWidget::pasteClipboard);

    if(!IDESettings::terminalTheme.isEmpty() && terminal->availableColorSchemes().contains(IDESettings::terminalTheme))
        terminal->setColorScheme(IDESettings::terminalTheme);

    setFontSize(IDESettings::defaultTerminalFontSize);
    setTerminalFont(QFont(IDESettings::defaultTerminalFont));

    QHBoxLayout* layout = static_cast<QHBoxLayout*>(this->layout());
    layout->addWidget(terminal);
    layout->setStretch(1, 1);
#endif
}

TerminalWidget::~TerminalWidget()
{
    delete ui;
}

QStringList TerminalWidget::getThemes()
{
#ifndef Q_OS_WIN
    return terminal->getAvailableColorSchemes();
#else
    return {};
#endif
}

void TerminalWidget::setTheme(const QString &theme)
{
#ifndef Q_OS_WIN
    terminal->setColorScheme(theme);
    IDESettings::terminalTheme = theme;
    IDESettings().saveSettings();
#endif
}

void TerminalWidget::setTerminalFont(const QFont &font)
{
#ifndef Q_OS_WIN
    terminal->setTerminalFont(font);
#endif
}

void TerminalWidget::increaseFontSize()
{
#ifndef Q_OS_WIN
    terminal->zoomIn();
#endif
}

void TerminalWidget::decreaseFontSize()
{
#ifndef Q_OS_WIN
    terminal->zoomOut();
#endif
}

void TerminalWidget::resetFontSize()
{
#ifndef Q_OS_WIN
    setFontSize(10);
#endif
}

void TerminalWidget::setFontSize(int size)
{
#ifndef Q_OS_WIN
    QFont font = terminal->getTerminalFont();
    font.setPointSize(size);
    terminal->setTerminalFont(font);
#endif
}

void TerminalWidget::copy()
{
#ifndef Q_OS_WIN
    terminal->copyClipboard();
#endif
}

void TerminalWidget::paste()
{
#ifndef Q_OS_WIN
    terminal->pasteClipboard();
#endif
}

void TerminalWidget::pasteSelected()
{
#ifndef Q_OS_WIN
    terminal->pasteSelection();
#endif
}

void TerminalWidget::scrollToEnd()
{
#ifndef Q_OS_WIN
    terminal->scrollToEnd();
#endif
}

void TerminalWidget::sigstop()
{
#ifndef Q_OS_WIN
    int id = terminal->getForegroundProcessId();
    kill(id, SIGSTOP);
#endif
}

void TerminalWidget::sigint()
{
#ifndef Q_OS_WIN
    int id = terminal->getForegroundProcessId();
    kill(id, SIGINT);
#endif
}

void TerminalWidget::sigterm()
{
#ifndef Q_OS_WIN
    int id = terminal->getForegroundProcessId();
    kill(id, SIGTERM);
#endif
}

void TerminalWidget::sigkill()
{
#ifndef Q_OS_WIN
    int id = terminal->getForegroundProcessId();
    kill(id, SIGKILL);
#endif
}

void TerminalWidget::sigquit()
{
#ifndef Q_OS_WIN
    int id = terminal->getForegroundProcessId();
    kill(id, SIGQUIT);
#endif
}

void TerminalWidget::sighup()
{
#ifndef Q_OS_WIN
    int id = terminal->getForegroundProcessId();
    kill(id, SIGHUP);
#endif
}

void TerminalWidget::sigtstp()
{
#ifndef Q_OS_WIN
    int id = terminal->getForegroundProcessId();
    kill(id, SIGTSTP);
#endif
}

void TerminalWidget::wheelEvent(QWheelEvent *event)
{
#ifndef Q_OS_WIN
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
#else
    QWidget::wheelEvent(event);
#endif
}
