#ifndef PROJECTMAKER_H
#define PROJECTMAKER_H

#include "8080/assembler.h"
#include "globals.h"
#include<QString>
#include <map>
#include <QList>


class ProjectManager
{
private:
    void decodeAndApply(std::pair<QString, QString> varvalPair);
    std::map<QString, int> codesMap = {{"setMemory", 0}, {"startAt", 1}, {"setAt", 2}, {"setSP", 3}};
    std::vector<std::pair<QString, int>> compileQueue;
    Assembler* assembler = nullptr;
    QString projectAbsolutePath;
    QString projectName;
    QString projectConfigAbsolutePath;
    QStringList projectFilesPaths;
    QVector<QString> logging;
    void log(QString msg);
    QList<Globals::FileMemoryStartEnd> fileMemoryRanges;
    std::vector<std::pair<unsigned short, int>> breakpoints;
    std::vector<std::pair<QString, std::vector<int>>> lineBreakpoints;
    std::vector<std::string> errors;
    std::vector<std::pair<unsigned short, int>> lineAddrInsts;
public:
    ProjectManager();
    ~ProjectManager();
    void readConfig(QString path);
    unsigned char* compile();
    QString getName() const;
    QString getProjectAbsolutePath() const;
    QString getProjectConfigAbsolutePath() const;
    bool hasGitRepository();
    void clearCompilerQueue();
    QStringList getProjectFilesPaths() const;
    QList<Globals::FileMemoryStartEnd> getFileMemoryRanges() const;
    void clearFileMemoryRanges();
    void setFileBreakpoints(const std::vector<std::pair<QString, std::vector<int>>>& bp);
    std::vector<std::pair<unsigned short, int>>& getBreakpoints();
    void clearBreakPoints();
    std::vector<std::string> getErrors() const;
    void pushBackErrors(const std::vector<std::string>& errs, const QString &fileName);
    void resetErrors();
    std::vector<std::pair<unsigned short, int> > getLineAddrInsts() const;
    void clearLineAddrInsts();
};

#endif // PROJECTMAKER_H
