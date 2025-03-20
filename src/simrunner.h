#ifndef SIMRUNNER_H
#define SIMRUNNER_H

#include "8080/Symulator.h"
#include <QObject>
#include <QThread>

class SimRunner : public QThread
{
    Q_OBJECT
public:
    explicit SimRunner(QObject *parent = nullptr);
    ~SimRunner();
    void setSymulator(Symulator* sim);
    void setBreakPoints(std::vector<std::pair<unsigned short, int>> breakPoints);
    void setLineAddrInsts(const std::vector<std::pair<unsigned short, int> > &newLineAddrInsts);

private:
    QStringList getRegisterList(Symulator* sim);

    std::string tohexASCII(unsigned short ch);
    std::string tohexASCII(unsigned char ch);
    bool stopCalled;
    QStringList oldRegistersState;
    char oldInBuffer;
    Symulator* sim = nullptr;
    char inputBuffer;
    bool bpContinue;
    std::vector<std::pair<unsigned short, int>> breakpoints;
    std::vector<std::pair<unsigned short, int>> lineAddrInsts;
    QString memoryToString();
public slots:
    void input(char in);
    unsigned char* getMemoryFromSim();
    void breakpointContinue();
    void nextStep();
    void memoryChangedByUser(const QString& memory, int size);
    void changeRegisters(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char h, unsigned char l, unsigned short pc, unsigned short sp);

signals:
    void stateChanged(QStringList registers);
    void charOut(char ch);
    void inputOut(char ch);
    void breakpointStop(int line, unsigned short address);
    void memoryChanged(QString memory, int size);

protected:
    void run() override;
};

#endif // SIMRUNNER_H
