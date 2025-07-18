#ifndef GLOBALS_H
#define GLOBALS_H

#include <QList>
#include <QString>

namespace Globals
{

struct FileMemoryStartEnd
{
    QString fileName;
    unsigned short start;
    unsigned short end;
    FileMemoryStartEnd(QString fileName, unsigned short start, unsigned short end) : fileName(fileName), start(start), end(end){}
};

struct SimStatus{
    SimStatus(){};
    SimStatus(const QString& areg, const QString& breg, const QString& creg, const QString& dreg, const QString& ereg, const QString& hreg, const QString& lreg,
              const QString& pc, const QString& sp, const QString& cf, const QString& sf, const QString& pf, const QString& zf, const QString& acf, const QString& mreg) :
        areg(areg), breg(breg), creg(creg), dreg(dreg), ereg(ereg), hreg(hreg), lreg(lreg), pc(pc), sp(sp), cf(cf), sf(sf), pf(pf), zf(zf), acf(acf), mreg(mreg){};
    QString areg;
    QString breg;
    QString creg;
    QString dreg;
    QString ereg;
    QString hreg;
    QString lreg;
    QString pc;
    QString sp;
    QString cf;
    QString sf;
    QString pf;
    QString zf;
    QString acf;
    QString mreg;
    auto operator<=>(const SimStatus&) const = default;
};

const QString SETTINGSFILENAME = "settings.ini";
const QString SETTINGSDIRNAME = "8080ide";

}

#endif // GLOBALS_H
