#include "simhandeler.h"
#include "simrunner.h"
#include "ssettings.h"
#include "idesettings.h"
#include "8080/assembler.h"

void SimHandeler::clearScreen()
{
    textScreenWidget->clear();
}
void SimHandeler::updateRegistersLabels()
{
    emit displayRegisters(tohexASCII(symulator->getAreg()), tohexASCII(symulator->getBreg()), tohexASCII(symulator->getCreg()),
                          tohexASCII(symulator->getDreg()), tohexASCII(symulator->getEreg()), tohexASCII(symulator->getHreg()),
                          tohexASCII(symulator->getLreg()), tohexASCII(symulator->getMreg()), tohexASCII(symulator->getPC()),
                          QString::number(symulator->getCF()), QString::number(symulator->getS()), QString::number(symulator->getP()), QString::number(symulator->getZ()), QString::number(symulator->getAC()),
                          tohexASCII(symulator->getSP()));
    emit setRegisterValues(tohexASCII(symulator->getAreg()), tohexASCII(symulator->getBreg()), tohexASCII(symulator->getCreg()),
                           tohexASCII(symulator->getDreg()), tohexASCII(symulator->getEreg()), tohexASCII(symulator->getHreg()),
                           tohexASCII(symulator->getLreg()), tohexASCII(symulator->getPC()), tohexASCII(symulator->getSP()));
}
QString SimHandeler::tohexASCII(unsigned char ch) const
{
    std::stringstream ss;
    ss << std::hex << +ch;
    return QString::fromStdString(ss.str());
}
QString SimHandeler::tohexASCII(unsigned short ch) const
{
    std::stringstream ss;
    ss << std::hex << +ch;
    return QString::fromStdString(ss.str());
}

SimHandeler::SimHandeler(QObject* parent) : QObject{parent}
{
    symulator = std::make_unique<Symulator>(256);
    projectManager = new ProjectManager(this);
    projectLoaded = false;
}

SimHandeler::~SimHandeler()
{
    if(sr != nullptr){
        sr->requestInterruption();
        sr->wait();
        delete sr;
    }
    delete[] compcode;
}
void SimHandeler::openProject(const QString &path)
{
    projectManager->deleteLater();
    projectManager = new ProjectManager(this);
    log(tr("Opening project at %1").arg(path));
    projectManager->readConfig(path);
    projectManager->clearCompilerQueue();
    projectLoaded = true;
    emit setProjectNameLabel(tr("Project: %1").arg(projectManager->getName()));
    log(tr("Project loaded"));
}
void SimHandeler::closeProject()
{
    projectLoaded = false;
    emit setProjectNameLabel(tr("No project"));
    Ssettings::memSize = IDESettings::simMemorySize;
    Ssettings::memStart = IDESettings::simStartAddress;
    Ssettings::sp = 100;
}

void SimHandeler::log(const QString &text)
{
    if(logsOutput != nullptr)
    {
        logsOutput->appendPlainText(text);
    }
}

void SimHandeler::setSimFullSpeed(bool newSimFullSpeed)
{
    simFullSpeed = newSimFullSpeed;
}

void SimHandeler::setScreenWidget(ScreenWidget *newScreenWidget)
{
    screenWidget = newScreenWidget;
}

