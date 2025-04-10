#include "simhandeler.h"
#include "qprocess.h"
#include "simrunner.h"
#include "ssettings.h"
#include "8080/assembler.h"


void SimHandeler::printOnScreen(char text)
{
    this->screen->insertPlainText(QString(text));
}
void SimHandeler::printOnScreen(const char* text)
{
    this->screen->insertPlainText(QString(text));
}
void SimHandeler::clearScreen()
{
    this->screen->clear();
}
void SimHandeler::updateRegistersLabels()
{
    areg->setText("A = " + QString::fromStdString(tohexASCII(symulator->getAreg())));
    breg->setText("B = " + QString::fromStdString(tohexASCII(symulator->getBreg())));
    creg->setText("C = " + QString::fromStdString(tohexASCII(symulator->getCreg())));
    dreg->setText("D = " + QString::fromStdString(tohexASCII(symulator->getDreg())));
    ereg->setText("E = " + QString::fromStdString(tohexASCII(symulator->getEreg())));
    hreg->setText("H = " + QString::fromStdString(tohexASCII(symulator->getHreg())));
    lreg->setText("L = " + QString::fromStdString(tohexASCII(symulator->getLreg())));
    pc->setText("PC = " + QString::fromStdString(tohexASCII(symulator->getPC())));
    flags->setText(QString("C=%1 AC=%2 P=%3 S=%4 Z=%5").arg(QString::number(symulator->getCF())).arg(QString::number(symulator->getAC())).arg(QString::number(symulator->getP())).arg(QString::number(symulator->getS())).arg(QString::number(symulator->getZ())));
    mreg->setText("M = "+QString::fromStdString(tohexASCII(symulator->getMreg())));
    sp->setText("SP = "+QString::fromStdString(tohexASCII(symulator->getSP())));
    emit setRegisterValues(QString::fromStdString(tohexASCII(symulator->getAreg())), QString::fromStdString(tohexASCII(symulator->getBreg())), QString::fromStdString(tohexASCII(symulator->getCreg())),
                           QString::fromStdString(tohexASCII(symulator->getDreg())), QString::fromStdString(tohexASCII(symulator->getEreg())), QString::fromStdString(tohexASCII(symulator->getHreg())),
                           QString::fromStdString(tohexASCII(symulator->getLreg())), QString::fromStdString(tohexASCII(symulator->getPC())), QString::fromStdString(tohexASCII(symulator->getSP())));
}
std::string SimHandeler::tohexASCII(unsigned char ch)
{
    std::stringstream ss;
    ss << std::hex << +ch;
    return ss.str();
}
std::string SimHandeler::tohexASCII(unsigned short ch)
{
    std::stringstream ss;
    ss << std::hex << +ch;
    return ss.str();
}

SimHandeler::SimHandeler(QPlainTextEdit* screen, QObject* parent) : QObject{parent}
{
    this->symulator = new Symulator(256);
    this->screen = screen;
    projectManager = new ProjectManager();
    projectLoaded = false;
}

SimHandeler::~SimHandeler()
{
    if(sr != nullptr){
        sr->requestInterruption();
        sr->wait();
        delete sr;
    }
    delete projectManager;
    delete symulator;
    delete[] compcode;
}
void SimHandeler::openProject(const QString &path)
{
    delete projectManager;
    projectManager = new ProjectManager();
    log("Opening project at "+path);
    projectManager->readConfig(path);
    projectManager->clearCompilerQueue();
    projectLoaded = true;
    projectNameLabel->setText("Projekt: " + projectManager->getName());
    if(projectManager->hasGitRepository()) setBranchName();
    log("Project loaded");
}
void SimHandeler::closeProject()
{
    projectLoaded = false;
    projectNameLabel->setText("Brak Projektu");
    Ssettings::memSize = IDESettings::simMemorySize;
    Ssettings::memStart = IDESettings::simStartAddress;
    Ssettings::sp = 100;
}
void SimHandeler::setBranchName()
{
    if(projectGitBranchNameLabel == nullptr) return;
    QProcess process = QProcess();
    process.setWorkingDirectory(projectManager->getProjectAbsolutePath());
    process.startCommand("git rev-parse --abbrev-ref HEAD");
    process.waitForStarted(3000);
    process.waitForFinished();
    QString output = process.readAllStandardOutput();
    output.remove('\n');
    if(output != "HEAD")
        projectGitBranchNameLabel->setText(output);
}

