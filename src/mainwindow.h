#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "editor/codeeditor.h"
#include "simhandeler.h"
#include <QMainWindow>
#include <QFileDialog>
#include <fstream>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    SimHandeler* simHandeler;
    CodeEditor* highlightedEditor = nullptr;
    CodeEditor* stepHighlightedEditor = nullptr;
    void b_load();
    void b_compile();
    void b_clr();
    void b_next();
    void b_run();
    void b_reset();
    void b_cl();
    void b_input();
    void b_restart();
    void showMemory();
    void settings();
    void newFile();
    void save();
    void save(CodeEditor* editor);
    void saveAs(CodeEditor* editor);
    void open();
    void saveas();
    void quit();
    void closeTab(int index);
    int currentTabIndex;
    bool newFileLoaded;
    void tabChanged();
    void undo();
    void redo();
    void openFromTree();
    void openDir();
    void openFileInNewTab(QString path);
    void openCommitDialog();
    void openLogDialog();
    void openStatusDialog();
    void openDiffDialog();
    void openGitFetch();
    void openGitPull();
    void openGitPush();
    void openGitBranchDialog();
    void openGitCommandDialog();
    void openAboutDialog();
    void openHelp();
    void openHelpPageGeneral();
    void openHelpPageInst(const QString& instruction);
    std::string getStdStringFromTab(int index);
    QString getPlainTextFromTab(int index);
    void openProject();
    void openProject(const QString& path);
    void closeProject();
    void openNewProjectWindow();
    void commentLine();
    void openStartTabWidget();
    void handleStartTabLinks(const QString& link);
    void saveFileToRecentFiles(const QString& filePath);
    void saveProjectToRecentProjects(const QString& projectPath);
    bool pathExists(std::string path, std::fstream &file);
    void loadLogs();
    void hideSimulator();
    void hideFileSystemTree();
    void enableSyntaxHighLinhting();
    void showSearch();
    void search(const QString& text);
    void replace(const QString& text);
    void enableSpellCheck();
    void openProjectSearch();
    void setBreakpoint();
    void openNumberConverterDialog();
    void openCalc();
    void openStringGenerator();
    void openTableDataGenerator();
    void openLineToNumber();
    void openProjectInformationPopup();
    void openProjectInformationDialog();
    void highlightLine(QString file, int line);
    void stepLineHighLight(const QString& file, int line);
    void loadSettings();
    void setStyleFromSettings();
    void showHideRegistersEditor();
protected:
    void dropEvent(QDropEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragLeaveEvent(QDragLeaveEvent* event) override;

    // QWidget interface
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
