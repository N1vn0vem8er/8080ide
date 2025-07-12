#include "basicterminal.h"

BasicTerminal::BasicTerminal(QWidget *parent) : QPlainTextEdit(parent)
{
    setFont(QFontDatabase::systemFont(QFontDatabase::FixedFont));
    process = new QProcess(this);
    process->setProcessChannelMode(QProcess::MergedChannels);
    connect(process, &QProcess::readyRead, this, &BasicTerminal::output);
    process->start("/bin/bash", {"-i"});
    process->waitForStarted();
}

BasicTerminal::~BasicTerminal()
{
    process->write("exit\n");
    process->waitForFinished(3000);
    process->terminate();
    process->waitForFinished(3000);
    if(process->state() != QProcess::NotRunning || !process->atEnd()) process->kill();
    process->waitForFinished(3000);
}

void BasicTerminal::sigint()
{
    process->write("\x03");
}

void BasicTerminal::sigtstp()
{
    process->write("\x1a");
}

void BasicTerminal::sigquit()
{
    process->write("\x1c");
}

void BasicTerminal::keyPressEvent(QKeyEvent *event)
{
    switch(event->key())
    {
    case Qt::Key_Return:
    case Qt::Key_Enter:
        process->write("\n");
        break;
    case Qt::Key_Backspace:
        process->write("\b");
        if(textCursor().position() > 0)
        {
            textCursor().deletePreviousChar();
        }
        break;
    case Qt::Key_Tab:
        process->write("\t");
        break;
    default:
        process->write(event->text().toUtf8());
        break;
    }
}

void BasicTerminal::output()
{
    QString out = process->readAllStandardOutput().removeIf([](QChar c){
        return (c < QChar(32) || c > QChar(126)) && c != '\n' && c != '\t';
    });
    if(out != " ")
        insertPlainText(out);
    QPlainTextEdit::ensureCursorVisible();
}
