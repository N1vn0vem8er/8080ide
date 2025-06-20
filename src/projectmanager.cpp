#include "projectmanager.h"
#include <fstream>
#include <sstream>
#include "8080/assembler.h"
#include "qdir.h"
#include "qfileinfo.h"
#include "qprocess.h"
#include "ssettings.h"

ProjectManager::ProjectManager()
{

}

ProjectManager::~ProjectManager()
{

}
void ProjectManager::readConfig(QString path)
{
    projectName = QFileInfo(path).baseName();
    QString config;
    if(path != "")
    {
        QFileInfo info(path);
        projectAbsolutePath = info.dir().absolutePath();
        projectConfigAbsolutePath = path;
        try {
            std::ifstream file;
            file.open(path.toStdString());
            if(file.is_open())
            {
                std::stringstream ss;
                ss << file.rdbuf();
                config = QString::fromStdString(ss.str());
                file.close();
            }
        } catch (...) {
            return;
        }
        QString variable = "";
        QString value = "";
        bool varPart = true;
        std::vector<std::pair<QString, QString>> varvalList;
        for(int i = 0; i < config.length(); i++)
        {
            if(config[i] == '\n' || config[i] == ';' || config[i] == ' ')continue;
            if(config[i] == '(')
            {
                varPart = false;
                continue;
            }
            if(config[i] == ')')
            {
                varvalList.push_back(std::make_pair(variable, value));
                varPart = true;
                variable = "";
                value = "";
                continue;
            }
            if(varPart)
            {
                variable += config[i];
            }
            else{
                value += config[i];
            }

        }
        for(const auto &i : varvalList)
        {
            decodeAndApply(i);
        }
    }
}
void ProjectManager::decodeAndApply(std::pair<QString, QString> varvalPair)
{
    switch(codesMap.find(varvalPair.first)->second)
    {
    case 0:
        Ssettings::memSize = varvalPair.second.toInt();
        break;
    case 1:
        Ssettings::memStart = varvalPair.second.toInt();
        break;
    case 2:
    {
        QString path = "";
        QString addr = "";
        bool first = true;
        for(auto i : std::as_const(varvalPair.second))
        {
            if(i == ',')
            {
                first = false;
                continue;
            }
            if(first) path+=i;
            else addr+=i;
        }
        projectFilesPaths.append(projectAbsolutePath + '/' + path);
        fileMemoryRanges.push_back(Globals::FileMemoryStartEnd(projectAbsolutePath + '/' +path, addr.toInt(), 0));
        std::ifstream file;
        file.open(projectAbsolutePath.toStdString() + '/' + path.toStdString());
        if(file.is_open())
        {
            std::stringstream ss;
            ss << file.rdbuf();
            path = QString::fromStdString(ss.str());
            if(!path.endsWith('\n'))path+='\n';
            file.close();
        }
        compileQueue.push_back(std::make_pair(path, addr.toInt()));
    }
        break;
    case 3:
        Ssettings::sp = varvalPair.second.toInt();
        break;
    }
}
unsigned char* ProjectManager::compile()
{
    if(compileQueue.empty()) return nullptr;
    unsigned char* memory = new unsigned char[Ssettings::memSize];
    memset(memory, 0, Ssettings::memSize);
    Assembler a;
    std::vector<std::vector<std::string>> preComp;
    int index = 0;
    for(const auto &p : compileQueue)
    {
        int address = p.second;
        a.setAssemblerAddress(address);
        std::vector<std::string> tmp = a.toVector(p.first.toStdString());
        preComp.push_back(tmp);
    }
    for(auto& i : preComp)
    {
        i = a.decodeConstants(i);
        pushBackErrors(a.getErrorMessages(), fileMemoryRanges[index].fileName);
        a.clearErrorMessages();
        index++;
    }
    index = 0;
    for(auto& i : preComp)
    {
        if(!lineBreakpoints.empty())
        {
            for(auto& breakpoint : lineBreakpoints)
            {
                if(breakpoint.first == fileMemoryRanges[index].fileName)
                {
                    a.setBreakpoints(breakpoint.second);
                    i = a.decodeIfsAndMacros(i);
                    breakpoint.second = a.getBreakpoints();
                    break;
                }
            }
        }
        else
        {
            i = a.decodeIfsAndMacros(i);
        }
        pushBackErrors(a.getErrorMessages(), fileMemoryRanges[index].fileName);
        a.clearErrorMessages();
        index++;
    }
    for(auto& i : preComp)
    {
        i = a.applyMacros(i);
    }
    index = 0;
    for(auto& i : preComp)
    {
        i = a.decodeLabels(i, compileQueue[index].second);
        pushBackErrors(a.getErrorMessages(), fileMemoryRanges[index].fileName);
        a.clearErrorMessages();
        index++;
    }
    index = 0;
    for(auto& i : preComp)
    {
        i = a.decodeOperands(i);
        pushBackErrors(a.getErrorMessages(), fileMemoryRanges[index].fileName);
        a.clearErrorMessages();
        index++;
    }
    index = 0;
    a.clearBreakpoints();
    for(auto& i : preComp)
    {
        unsigned char* comp = nullptr;
        if(!lineBreakpoints.empty())
        {
            for(auto& breakpoint : lineBreakpoints)
            {
                if(breakpoint.first == fileMemoryRanges[index].fileName)
                {
                    a.setBreakpoints(breakpoint.second);
                    break;
                }
            }
        }
        a.setAssemblerAddress(compileQueue[index].second);
        comp = a.assemble(i);
        pushBackErrors(a.getErrorMessages(), fileMemoryRanges[index].fileName);
        a.clearErrorMessages();
        int memIndex = compileQueue[index].second;
        for(int j = 0; j < a.getCompCodeSize(); j++)
        {
            memory[memIndex] = comp[j];
            memIndex++;
            if(memIndex == Ssettings::memSize)break;
        }
        for(const auto& j : a.getCodeBreakpoints())
        {
            breakpoints.push_back(j);
        }
        for(const auto& j : a.getLineAddrInsts())
        {
            lineAddrInsts.push_back(j);
        }
        a.clearCodeBreakpoints();
        a.clearBreakpoints();
        a.resetLineAddrInsts();
        delete[] comp;
        fileMemoryRanges[index].end = compileQueue[index].second + a.getCompCodeSize();
        index++;
    }
    compileQueue.clear();
    return memory;
}
QString ProjectManager::getName() const
{
    return projectName;
}
QString ProjectManager::getProjectAbsolutePath() const
{
    return projectAbsolutePath;
}
QString ProjectManager::getProjectConfigAbsolutePath() const
{
    return projectConfigAbsolutePath;
}