void SimHandeler::log(QString text)
{
    if(logsOutput != nullptr)
    {
        logsOutput->appendPlainText(text);
    }
}

void SimHandeler::setBranch(QString name)
{
    name.remove('\'');
    QProcess process = QProcess();
    process.setWorkingDirectory(projectManager->getProjectAbsolutePath());
    process.startCommand("git checkout "+name);
    process.waitForStarted(3000);
    process.waitForFinished(3000);
    setBranchName();
}

QString SimHandeler::getFilename() const
{
    return filename;
}

void SimHandeler::setFilename(const QString &newFilename)
{
    filename = newFilename;
}

void SimHandeler::setFileBreakpoints(const std::vector<std::pair<QString, std::vector<int>> > &bp)
{
    fileBreakpoints = bp;
}

QStringList SimHandeler::getGitBranches()
{
    return projectManager->getBranches();
}

void SimHandeler::setLogsOutput(QPlainTextEdit *output)
{
    this->logsOutput = output;
}

QString SimHandeler::getProjectName()
{
    return projectManager->getName();
}

QStringList SimHandeler::getProjectFilesPaths()
{
    return projectManager->getProjectFilesPaths();
}

QString SimHandeler::getProjectPath()
{
    return projectManager->getProjectAbsolutePath();
}

void SimHandeler::readBreakPoints(QVector<int> breakpoints)
{
    this->breakpoints.insert(this->breakpoints.end(), breakpoints.begin(), breakpoints.end());
    hasBreakpoints = true;
}

void SimHandeler::breakpointContinue()
{
    emit simContinue();
}

bool SimHandeler::hasBreakPoints()
{
    return hasBreakpoints;
}

void SimHandeler::clearBreakpoints()
{
    hasBreakpoints = false;
    breakpoints.clear();
}

Symulator *SimHandeler::getSymulator()
{
    return symulator;
}

unsigned char *SimHandeler::getCompiled()
{
    return compcode;
}

int SimHandeler::getCompiledSize() const
{
    return compcodeSize;
}

int SimHandeler::getSimMemorySize() const
{
    return symulator->getMemSize();
}

void SimHandeler::setProjectNameLabel(QLabel* label)
{
    this->projectNameLabel = label;
}

void SimHandeler::setProjectGitBranchNameLabel(QLabel *label)
{
    this->projectGitBranchNameLabel = label;
}

void SimHandeler::setInputLine(QLineEdit *lineEdit)
{
    this->inputLine = lineEdit;
}
void SimHandeler::run()
{
    sr = new SimRunner(this);
    connect(sr, &SimRunner::charOut, this, &SimHandeler::print);
    connect(sr, &SimRunner::stateChanged, this, &SimHandeler::registersChanged);
    connect(this, &SimHandeler::inputToSim, sr, &SimRunner::input);
    connect(sr, &SimRunner::inputOut, this, &SimHandeler::inputOut);
    connect(this, &SimHandeler::getMemoryFromSim, sr, &SimRunner::getMemoryFromSim);
    connect(this, &SimHandeler::simContinue, sr, &SimRunner::breakpointContinue);
    connect(sr, &SimRunner::breakpointStop, this, &SimHandeler::breakpointCodeLocation);
    connect(sr, &SimRunner::memoryChanged, this, [=](QString memory, int size){emit memoryChanged(memory, size);});
    connect(this, &SimHandeler::memoryChangedByUserSignal, sr, &SimRunner::memoryChangedByUser);
    connect(this, &SimHandeler::changeRegisters, sr, &SimRunner::changeRegisters);
    sr->setSymulator(this->symulator);
    sr->setBreakPoints(breakpointsLocations);
    sr->setLineAddrInsts(lineAddrInsts);
    if(!inputLine->text().isEmpty())
        sr->input((char)inputLine->text().toStdString()[0]);
    sr->start();
}
QString SimHandeler::memoryToString()
{
    QString mem = "";
    if(symulator!=nullptr)
        for(int i = 0; i<symulator->getMemSize(); i++)
        {
            mem += QChar(symulator->getMemory()[i]);
        }
    return mem;
}
void SimHandeler::print(char ch)
{
    printOnScreen(ch);
}

