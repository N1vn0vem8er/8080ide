#ifndef GLOBALS_H
#define GLOBALS_H

#include <QList>
#include <QString>
#endif // GLOBALS_H

namespace Globals
{

struct FileMemoryStartEnd
{
    QString fileName;
    unsigned short start;
    unsigned short end;
    FileMemoryStartEnd(QString fileName, unsigned short start, unsigned short end) : fileName(fileName), start(start), end(end){}
};

const QString SETTINGSFILENAME = "settings.ini";
const QString SETTINGSDIRNAME = "8080ide";

}
