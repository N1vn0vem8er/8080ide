#ifndef UIHANDELER_H
#define UIHANDELER_H
#include "projectmanager.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "qplaintextedit.h"
#include <string>
#include <sstream>
#include "8080/Symulator.h"
#include "qthread.h"
#include "simrunner.h"

class SimHandeler : public QObject
{
    Q_OBJECT
private:
    std::string code;
    QPlainTextEdit* screen;
    void printOnScreen(char text);
    void printOnScreen(const char* text);
    void clearScreen();
    void updateRegistersLabels();
    std::string tohexASCII(unsigned char ch);
    std::string tohexASCII(unsigned short ch);
    Symulator* symulator = nullptr;
    unsigned char* compcode = nullptr;
    int compcodeSize;
    QLabel* areg = nullptr;
    QLabel* breg = nullptr;
    QLabel* creg = nullptr;
    QLabel* dreg = nullptr;
    QLabel* ereg = nullptr;
    QLabel* hreg = nullptr;
    QLabel* lreg = nullptr;
    QLabel* mreg = nullptr;
    QLabel* pc = nullptr;
    QLabel* flags = nullptr;
    QLabel* sp = nullptr;
    QDialog* settingsWindow = nullptr;
    ProjectManager* projectManager = nullptr;
    bool projectLoaded;
    QLabel* projectNameLabel = nullptr;
    QLabel* projectGitBranchNameLabel = nullptr;
    void setBranchName();
    QThread simulatorThread;
    unsigned char* inputValue;
    SimRunner* sr = nullptr;
    QLineEdit* inputLine = nullptr;
    QPlainTextEdit* logsOutput = nullptr;
    void log(QString text);
    std::map<std::string, std::vector<int>> fileBreakpointsMap;
    std::vector<std::pair<unsigned short, int>> breakpointsLocations;
    std::vector<int> breakpoints;
    bool hasBreakpoints = false;
    QString filename;
    std::vector<std::pair<QString, std::vector<int>>> fileBreakpoints;
    QList<Globals::FileMemoryStartEnd> fileMemoryRanges;
    std::vector<std::pair<unsigned short, int>> lineAddrInsts;
public:
    enum RegistersIds{
        A,
        B,
        C,
        D,
        E,
        H,
        L,
        PC,
        SP
    };
    explicit SimHandeler(QPlainTextEdit* screen, QObject* parent = nullptr);
    ~SimHandeler();
    void setBranch(QString name);
    void setProjectNameLabel(QLabel* label);
    void setProjectGitBranchNameLabel(QLabel* label);
    void setInputLine(QLineEdit* lineEdit);
    void updateCode(const QString& code);
    void run();
    void compile();
    void load();
    void clr();
    void next();
    void setScreen(QPlainTextEdit& screen);
    void reset();
    void restart();
    void input(QString input);
    unsigned char *getMemory();
    void setReferencesToRegisters(QLabel* areg, QLabel* breg, QLabel* creg, QLabel* dreg, QLabel* ereg, QLabel* hreg, QLabel* lreg,  QLabel* mreg, QLabel* pc, QLabel* flags, QLabel *sp);
    void openProject(const QString& path);
    bool isProjectLoaded();
    void closeProject();
    void setLogsOutput(QPlainTextEdit* output);
    QString getProjectName();
    QStringList getProjectFilesPaths();
    QString getProjectPath();
    void readBreakPoints(QVector<int> breakpoints);
    void breakpointContinue();
    bool hasBreakPoints();
    void clearBreakpoints();
    Symulator* getSymulator();
    unsigned char* getCompiled();
    int getCompiledSize() const;
    int getSimMemorySize() const;
    QString getFilename() const;
    void setFilename(const QString &newFilename);
    void setFileBreakpoints(const std::vector<std::pair<QString, std::vector<int>>>& bp);
    QStringList getGitBranches();
    QString memoryToString();
signals:
    void startSim(Symulator* sim);
    void inputToSim(char in);
    unsigned char* getMemoryFromSim();
    void simContinue();
    void breakpointHighlightLine(QString file, int line);
    void stepLineHighlight(const QString& file, int line);
    void memoryChanged(QString memory, int size);
    void memoryChangedByUserSignal(QString memory, int size);
    void changeRegisters(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char h, unsigned char l, unsigned short pc, unsigned short sp);
    void setRegisterValues(const QString& a, const QString& b, const QString& c, const QString& d, const QString& e, const QString& h, const QString& l, const QString& PC, const QString& SP);
public slots:
    void print(char ch);
    void registersChanged(QStringList registers);
    void inputOut(char ch);
    void breakpointCodeLocation(int line, unsigned short address);
    void memoryChangedByUser(QString& memory, int size);
    void changedRegisters(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char h, unsigned char l, unsigned short pc, unsigned short sp);
};

#endif // UIHANDELER_H