void SimHandeler::registersChanged(QStringList registers)
{
    areg->setText("A = " + registers[0]);
    breg->setText("B = " + registers[1]);
    creg->setText("C = " + registers[2]);
    dreg->setText("D = " + registers[3]);
    ereg->setText("E = " + registers[4]);
    hreg->setText("H = " + registers[5]);
    lreg->setText("L = " + registers[6]);
    pc->setText("PC = " + registers[7]);
    flags->setText(QString("C=%1 AC=%2 P=%3 S=%4 Z=%5").arg(registers[8]).arg(registers[9]).arg(registers[10]).arg(registers[11]).arg(registers[12]));
    mreg->setText("M = "+registers[13]);
    sp->setText("SP = "+registers[14]);
    emit setRegisterValues(registers[0], registers[1], registers[2], registers[3], registers[4], registers[5],registers[6], registers[7], registers[14]);
}

void SimHandeler::inputOut(char ch)
{
    if(inputLine) ch == 0x0 ? inputLine->clear() : inputLine->setText(QChar(ch));
}

void SimHandeler::breakpointCodeLocation(int line, unsigned short address)
{
    QString fName;
    for(const auto& i : fileMemoryRanges)
    {
        if(address >= i.start && address <= i.end)
        {
            fName = i.fileName;
            break;
        }
    }
    emit breakpointHighlightLine(fName, line);
}

void SimHandeler::memoryChangedByUser(QString &memory, int size)
{
    if(sr != nullptr)
    {
        emit memoryChangedByUserSignal(memory, size);
    }
    else
    {
        if(size == symulator->getMemSize() && !memory.isEmpty())
        {
            int index = 0;
            for(const auto& i : memory)
            {
                symulator->getMemory()[index] = i.cell();
                index++;
            }
        }
    }
}

