#include "simrunner.h"
#include "qthread.h"
#include <sstream>

SimRunner::SimRunner(QObject *parent)
    : QThread{parent}
{
    stopCalled = false;
    inputBuffer = 0x0;
    oldInBuffer = 0x0;
}

SimRunner::~SimRunner()
{

}

void SimRunner::setSymulator(Symulator *sim)
{
    this->sim = sim;
}

void SimRunner::setBreakPoints(std::vector<std::pair<unsigned short, int>> breakPoints)
{
    breakpoints = breakPoints;
}

Globals::SimStatus SimRunner::getRegisterList(Symulator *sim)
{
    Globals::SimStatus status(tohexASCII(sim->getAreg()), tohexASCII(sim->getBreg()), tohexASCII(sim->getCreg()), tohexASCII(sim->getDreg()), tohexASCII(sim->getEreg()), tohexASCII(sim->getHreg()),
                              tohexASCII(sim->getLreg()), tohexASCII(sim->getPC()), tohexASCII(sim->getSP()), QString::number(sim->getCF()), QString::number(sim->getS())
                                ,QString::number(sim->getP()),QString::number(sim->getZ()),QString::number(sim->getAC()), tohexASCII(sim->getMreg()));
    return status;
}

QString SimRunner::tohexASCII(unsigned char ch) const
{
    std::stringstream ss;
    ss << std::hex << +ch;
    return QString::fromStdString(ss.str());
}

QString SimRunner::memoryToString() const
{
    QString mem = "";
    if(sim!=nullptr)
        for(int i = 0; i<sim->getMemSize(); i++)
        {
            mem += QChar(sim->getMemory()[i]);
        }
    return mem;
}

void SimRunner::setLineAddrInsts(const std::vector<std::pair<unsigned short, int> > &newLineAddrInsts)
{
    lineAddrInsts = newLineAddrInsts;
}
QString SimRunner::tohexASCII(unsigned short ch) const
{
    std::stringstream ss;
    ss << std::hex << +ch;
    return QString::fromStdString(ss.str());
}

void SimRunner::input(char in)
{
    inputBuffer = in;
}

unsigned char *SimRunner::getMemoryFromSim()
{
    return sim->getMemory();
}

void SimRunner::breakpointContinue()
{
    bpContinue = true;
}

void SimRunner::nextStep()
{

}

void SimRunner::memoryChangedByUser(const QString &memory, int size)
{
    if(size == sim->getMemSize() && !memory.isEmpty())
    {
        int index = 0;
        for(const auto& i : memory)
        {
            sim->getMemory()[index] = i.cell();
            index++;
        }
    }
}

void SimRunner::changeRegisters(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char h, unsigned char l, unsigned short pc, unsigned short sp)
{
    sim->setAreg(a);
    sim->setBreg(b);
    sim->setCreg(c);
    sim->setDreg(d);
    sim->setEreg(e);
    sim->setHreg(h);
    sim->setLreg(l);
    sim->setPC(pc);
    sim->setSP(sp);
    emit stateChanged(getRegisterList(sim));
}

void SimRunner::run()
{
    Globals::SimStatus registersState;
    if(sim != nullptr)
    {
        sim->setHLTType(Symulator::SetHTLFlag);
        while(!sim->getHLT() && sim->getPC() <= sim->getMemSize() && !QThread::currentThread()->isInterruptionRequested())
        {
            auto tmp = std::find_if(breakpoints.begin(), breakpoints.end(), [this](const std::pair<unsigned short, int>& element){return element.first == sim->getPC();});
            if(tmp != breakpoints.end())
            {
                bpContinue = false;
                emit breakpointStop(tmp->second, tmp->first);
                while(!bpContinue && !QThread::currentThread()->isInterruptionRequested()){}
            }
            if(inputBuffer!=0x0)
            {
                sim->setInBuffer(inputBuffer);
                inputBuffer = 0x0;
            }
            sim->nextInst();
            if(sim->getOutBuffer() != '\0')
                emit charOut(sim->getOutBuffer());
            sim->setOutBuffer('\0');
            if(!fullSpeed)
            {
                registersState = getRegisterList(sim);
                if(oldRegistersState != registersState)
                    emit stateChanged(registersState);
            }
            if(sim->getInBuffer() != oldInBuffer)
            {
                oldInBuffer = sim->getInBuffer();
                emit inputOut(oldInBuffer);
            }
            if(!sim->getScreenColorRead())
            {
                emit screenSetPixel(sim->getScreenX(), sim->getScreenY(), sim->getScreenColor(true));
            }
            emit memoryChanged(memoryToString(), sim->getMemSize());
            if(!fullSpeed) QThread::msleep(2);
        }
    }
}

