#ifndef UIHANDELER_H
#define UIHANDELER_H
#include "projectmanager.h"
#include "qlabel.h"
#include "qlineedit.h"
#include "qplaintextedit.h"
#include <string>
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
    QString tohexASCII(unsigned char ch) const;
    QString tohexASCII(unsigned short ch) const;
    std::unique_ptr<Symulator> symulator {nullptr};
    unsigned char* compcode = nullptr;
    int compcodeSize;
    QDialog* settingsWindow = nullptr;
    ProjectManager* projectManager = nullptr;
    bool projectLoaded;
    QLabel* projectNameLabel = nullptr;
    QThread simulatorThread;
    unsigned char* inputValue;
    SimRunner* sr = nullptr;
    QLineEdit* inputLine = nullptr;
    QPlainTextEdit* logsOutput = nullptr;
    void log(const QString& text);
    std::map<std::string, std::vector<int>> fileBreakpointsMap;
    std::vector<std::pair<unsigned short, int>> breakpointsLocations;
    std::vector<int> breakpoints;
    bool hasBreakpoints = false;
    QString filename;
    std::vector<std::pair<QString, std::vector<int>>> fileBreakpoints;
    QList<Globals::FileMemoryStartEnd> fileMemoryRanges;
    std::vector<std::pair<unsigned short, int>> lineAddrInsts;
public:
    explicit SimHandeler(QPlainTextEdit* screen, QObject* parent = nullptr);
    ~SimHandeler();
    void setProjectNameLabel(QLabel* label);
    void setInputLine(QLineEdit* lineEdit);
    void updateCode(const QString& code);
    void run();
    void compile();
    void load();
    void clr();
    void next();
    void setScreen(QPlainTextEdit* screen);
    void reset();
    void restart();
    void input(const QString& input);
    unsigned char *getMemory();
    void openProject(const QString& path);
    bool isProjectLoaded() const;
    void closeProject();
    void setLogsOutput(QPlainTextEdit* output);
    QString getProjectName() const;
    QStringList getProjectFilesPaths() const;
    QString getProjectPath() const;
    void readBreakPoints(QVector<int> breakpoints);
    void breakpointContinue();
    bool hasBreakPoints() const;
    void clearBreakpoints();
    Symulator* getSymulator() const;
    unsigned char* getCompiled() const;
    int getCompiledSize() const;
    int getSimMemorySize() const;
    QString getFilename() const;
    void setFilename(const QString &newFilename);
    void setFileBreakpoints(const std::vector<std::pair<QString, std::vector<int>>>& bp);
    QString memoryToString() const;
signals:
    void startSim(Symulator* sim);
    void inputToSim(char in);
    unsigned char* getMemoryFromSim();
    void simContinue();
    void breakpointHighlightLine(const QString& file, int line);
    void stepLineHighlight(const QString& file, int line);
    void memoryChanged(QString memory, int size);
    void memoryChangedByUserSignal(QString memory, int size);
    void changeRegisters(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char h, unsigned char l, unsigned short pc, unsigned short sp);
    void setRegisterValues(const QString& a, const QString& b, const QString& c, const QString& d, const QString& e, const QString& h, const QString& l, const QString& PC, const QString& SP);
    void displayRegisters(const QString &areg, const QString &breg, const QString &creg, const QString &dreg, const QString &ereg, const QString &hreg, const QString &lreg, const QString &mreg,
                          const QString &pc, const QString &cf, const QString &sf, const QString &pf, const QString &zf, const QString &acf, const QString &sp);

public slots:
    void print(char ch);
    void registersChanged(const Globals::SimStatus& status);
    void inputOut(char ch);
    void breakpointCodeLocation(int line, unsigned short address);
    void memoryChangedByUser(QString& memory, int size);
    void changedRegisters(unsigned char a, unsigned char b, unsigned char c, unsigned char d, unsigned char e, unsigned char h, unsigned char l, unsigned short pc, unsigned short sp);
};

#endif // UIHANDELER_H