void SimHandeler::changedRegisters(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char h, unsigned char l, unsigned short pc, unsigned short sp)
{
    if(sr == nullptr)
    {
        symulator->setAreg(a);
        symulator->setBreg(b);
        symulator->setCreg(c);
        symulator->setDreg(d);
        symulator->setEreg(e);
        symulator->setHreg(h);
        symulator->setLreg(l);
        symulator->setPC(pc);
        symulator->setSP(sp);
        updateRegistersLabels();
        return;
    }
    emit changeRegisters( a, b, c, d, e,  h,  l, pc, sp);
}
void SimHandeler::compile()
{
    if(compcode != nullptr)
    {
        delete[] compcode;
        compcode = nullptr;
    }
    if(!projectLoaded)
    {
        Assembler a;
        std::vector<std::string> pre = a.toVector(code);
        a.setBreakpoints(breakpoints);
        pre = a.decodeConstants(pre);
        pre = a.decodeIfsAndMacros(pre);
        pre = a.applyMacros(pre);
        pre = a.decodeLabels(pre, 0);
        pre = a.decodeOperands(pre);
        compcode = a.assemble(pre);
        compcodeSize = a.getCompCodeSize();
        breakpointsLocations = a.getCodeBreakpoints();
        lineAddrInsts = a.getLineAddrInsts();
        for(const auto& i : a.getErrorMessages())
        {
            log(QString::fromStdString(i));
        }
    }
    else
    {
        projectManager->clearBreakPoints();
        projectManager->clearLineAddrInsts();
        projectManager->readConfig(projectManager->getProjectConfigAbsolutePath());
        projectManager->setFileBreakpoints(fileBreakpoints);
        compcode = projectManager->compile();
        lineAddrInsts = projectManager->getLineAddrInsts();
        breakpointsLocations = projectManager->getBreakpoints();
        fileMemoryRanges = projectManager->getFileMemoryRanges();
        compcodeSize = Ssettings::memSize;
        for(const auto& error : projectManager->getErrors())
        {
            log(QString::fromStdString(error));
        }
        projectManager->resetErrors();
    }
}
void SimHandeler::load()
{
    reset();
    if(compcode != nullptr && compcodeSize > 0)
    {
        this->symulator->load(this->compcode, this->compcodeSize);
        emit memoryChanged(memoryToString(), symulator->getMemSize());
    }
}
void SimHandeler::updateCode(const QString &code)
{
    this->code = code.toStdString() + '\n';
}
void SimHandeler::clr()
{
    compile();
    load();
    run();
}
void SimHandeler::next()
{
    if(symulator->getHLT()) return;
    this->symulator->setHLTType(0);
    symulator->nextInst();
    printOnScreen(symulator->getOutBuffer());
    symulator->setOutBuffer('\0');
    if(inputLine) symulator->getInBuffer() == 0x0 ? inputLine->clear() : inputLine->setText(QChar(symulator->getInBuffer()));
    updateRegistersLabels();
    emit memoryChanged(memoryToString(), symulator->getMemSize());
    QString fName;
    for(const auto& i : fileMemoryRanges)
    {
        if(symulator->getPC() >= i.start && symulator->getPC() <= i.end)
        {
            fName = i.fileName;
            break;
        }
    }
    for(const auto& i : lineAddrInsts)
    {
        if(symulator->getPC() == i.first)
        {
            emit stepLineHighlight(fName, i.second);
            break;
        }
    }
}

void SimHandeler::setScreen(QPlainTextEdit &screen)
{
    this->screen = &screen;
}
void SimHandeler::reset()
{
    if(sr!=nullptr)
    {
        sr->requestInterruption();
        sr->wait();
        sr->deleteLater();
        sr = nullptr;
    }
    this->screen->clear();
    delete symulator;
    this->symulator = new Symulator(Ssettings::memSize);
    this->symulator->setPC(Ssettings::memStart);
    this->symulator->setSP(Ssettings::sp);
    if(inputLine) inputLine->clear();
    updateRegistersLabels();
    emit memoryChanged(memoryToString(), symulator->getMemSize());
}

void SimHandeler::restart()
{
    if(sr!=nullptr)
    {
        sr->requestInterruption();
        sr->wait();
        sr->deleteLater();
        sr = nullptr;
    }
    this->screen->clear();
    symulator->setHLT(false);
    symulator->setPC(Ssettings::memStart);
    if(inputLine) inputLine->clear();
    updateRegistersLabels();
}

void SimHandeler::input(QString input)
{
    symulator->setInBuffer((char) input.toStdString()[0]);
    emit inputToSim((char)input.toStdString()[0]);
}
unsigned char* SimHandeler::getMemory()
{
    unsigned char* memory;
    if(sr!=nullptr)
    {
        memory = emit getMemoryFromSim();
    }
    else{
    memory = symulator->getMemory();
    }
    return memory;
}
void SimHandeler::setReferencesToRegisters(QLabel* areg, QLabel* breg, QLabel* creg, QLabel* dreg, QLabel* ereg, QLabel* hreg, QLabel* lreg,  QLabel* mreg, QLabel* pc, QLabel *flags, QLabel* sp)
{
    this->areg = areg;
    this->breg = breg;
    this->creg = creg;
    this->dreg = dreg;
    this->ereg = ereg;
    this->hreg = hreg;
    this->lreg = lreg;
    this->mreg = mreg;
    this->pc = pc;
    this->flags = flags;
    this->sp = sp;
}
bool SimHandeler::isProjectLoaded()
{
    return projectLoaded;
}