void SimHandeler::screenSetPixel(int x, int y, int color)
{
    if(screenWidget)
        screenWidget->setPixelColor(x, y, color);
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

void SimHandeler::setLogsOutput(QPlainTextEdit *output)
{
    this->logsOutput = output;
}

QString SimHandeler::getProjectName() const
{
    return projectManager->getName();
}

QStringList SimHandeler::getProjectFilesPaths() const
{
    return projectManager->getProjectFilesPaths();
}

QString SimHandeler::getProjectPath() const
{
    return projectManager->getProjectAbsolutePath();
}

QString SimHandeler::getProjectConfigPath() const
{
    return projectManager->getProjectConfigAbsolutePath();
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

bool SimHandeler::hasBreakPoints() const
{
    return hasBreakpoints;
}

void SimHandeler::clearBreakpoints()
{
    hasBreakpoints = false;
    breakpoints.clear();
}

Symulator *SimHandeler::getSymulator() const
{
    return symulator.get();
}

unsigned char *SimHandeler::getCompiled() const
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

void SimHandeler::setInputLine(QLineEdit *lineEdit)
{
    this->inputLine = lineEdit;
}
void SimHandeler::run()
{
    sr = new SimRunner(this);
    connect(sr, &SimRunner::outReady, this, &SimHandeler::printText);
    connect(sr, &SimRunner::stateChanged, this, &SimHandeler::registersChanged);
    connect(this, &SimHandeler::inputToSim, sr, &SimRunner::input);
    connect(sr, &SimRunner::inputOut, this, &SimHandeler::inputOut);
    connect(this, &SimHandeler::getMemoryFromSim, sr, &SimRunner::getMemoryFromSim);
    connect(this, &SimHandeler::simContinue, sr, &SimRunner::breakpointContinue);
    connect(sr, &SimRunner::breakpointStop, this, &SimHandeler::breakpointCodeLocation);
    connect(sr, &SimRunner::memoryChanged, this, [&](QString memory, int size){emit memoryChanged(memory, size);});
    connect(this, &SimHandeler::memoryChangedByUserSignal, sr, &SimRunner::memoryChangedByUser);
    connect(this, &SimHandeler::changeRegisters, sr, &SimRunner::changeRegisters);
    connect(sr, &SimRunner::screenSetPixel, this, &SimHandeler::screenSetPixel);
    sr->setFullSpeed(simFullSpeed);
    sr->setSymulator(this->symulator.get());
    sr->setBreakPoints(breakpointsLocations);
    sr->setLineAddrInsts(lineAddrInsts);
    if(!inputLine->text().isEmpty())
        sr->input((char)inputLine->text().toStdString()[0]);
    sr->start();
}
QString SimHandeler::memoryToString() const
{
    QString mem = "";
    if(symulator)
        for(int i = 0; i<symulator->getMemSize(); i++)
        {
            mem += QChar(symulator->getMemory()[i]);
        }
    return mem;
}

void SimHandeler::printText(const QString &text)
{
    textScreenWidget->appendText(text);
}

void SimHandeler::registersChanged(const Globals::SimStatus &status)
{
    emit displayRegisters(status.areg, status.breg, status.creg, status.dreg, status.ereg, status.hreg, status.lreg, status.mreg, status.pc, status.cf,
                          status.sf, status.pf, status.zf, status.acf, status.sp);
    emit setRegisterValues(status.areg, status.breg, status.creg, status.dreg, status.ereg, status.hreg, status.lreg, status.pc, status.sp);
}

void SimHandeler::inputOut(char ch)
{
    if(inputLine) ch == 0x0 ? inputLine->clear() : inputLine->setText(QChar(ch));
}

void SimHandeler::breakpointCodeLocation(int line, unsigned short address)
{
    for(const auto& i : std::as_const(fileMemoryRanges))
    {
        if(address >= i.start && address <= i.end)
        {
            emit breakpointHighlightLine(i.fileName, line);
            break;
        }
    }
}

void SimHandeler::memoryChangedByUser(QString &memory, int size)
{
    if(sr)
    {
        emit memoryChangedByUserSignal(memory, size);
    }
    else
    {
        if(size == symulator->getMemSize() && !memory.isEmpty())
        {
            int index = 0;
            for(const auto& i : std::as_const(memory))
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
    if(compcode)
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
    if(compcode && compcodeSize > 0)
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
    this->symulator->setHLTType(Symulator::SetHTLFlag);
    symulator->nextInst();
    textScreenWidget->appendText(QChar(symulator->getOutBuffer()));
    symulator->setOutBuffer('\0');
    if(inputLine) symulator->getInBuffer() == 0x0 ? inputLine->clear() : inputLine->setText(QChar(symulator->getInBuffer()));
    updateRegistersLabels();
    emit memoryChanged(memoryToString(), symulator->getMemSize());
    QString fName;
    for(const auto& i : std::as_const(fileMemoryRanges))
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

void SimHandeler::setTextScreen(TextScreenWidget *screen)
{
    textScreenWidget = screen;
}
void SimHandeler::reset()
{
    if(sr)
    {
        sr->requestInterruption();
        sr->wait();
        sr->deleteLater();
        sr = nullptr;
    }
    textScreenWidget->clear();
    symulator.reset();
    this->symulator = std::make_unique<Symulator>(Ssettings::memSize);
    this->symulator->setPC(Ssettings::memStart);
    this->symulator->setSP(Ssettings::sp);
    if(inputLine) inputLine->clear();
    updateRegistersLabels();
    emit memoryChanged(memoryToString(), symulator->getMemSize());
}

void SimHandeler::restart()
{
    if(sr)
    {
        sr->requestInterruption();
        sr->wait();
        sr->deleteLater();
        sr = nullptr;
    }
    textScreenWidget->clear();
    symulator->setHLT(false);
    symulator->setPC(Ssettings::memStart);
    if(inputLine) inputLine->clear();
    updateRegistersLabels();
}

void SimHandeler::input(const QString &input)
{
    symulator->setInBuffer((char) input.toStdString()[0]);
    emit inputToSim((char)input.toStdString()[0]);
}
unsigned char* SimHandeler::getMemory()
{
    unsigned char* memory;
    if(sr)
    {
        memory = emit getMemoryFromSim();
    }
    else
    {
        memory = symulator->getMemory();
    }
    return memory;
}

bool SimHandeler::isProjectLoaded() const
{
    return projectLoaded;
}
