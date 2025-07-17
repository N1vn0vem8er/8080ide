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
    void save(CodeEditor* editor);
    void addTab(QWidget* widget, const QString& title);
    bool newFileLoaded;
    QLabel* projectInfoLabel {nullptr};
    std::string getStdStringFromTab(int index);
    QString getPlainTextFromTab(int index);
    void openProject(const QString& path);
    void saveFileToRecentFiles(const QString& filePath);
    void saveProjectToRecentProjects(const QString& projectPath);
    bool pathExists(std::string path, std::fstream &file);
    void loadSettings() const;
    void setStyleFromSettings();
    void openSaveWarningDialog(CodeEditor* editor);
    void openFailedToOpenDialog(const QString& path, const QString& errorMessage);
    void loadTerminalThemesMenu();
    void setTermTheme(const QString& name);
    inline bool isFilesOpen() const;
    inline bool isGitOpen() const;

private slots:
    void copy();
    void selectAll();
    void cut();
    void paste();
    void fontSizeChanged(int size);
    void openPasteFromFile();
    void setLineWrap(bool val);
    void increaseFontSize();
    void decreaseFontSize();
    void resetFontSize();
    void setFontSize();
    void closeAllButThis();
    void reloadCurrent();
    void reloadAll();
    void openPrint();
    void overwriteModeChanged(bool val);
    void readOnlyChanget(bool val);
    void mergeLines();
    void deleteSelected();
    void deleteAll();
    void hideSimulator();
    void showFileSystemTree();
    void showGitWidget();
    void showDiagnostics();
    void showTerminal();
    void openInEditor(const QString& text, const QString& title, bool readOnly = true, bool spellChecking = false, bool disableSaveWarning = false);
    void setCurrenctBranchName(const QString& name);
    void undo();
    void redo();
    void openFromTree();
    void openDirPressed();
    void openDir(const QString& path);
    void openFileInNewTab(const QString& path);
    void openGitLog();
    void openGitStatus();
    void openGitFetch();
    void openGitPull();
    void openGitPush();
    void openGitBranchDialog();
    void openGitCommandDialog();
    void openAboutDialog();
    void openHelp();
    void openHelpPageGeneral();
    void openHelpPageInst(const QString& instruction);
    void showHideRegistersEditor();
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
    void open();
    void saveas();
    void quit();
    void closeTab(int index);
    void tabChanged();
    void openProject();
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
    void closeProject();
    void openNewProjectWindow();
    void commentLine();
    void openStartTabWidget();
    void handleStartTabLinks(const QString& link);
    void goTop();
    void goBotton();
    void openTerminalSetFontSize();
    void showMessage(const QString& message);

protected:
    void dropEvent(QDropEvent* event) override;
    void dragEnterEvent(QDragEnterEvent* event) override;
    void dragLeaveEvent(QDragLeaveEvent* event) override;
    void closeEvent(QCloseEvent *event) override;

signals:
    void refreshStartTab();

};
#endif // MAINWINDOW_H
