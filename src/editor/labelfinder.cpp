#include "labelfinder.h"
#include "qdir.h"
#include "qdiriterator.h"

LabelFinder::LabelFinder(QObject *parent)
    : QThread{parent}
{
    projectMode = false;
}

void LabelFinder::setProjectPath(const QString &path)
{
    projectPath = path;
}

void LabelFinder::setFilePath(const QString &path)
{
    filePath = path;
}

void LabelFinder::setText(const QString &text)
{
    this->text = text;
}

void LabelFinder::setProjectMode(bool val)
{
    projectMode = val;
}

bool LabelFinder::isProjectMode() const
{
    return projectMode;
}

void LabelFinder::run()
{
    QStringList labels;
    labels.clear();
    if(projectMode)
    {
        if(!projectPath.isEmpty())
        {
            QDirIterator it(projectPath, QStringList() << "*.asm", QDir::Files, QDirIterator::Subdirectories);
            while(it.hasNext())
            {
                if(QThread::currentThread()->isInterruptionRequested()) return;
                labels.append(readLabelsFromFile(it.next()));
            }
        }
        else if(!filePath.isEmpty())
            labels.append(readLabelsFromFile(filePath));
    }
    labels.append(readFromString(text));
    if(QThread::currentThread()->isInterruptionRequested()) return;
    emit resoultsReady(labels);
}

QStringList LabelFinder::readLabelsFromFile(const QString path) const
{
    QStringList labels;
    QFile file(path);
    file.open(QIODevice::ReadOnly);
    if(file.isOpen())
    {
        QTextStream fileStream(&file);
        while(!fileStream.atEnd())
        {
            if(QThread::currentThread()->isInterruptionRequested()) break;
            QString line = fileStream.readLine();
            if(line.length()>2 && line.contains(":") && line[0] != ':')
            {
                labels.append(line.left(line.indexOf(":")));
            }
        }
        file.close();
    }
    return labels;
}

QStringList LabelFinder::readFromString(QString text) const
{
    QStringList labels;
    if(text.length() <= 1) return labels;
    QTextStream stream(&text);
    while(!stream.atEnd())
    {
        if(QThread::currentThread()->isInterruptionRequested()) break;
        QString line = stream.readLine();
        if(line.length()>2 && line.contains(":") && line[0] != ':')
        {
            labels.append(line.left(line.indexOf(":")));
        }
    }
    return labels;
}
