#include "projectmanager.h"
#include "8080/assembler.h"
#include "qdir.h"
#include "qfileinfo.h"
#include "ssettings.h"

ProjectManager::ProjectManager(QObject *parent) : QObject(parent)
{

}

ProjectManager::~ProjectManager()
{

}

void ProjectManager::readConfig(const QString &path)
{
    projectAbsolutePath = QFileInfo(path).dir().absolutePath();
    projectConfigAbsolutePath = path;
    projectConfig.fromFile(path);
    Ssettings::memSize = projectConfig.getMemorySize();
    Ssettings::memStart = projectConfig.getStartAt();
    Ssettings::sp = projectConfig.getStackPointer();
    for(const auto& i : projectConfig.getFilesInMemory())
    {
        const QString filePath = projectAbsolutePath + QDir::separator() + i.first;
        QFile file(filePath);
        if(file.open(QIODevice::ReadOnly))
        {
            projectFilesPaths.append(filePath);
            fileMemoryRanges.push_back(Globals::FileMemoryStartEnd(filePath, i.second, 0));
            QString content = file.readAll();
            file.close();
            if(!content.endsWith('\n'))
                content+="\n";
            compileQueue.push_back({content, i.second});
        }
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
    for(const auto& i : preComp)
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

void ProjectManager::clearCompilerQueue()
{
    compileQueue.clear();
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