bool ProjectManager::hasGitRepository()
{
    if(projectAbsolutePath=="")return false;
    QDir dir(projectAbsolutePath);
    QStringList files = dir.entryList(QStringList() << ".git", QDir::Dirs | QDir::Hidden);
    if(files.isEmpty()) return false;
    else return true;
}

void ProjectManager::clearCompilerQueue()
{
    compileQueue.clear();
}

QStringList ProjectManager::getBranches()
{
    gitBranches.clear();
    if(hasGitRepository())
    {
        QProcess* process = new QProcess();
        process->setWorkingDirectory(projectAbsolutePath);
        process->startCommand("git branch --format='%(refname:short)'");
        process->waitForFinished();
        QByteArray output = process->readAll();
        delete process;
        QString line = "";
        for(auto i : std::as_const(output))
        {
            if(i=='\n')
            {
                gitBranches.append(line);
                line = "";
                continue;
            }
            line+=i;
        }
    }
    return gitBranches;
}

QStringList ProjectManager::getProjectFilesPaths() const
{
    return projectFilesPaths;
}

QList<Globals::FileMemoryStartEnd> ProjectManager::getFileMemoryRanges() const
{
    return fileMemoryRanges;
}

void ProjectManager::clearFileMemoryRanges()
{
    fileMemoryRanges.clear();
}

void ProjectManager::setFileBreakpoints(const std::vector<std::pair<QString, std::vector<int>>> &bp)
{
    lineBreakpoints = bp;
}

std::vector<std::pair<unsigned short, int> > &ProjectManager::getBreakpoints()
{
    return breakpoints;
}

void ProjectManager::clearBreakPoints()
{
    breakpoints.clear();
    lineBreakpoints.clear();
}

void ProjectManager::log(QString msg)
{
    logging.append(msg);
}

std::vector<std::pair<unsigned short, int> > ProjectManager::getLineAddrInsts() const
{
    return lineAddrInsts;
}

void ProjectManager::clearLineAddrInsts()
{
    lineAddrInsts.clear();
}

void ProjectManager::resetErrors()
{
    errors.clear();
}

std::vector<std::string> ProjectManager::getErrors() const
{
    return errors;
}

void ProjectManager::pushBackErrors(const std::vector<std::string> &errs, const QString& fileName)
{
    for(const auto& i : errs)
    {
        errors.push_back(i + " in file: " + fileName.toStdString() + "\n");
    }
}

