#include "mainwindow.h"
#include "editor/codeeditor.h"
#include "dialogs/createprojectwindow.h"
#include "qprocess.h"
#include "utils/git/commitdialog.h"
#include "utils/git/gitdialog.h"
#include "utils/memorywindow.h"
#include "widgets/projectglobalsearchwidget.h"
#include "qfilesystemmodel.h"
#include "qmessagebox.h"
#include "dialogs/savewarningdialog.h"
#include "dialogs/settings.h"
#include "ui_mainwindow.h"
#include "simhandeler.h"
#include "widgets/starttabwidget.h"
#include "utils/calcdialog.h"
#include "utils/git/customgitcommanddialog.h"
#include "utils/git/gitbranchdialog.h"
#include "utils/git/gitfetchdialog.h"
#include "utils/git/gitpulldialog.h"
#include "utils/git/gitpushdialog.h"
#include "utils/instinmemorydialog.h"
#include "utils/numberconverterdialog.h"
#include "utils/stringtablegeneratordialog.h"
#include "utils/tabledatageneratordialog.h"
#include "widgets/helpwidget.h"
#include <fstream>
#include <QMimeData>
#include <QSettings>
#include <QStyleFactory>
#include "idesettings.h"
#include <widgets/searchwidget.h>
#include <QPrinter>
#include <QPrintDialog>

#define VERSION "1.0.0"
#define LICENSELINK "https://www.gnu.org/licenses/gpl-3.0.html"
#define REPOLINK "https://github.com/N1vn0vem8er/8080ide"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    simHandeler = new SimHandeler(ui->screen);
    simHandeler->setProjectNameLabel(ui->projectInfoLabel);
    simHandeler->setProjectGitBranchNameLabel(ui->projectGitBranchLabel);
    simHandeler->setInputLine(ui->simulatorInput);
    connect(ui->run_button, &QPushButton::released, this, &MainWindow::b_run);
    connect(ui->actionCompile, &QAction::triggered, this, &MainWindow::b_compile);
    connect(ui->c_button, &QPushButton::released, this, &MainWindow::b_compile);
    connect(ui->actionLoad, &QAction::triggered, this, &MainWindow::b_load);
    connect(ui->actionRun, &QAction::triggered, this, &MainWindow::b_run);
    connect(ui->actionReset, &QAction::triggered, this, &MainWindow::b_reset);
    connect(ui->clr_button, &QPushButton::released, this, &MainWindow::b_clr);
    connect(ui->actionRestart, &QAction::triggered, this, &MainWindow::b_restart);
    connect(ui->nextstep_button, &QPushButton::released, this, &MainWindow::b_next);
    connect(ui->restert_button, &QPushButton::released, this, &MainWindow::b_reset);
    connect(ui->actionPami, &QAction::triggered, this, &MainWindow::showMemory);
    connect(ui->cl_button, &QPushButton::released, this, &MainWindow::b_cl);
    connect(ui->actionOtw, &QAction::triggered, this, &MainWindow::open);
    connect(ui->actionNowy, &QAction::triggered, this, &MainWindow::newFile);
    connect(ui->actionZapisz, &QAction::triggered, this, qOverload<>(&MainWindow::save));
    connect(ui->actionZapisz_jako, &QAction::triggered, this, &MainWindow::saveas);
    connect(ui->actionZamknij, &QAction::triggered, this, &MainWindow::quit);
    connect(ui->actionOpcje, &QAction::triggered, this, &MainWindow::settings);
    connect(ui->tabWidget, &QTabWidget::tabCloseRequested, this, &MainWindow::closeTab);
    connect(ui->actionClose_Tab, &QAction::triggered, this, [&]{closeTab(ui->tabWidget->currentIndex());});
    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &MainWindow::tabChanged);
    simHandeler->setReferencesToRegisters(ui->Areg, ui->Breg, ui->Creg, ui->Dreg, ui->Ereg, ui->Hreg, ui->Lreg, ui->Mreg, ui->PC, ui->Flagsreg, ui->SPreg);
    connect(ui->actionUndo, &QAction::triggered, this, &MainWindow::undo);
    connect(ui->actionRedo, &QAction::triggered, this, &MainWindow::redo);
    connect(ui->actionOpenDir, &QAction::triggered, this, &MainWindow::openDirPressed);
    connect(ui->actionOpenProject, &QAction::triggered, this, qOverload<>(&MainWindow::openProject));
    connect(ui->actionnewProject, &QAction::triggered, this, &MainWindow::openNewProjectWindow);
    connect(ui->actionCloseProject, &QAction::triggered, this, &MainWindow::closeProject);
    connect(ui->actionGitCommit, &QAction::triggered, this, &MainWindow::openCommitDialog);
    connect(ui->actionGitLog, &QAction::triggered, this, &MainWindow::openLogDialog);
    connect(ui->actionGitStatus, &QAction::triggered, this, &MainWindow::openStatusDialog);
    connect(ui->inputButton, &QPushButton::released, this, &MainWindow::b_input);
    connect(ui->actionGitDiff, &QAction::triggered, this, &MainWindow::openDiffDialog);
    connect(ui->actionComment, &QAction::triggered, this, &MainWindow::commentLine);
    connect(ui->actionStartPage, &QAction::triggered, this, &MainWindow::openStartTabWidget);
    connect(ui->openLogsOutputButtom, &QPushButton::released, this, &MainWindow::loadLogs);
    connect(ui->simulatorButton, &QPushButton::released, this, &MainWindow::hideSimulator);
    connect(ui->actionShowSim, &QAction::triggered, this, &MainWindow::hideSimulator);
    connect(ui->actionShowFiles, &QAction::triggered, this, &MainWindow::showFileSystemTree);
    connect(ui->actionEnableSyntaxHighLighting, &QAction::triggered, this, &MainWindow::enableSyntaxHighLinhting);
    connect(ui->actionSpellcheck, &QAction::triggered, this, &MainWindow::enableSpellCheck);
    connect(ui->actionSearch, &QAction::triggered, this, &MainWindow::showSearch);
    connect(ui->searchWidget, &SearchWidget::searchFieldChanged, this, &MainWindow::search);
    connect(ui->searchWidget, &SearchWidget::replaceFieldChanged, this, &MainWindow::replace);
    connect(ui->actionProjectSearch, &QAction::triggered, this, &MainWindow::openProjectSearch);
    connect(ui->actionSetBreakpoint, &QAction::triggered, this, &MainWindow::setBreakpoint);
    connect(ui->continueButton, &QPushButton::clicked, simHandeler, &SimHandeler::breakpointContinue);
    connect(ui->continueButton, &QPushButton::clicked, simHandeler, [&](){if(highlightedEditor!=nullptr)highlightedEditor->clearSearchFormatting(); highlightedEditor = nullptr;});
    connect(simHandeler, &SimHandeler::stepLineHighlight, this, &MainWindow::stepLineHighLight);
    connect(ui->actionOpenHexConverter, &QAction::triggered, this, &MainWindow::openNumberConverterDialog);
    connect(ui->actionOpenCalc, &QAction::triggered, this, &MainWindow::openCalc);
    connect(ui->actionStringGenerator, &QAction::triggered, this, &MainWindow::openStringGenerator);
    connect(ui->actionTable_DATA, &QAction::triggered, this, &MainWindow::openTableDataGenerator);
    connect(ui->actionOpenInstInMemoryCounter, &QAction::triggered, this, &MainWindow::openLineToNumber);
    connect(simHandeler, &SimHandeler::breakpointHighlightLine, this, &MainWindow::highlightLine);
    connect(ui->actionGitBranch, &QAction::triggered, this, &MainWindow::openGitBranchDialog);
    connect(ui->actionGitFetch, &QAction::triggered, this, &MainWindow::openGitFetch);
    connect(ui->actionGitPull, &QAction::triggered, this, &MainWindow::openGitPull);
    connect(ui->actionGitPush, &QAction::triggered, this, &MainWindow::openGitPush);
    connect(ui->actionManualRun, &QAction::triggered, this, &MainWindow::openGitCommandDialog);
    connect(ui->actionAboutApplication, &QAction::triggered, this, &MainWindow::openAboutDialog);
    connect(ui->actionAboutQt, &QAction::triggered, this, [&](){QMessageBox::aboutQt(this, tr("About Qt"));});
    connect(ui->actionGetHelp, &QAction::triggered, this, &MainWindow::openHelp);
    connect(ui->converterButton, &QPushButton::clicked, this, [&](){ui->numConverter->setVisible(ui->numConverter->isVisible() ? false : true);});
    connect(ui->editRegistersButton, &QPushButton::clicked, this, &MainWindow::showHideRegistersEditor);
    connect(ui->registersEditor, &RegistersEditor::changeRegisters, simHandeler, &SimHandeler::changedRegisters);
    connect(simHandeler, &SimHandeler::setRegisterValues, ui->registersEditor, &RegistersEditor::setRegisterValues);
    connect(ui->treeView, &FileSystemTree::openFile, this, &MainWindow::openFileInNewTab);
    connect(ui->actionCut, &QAction::triggered, this, &MainWindow::cut);
    connect(ui->actionCopy, &QAction::triggered, this, &MainWindow::copy);
    connect(ui->actionPaste, &QAction::triggered, this, &MainWindow::paste);
    connect(ui->actionPaste_from_file, &QAction::triggered, this, &MainWindow::openPasteFromFile);
    connect(ui->actionPrint, &QAction::triggered, this, &MainWindow::openPrint);
    connect(ui->actionMerge_lines, &QAction::triggered, this, &MainWindow::mergeLines);
    connect(ui->actionRead_only, &QAction::triggered, this, &MainWindow::readOnlyChanget);
    connect(ui->actionLine_wrap, &QAction::triggered, this, &MainWindow::setLineWrap);
    connect(ui->actionSelect_All, &QAction::triggered, this, &MainWindow::selectAll);
    connect(ui->actionClose, &QAction::triggered, this, [&]{closeTab(ui->tabWidget->currentIndex());});
    connect(ui->actionClose_All, &QAction::triggered, this, [&]{while(ui->tabWidget->count() > 0) closeTab(ui->tabWidget->currentIndex());});
    connect(ui->actionClose_all_but_this, &QAction::triggered, this, &MainWindow::closeAllButThis);
    connect(ui->actionReload, &QAction::triggered, this, &MainWindow::reloadCurrent);
    connect(ui->actionReload_all, &QAction::triggered, this, &MainWindow::reloadAll);
    connect(ui->actionIncrease_font_size, &QAction::triggered, this, &MainWindow::increaseFontSize);
    connect(ui->actionDecrease_font_size, &QAction::triggered, this, &MainWindow::decreaseFontSize);
    connect(ui->actionReset_font_size, &QAction::triggered, this, &MainWindow::resetFontSize);
    connect(ui->actionSet_font_size, &QAction::triggered, this, &MainWindow::setFontSize);
    connect(ui->actionOverwrite_mode, &QAction::triggered, this, &MainWindow::overwriteModeChanged);
    connect(ui->actionDelete, &QAction::triggered, this, &MainWindow::deleteSelected);
    connect(ui->actionDelete_all, &QAction::triggered, this, &MainWindow::deleteAll);
    connect(ui->actionShowGit, &QAction::triggered, this, &MainWindow::showGitWidget);
    connect(ui->gitWidget, &GitWidget::addTab, this, &MainWindow::addTab);
    connect(ui->gitWidget, &GitWidget::openInEditor, this, &MainWindow::openInEditor);


    newFileLoaded = false;
    ui->treeView->open(QDir::homePath());
    simHandeler->setLogsOutput(ui->logsOutputWidget);

    ui->registersEditor->setVisible(false);

    ui->splitter->setStretchFactor(1, 3);
    ui->splitter_2->setStretchFactor(0, 2);

    setAcceptDrops(true);
    loadSettings();
    setStyleFromSettings();

    ui->stackedWidget->setVisible(false);
    ui->statusbar->setVisible(false);
    ui->searchWidget->setVisible(false);
    if(IDESettings::startupWidgetsVisibitity.startPage == IDESettings::show)
        openStartTabWidget();
    if(IDESettings::startupWidgetsVisibitity.diagnostics == IDESettings::hide)
        ui->logsOutputWidget->setVisible(false);
    if(IDESettings::startupWidgetsVisibitity.simulator == IDESettings::hide)
        ui->simLayout->setVisible(false);
    if(IDESettings::startupWidgetsVisibitity.converter == IDESettings::hide)
        ui->numConverter->setVisible(false);
}

void MainWindow::b_run()
{
    if(ui->tabWidget->count() == 0 && !simHandeler->isProjectLoaded())
        return;
    simHandeler->run();
}
void MainWindow::b_load()
{
    if(ui->tabWidget->count() > 0 && !simHandeler->isProjectLoaded())
    {
        simHandeler->updateCode(getPlainTextFromTab(ui->tabWidget->currentIndex()));
    }
    simHandeler->load();
}
void MainWindow::b_compile()
{
    if(ui->tabWidget->count() > 0 && !simHandeler->isProjectLoaded())
    {
        simHandeler->updateCode(getPlainTextFromTab(ui->tabWidget->currentIndex()));
        CodeEditor* ce = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
        if(ce != nullptr)
        {
            if(ce->hasBreakPoints())
                simHandeler->readBreakPoints(ce->getBreakPoints());
            else if(simHandeler->hasBreakPoints())
                simHandeler->clearBreakpoints();
        }
    }
    if(simHandeler->isProjectLoaded())
    {
        std::vector<std::pair<QString, std::vector<int>>> bp;
        for(int i=0;i<ui->tabWidget->count();i++)
        {
            CodeEditor* ce = dynamic_cast<CodeEditor*>(ui->tabWidget->widget(i));
            if(ce != nullptr && ce->hasBreakPoints())
            {
                std::vector<int> lines;
                const auto bps = ce->getBreakPoints();
                for(const auto& i : bps)
                {
                    lines.push_back(i);
                }
                bp.push_back(std::make_pair(ce->getFilePath(), lines));
            }
        }
        simHandeler->setFileBreakpoints(bp);
    }
    simHandeler->compile();
}
void MainWindow::b_clr()
{
    b_compile();
    b_load();
    b_run();
}
void MainWindow::b_next()
{
    simHandeler->next();
}
void MainWindow::b_reset()
{
    simHandeler->reset();
    for(int i=0;i<ui->tabWidget->count();i++)
    {
        CodeEditor* ce = dynamic_cast<CodeEditor*>(ui->tabWidget->widget(i));
        if(ce != nullptr)
        {
            ce->clearSearchFormatting();
        }
    }
}
void MainWindow::b_cl()
{
    b_compile();
    b_load();
}

void MainWindow::b_input()
{
    simHandeler->input(ui->simulatorInput->text());
}

void MainWindow::b_restart()
{
    simHandeler->restart();
}
void MainWindow::showMemory()
{
    MemoryWindow* w = new MemoryWindow(this);
    w->setAttribute(Qt::WA_DeleteOnClose);
    w->updateMemory(simHandeler->memoryToString(), simHandeler->getSimMemorySize());
    connect(simHandeler, &SimHandeler::memoryChanged, w, &MemoryWindow::updateMemory);
    connect(w, &MemoryWindow::changedMemory, simHandeler, &SimHandeler::memoryChangedByUser);
    w->show();
}
void MainWindow::settings()
{
    Settings* s = new Settings();
    s->setAttribute(Qt::WA_DeleteOnClose);
    s->show();
}
void MainWindow::openNewProjectWindow()
{
    CreateProjectWindow w = CreateProjectWindow();
    if(w.exec() == QDialog::Accepted)
    {
        QString path = w.getProjectConfigPath();
        if(path!="")
        {
            simHandeler->openProject(path);
            QFileInfo info(path);
            openDir(info.dir().path());
            showFileSystemTree();
            saveProjectToRecentProjects(path);
        }
    }
}

void MainWindow::commentLine()
{
    CodeEditor* ce = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(ce != nullptr)
        ce->commentCurrentLine();
}

void MainWindow::openStartTabWidget()
{
    StartTabWidget* widget = new StartTabWidget();
    connect(widget, &StartTabWidget::linkActivated, this, &MainWindow::handleStartTabLinks);
    connect(widget, &StartTabWidget::openFileFromPath, this, &MainWindow::openFileInNewTab);
    connect(widget, &StartTabWidget::openProjectFromPath, simHandeler, [this](const QString& path){openProject(path);});
    addTab(widget, "Start");
}

void MainWindow::handleStartTabLinks(const QString &link)
{
    if(link == "openFile")
        this->open();
    else
        if(link == "newFile")
        this->newFile();
    else
        if(link == "openProject")
        this->openProject();
    else
        if(link == "createProject")
        this->openNewProjectWindow();
}

void MainWindow::saveFileToRecentFiles(const QString &filePath)
{
    QString path = QDir::homePath() + "/.ide8080ide.recentfiles";
    if(std::filesystem::exists(path.toStdString()))
    {
        std::fstream file(path.toStdString(), std::ios_base::app | std::ios_base::in);
        if(file.is_open())
        {
            if(!pathExists(filePath.toStdString(), file))
                file << filePath.toStdString() + '\n';
            file.close();
        }
    }
    else
    {
        std::fstream file(path.toStdString(), std::ios_base::out);
        if(file.is_open())
        {
            file << filePath.toStdString() + '\n';
            file.close();
        }
    }
}

void MainWindow::saveProjectToRecentProjects(const QString &projectPath)
{
    QString path = QDir::homePath() + "/.ide8080ide.recentprojects";
    if(std::filesystem::exists(path.toStdString()))
    {
        std::fstream file(path.toStdString(), std::ios_base::app | std::ios_base::in);
        if(file.is_open())
        {
            if(!pathExists(projectPath.toStdString(), file))
                file << projectPath.toStdString() + '\n';
            file.close();
        }
    }
    else
    {
        std::fstream file(path.toStdString(), std::ios_base::out);
        if(file.is_open())
        {
            file << projectPath.toStdString() + '\n';
            file.close();
        }
    }
}

bool MainWindow::pathExists(std::string path, std::fstream& file)
{
    if(file.is_open())
    {
        while(!file.eof())
        {
            std::string line;
            getline(file, line);
            if(line == path)
            {
                file.clear();
                file.seekg(0);
                return true;
            }
        }
        file.clear();
        file.seekg(0);
    }
    return false;
}

void MainWindow::loadLogs()
{
    if(ui->logsOutputWidget->isVisible())
        ui->logsOutputWidget->setVisible(false);
    else
        ui->logsOutputWidget->setVisible(true);
}

void MainWindow::hideSimulator()
{
    if(ui->simLayout->isVisible())
        ui->simLayout->setVisible(false);
    else
        ui->simLayout->setVisible(true);
}

void MainWindow::showFileSystemTree()
{
    ui->stackedWidget->setVisible(ui->stackedWidget->currentIndex() == 0 && ui->stackedWidget->isVisible() ? false : true);
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::showGitWidget()
{
    ui->stackedWidget->setVisible(ui->stackedWidget->currentIndex() == 1 && ui->stackedWidget->isVisible() ? false : true);
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::openInEditor(const QString &text, const QString &title, bool readOnly, bool spellChecking)
{
    CodeEditor* editor = new CodeEditor(ui->tabWidget);
    connect(editor, &CodeEditor::fontSizeChanged, this, &MainWindow::fontSizeChanged);
    editor->setReadOnly(readOnly);
    editor->setSpellCheckEnabled(spellChecking);
    ui->actionOverwrite_mode->setChecked(editor->overwriteMode());
    ui->actionRead_only->setChecked(editor->isReadOnly());
    ui->actionLine_wrap->setChecked(editor->lineWrapMode() == CodeEditor::NoWrap ? false : true);
    editor->appendPlainText(text);
    addTab(editor, title);
}

void MainWindow::enableSyntaxHighLinhting()
{
    CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(tmp != nullptr)
    {
        if(tmp->isHighlighterEnabled())
        {
            tmp->setHighlighterEnabled(true);
        }
        else
        {
            tmp->setHighlighterEnabled(false);
        }
    }
}

void MainWindow::search(const QString &text)
{
    CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(tmp != nullptr)
    {
        tmp->highlightTextSequence(text);
    }
}

void MainWindow::replace(const QString &text)
{
    CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(tmp != nullptr)
    {
        tmp->replaceTextSequence(ui->searchWidget->getSearchFieldText(), text);
    }
}

void MainWindow::enableSpellCheck()
{
    CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(tmp != nullptr)
    {
        tmp->setSpellCheckEnabled(tmp->isSpellcheckEnabled() ? false : true);
    }
}

void MainWindow::openProjectSearch()
{
    if(simHandeler->isProjectLoaded())
    {
        addTab(new ProjectGlobalSearchWidget(simHandeler->getProjectPath()), simHandeler->getProjectName());
    }
}

void MainWindow::setBreakpoint()
{
    CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(tmp != nullptr)
    {
        tmp->setLineBreakpoint();
    }
}

void MainWindow::openNumberConverterDialog()
{
    NumberConverterDialog* dialog = new NumberConverterDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::openCalc()
{
    CalcDialog* dialog = new CalcDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::openStringGenerator()
{
    StringTableGeneratorDialog* dialog = new StringTableGeneratorDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::openTableDataGenerator()
{
    TableDataGeneratorDialog* dialog = new TableDataGeneratorDialog(this);
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    dialog->show();
}

void MainWindow::openLineToNumber()
{
    CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(tmp != nullptr)
    {
        InstInMemoryDialog* dialog = new InstInMemoryDialog(this);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->setText(tmp->toPlainText());
        dialog->show();
    }
    else
    {
        QMessageBox::information(this, tr("Information"), tr("Open file to use this feature"));
    }
}

void MainWindow::openProjectInformationPopup()
{
    QMessageBox::information(this, tr("Information"), tr("Open project to use this feature"));
}

void MainWindow::openProjectInformationDialog()
{

}

void MainWindow::highlightLine(QString file, int line)
{
    if(simHandeler->isProjectLoaded())
    {
        for(int i = 0; i<ui->tabWidget->count(); i++)
        {
            CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->widget(i));
            if(tmp != nullptr)
            {
                if(tmp->getFilePath() == file)
                {
                    ui->tabWidget->setCurrentIndex(i);
                    tmp->highlightLine(line);
                    highlightedEditor = tmp;
                    break;
                }
            }
        }
    }
    else
    {
        CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
        if(tmp != nullptr)
        {
            tmp->highlightLine(line);
            highlightedEditor = tmp;
        }
    }
}

void MainWindow::stepLineHighLight(const QString &file, int line)
{
    if(simHandeler->isProjectLoaded())
    {
        for(int i = 0; i<ui->tabWidget->count(); i++)
        {
            CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->widget(i));
            if(tmp != nullptr)
            {
                if(tmp->getFilePath() == file)
                {
                    ui->tabWidget->setCurrentIndex(i);
                    tmp->stepLineHightlight(line);
                    stepHighlightedEditor = tmp;
                    break;
                }
            }
        }
    }
    else
    {
        CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
        if(tmp != nullptr)
        {
            tmp->stepLineHightlight(line);
            stepHighlightedEditor = tmp;
        }
    }
}

void MainWindow::loadSettings()
{
    IDESettings s;
    s.loadSettings();
}

void MainWindow::setStyleFromSettings()
{
    if(QStyleFactory::keys().contains(IDESettings::theme))
    {
        QApplication::setStyle(IDESettings::theme);
    }
}

void MainWindow::showHideRegistersEditor()
{
    ui->registersEditor->setVisible(!ui->registersEditor->isVisible());
    if(ui->registersEditor->isVisible())
    {
        ui->editRegistersButton->setText(tr("Hide editor"));
        ui->Lreg->setVisible(false);
        ui->Hreg->setVisible(false);
        ui->Areg->setVisible(false);
        ui->Breg->setVisible(false);
        ui->Creg->setVisible(false);
        ui->Dreg->setVisible(false);
        ui->Ereg->setVisible(false);
        ui->Mreg->setVisible(false);
        ui->PC->setVisible(false);
        ui->SPreg->setVisible(false);
        ui->Flagsreg->setVisible(false);
    }
    else
    {
        ui->editRegistersButton->setText(tr("Edit registers"));
        ui->Lreg->setVisible(true);
        ui->Hreg->setVisible(true);
        ui->Areg->setVisible(true);
        ui->Breg->setVisible(true);
        ui->Creg->setVisible(true);
        ui->Dreg->setVisible(true);
        ui->Ereg->setVisible(true);
        ui->Mreg->setVisible(true);
        ui->PC->setVisible(true);
        ui->SPreg->setVisible(true);
        ui->Flagsreg->setVisible(true);
    }
}

void MainWindow::dropEvent(QDropEvent *event)
{
    const QMimeData* mimeData = event->mimeData();
    if(mimeData->hasUrls())
    {
        QList<QUrl> urls = mimeData->urls();
        for (int i = 0; i < urls.size() && i < 32; i++)
        {
            openFileInNewTab(urls.at(i).toLocalFile());
        }
    }
}

void MainWindow::dragEnterEvent(QDragEnterEvent *event)
{
    event->acceptProposedAction();
}

void MainWindow::dragLeaveEvent(QDragLeaveEvent *event)
{
    event->accept();
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    for(int i = 0; i < ui->tabWidget->count(); i++)
    {
        CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->widget(i));
        if(tmp!=nullptr && !tmp->isSaved())
        {
            openSaveWarningDialog(tmp);
        }
    }
    QMainWindow::closeEvent(event);
}

void MainWindow::showSearch()
{
    if(ui->searchWidget->isVisible())
    {
        CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
        if(tmp != nullptr)
            tmp->clearSearchFormatting();
        ui->searchWidget->setVisible(false);
    }
    else
    {
        CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
        if(tmp != nullptr)
            tmp->highlightTextSequence(ui->searchWidget->getSearchFieldText());
        ui->searchWidget->setVisible(true);
    }
}
void MainWindow::newFile()
{
    CodeEditor* tmp = new CodeEditor(ui->tabWidget);
    connect(tmp, &CodeEditor::fontSizeChanged, this, &MainWindow::fontSizeChanged);
    ui->actionOverwrite_mode->setChecked(tmp->overwriteMode());
    ui->actionRead_only->setChecked(tmp->isReadOnly());
    ui->actionLine_wrap->setChecked(tmp->lineWrapMode() == CodeEditor::NoWrap ? false : true);
    addTab(tmp, "New File");
}
void MainWindow::openFromTree()
{
   QString path = ui->treeView->getSelectedItem(ui->treeView->selectionModel()->selectedIndexes()[0]);
   QFileInfo fi(path);
   if(fi.isFile())
    openFileInNewTab(path);
}
void MainWindow::openFileInNewTab(const QString &path)
{
   if(path != "")
   {
        try {
            std::ifstream file;
            file.open(path.toStdString());
            if(file.is_open())
            {
                QFileInfo info(path);
                std::stringstream ss;
                ss << file.rdbuf();
                file.close();
                CodeEditor* ce = new CodeEditor();
                connect(ce, &CodeEditor::fontSizeChanged, this, &MainWindow::fontSizeChanged);
                ce->setFilePath(path);
                simHandeler->setFilename(path);
                if(simHandeler->getProjectFilesPaths().contains(path))
                {
                    ce->setPartOfProject(true);
                    ce->setProjectPath(simHandeler->getProjectPath());
                }
                ce->insertPlainText(QString::fromStdString(ss.str()));
                addTab(ce, info.fileName());
                saveFileToRecentFiles(path);
            }
        } catch (...) {
        }
   }
}
void MainWindow::openCommitDialog()
{
    if(simHandeler->isProjectLoaded())
    {
        CommitDialog* dialog = new CommitDialog();
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->init(simHandeler->getProjectPath());
        dialog->show();
    }
    else
        openProjectInformationPopup();
}
void MainWindow::openLogDialog()
{
    if(simHandeler->isProjectLoaded())
    {
        GitDialog* dialog = new GitDialog();
        dialog->setupForLog(simHandeler->getProjectPath());
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();
    }
    else
        openProjectInformationPopup();
}

void MainWindow::openStatusDialog()
{
    if(simHandeler->isProjectLoaded())
    {
        GitDialog* dialog = new GitDialog();
        dialog->setupForStatus(simHandeler->getProjectPath());
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();
    }
    else
        openProjectInformationPopup();
}

void MainWindow::openDiffDialog()
{
    if(simHandeler->isProjectLoaded())
    {
        QWidget* ce = ui->tabWidget->currentWidget();
        CodeEditor* c = dynamic_cast<CodeEditor*>(ce);
        if(c != nullptr)
        {
            GitDialog* dialog = new GitDialog();
            dialog->setupForDiff(simHandeler->getProjectPath(), c->getFilePath());
            dialog->setAttribute(Qt::WA_DeleteOnClose);
            dialog->show();
        }
    }
    else
        openProjectInformationPopup();
}

void MainWindow::openGitFetch()
{
    if(simHandeler->isProjectLoaded())
    {
        GitFetchDialog* dialog = new GitFetchDialog(simHandeler->getProjectPath(), this);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();
    }
    else
        openProjectInformationPopup();
}

void MainWindow::openGitPull()
{
    if(simHandeler->isProjectLoaded())
    {
        GitPullDialog* dialog = new GitPullDialog(simHandeler->getProjectPath(), this);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();
    }
    else
        openProjectInformationPopup();
}

void MainWindow::openGitPush()
{
    if(simHandeler->isProjectLoaded())
    {
        GitPushDialog* dialog = new GitPushDialog(simHandeler->getProjectPath(), this);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();
    }
    else
        openProjectInformationPopup();
}

void MainWindow::openGitBranchDialog()
{
    if(simHandeler->isProjectLoaded())
    {
        GitBranchDialog* dialog = new GitBranchDialog(simHandeler->getProjectPath(), simHandeler->getGitBranches(), this);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        connect(dialog, &GitBranchDialog::setBranch, simHandeler, &SimHandeler::setBranch);
        dialog->show();
    }
    else
        openProjectInformationPopup();
}

void MainWindow::openGitCommandDialog()
{
    if(simHandeler->isProjectLoaded())
    {
        CustomGitCommandDialog* dialog = new CustomGitCommandDialog(simHandeler->getProjectPath(), this);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->show();
    }
    else
        openProjectInformationPopup();
}

void MainWindow::openAboutDialog()
{
    QMessageBox::about(this, tr("About Application"), tr(R"(
    <html>
        <body>
            <h2>8080 IDE</h2>
            <p>8080 IDE is an integrated development environment for 8080 microprocessor.</p>
            <p>The environment includes many tools to help with programming.</p>
            <p>Version: %1</p>
            <p>License: <a href="%2">GPL 3</a></p>
            <p><a href="%3">Repository</a></p>
        <body>
    </html>
)").arg(VERSION, LICENSELINK, REPOLINK));
}

void MainWindow::openHelp()
{
    if(ui->tabWidget->count() > 0)
    {
        CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
        if(tmp != nullptr)
        {
            QString instruction = tmp->getInstructionFromSelectedLine();
            if(!instruction.isEmpty())
            {
                openHelpPageInst(instruction);
            }
            else
            {
                openHelpPageGeneral();
            }
            return;
        }
    }
    openHelpPageGeneral();
}

void MainWindow::openHelpPageGeneral()
{
    if(IDESettings::showHelpTypeAny == IDESettings::tab)
    {
        HelpWidget* widget = new HelpWidget();
        addTab(widget, tr("Help"));
    }
    else
    {
        QDialog* dialog = new QDialog(this);
        HelpWidget* widget = new HelpWidget(dialog);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        QLayout* layout = new QHBoxLayout(dialog);
        layout->addWidget(widget);
        dialog->setLayout(layout);
        dialog->resize(IDESettings::showHelpDialogSize.first, IDESettings::showHelpDialogSize.second);
        dialog->show();
    }
}

void MainWindow::openHelpPageInst(const QString &instruction)
{
    if(IDESettings::showHelpTypeCode == IDESettings::tab)
    {
        HelpWidget* widget = new HelpWidget();
        widget->openHelp(instruction);
        addTab(widget, tr("Help"));
        ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
    }
    else
    {
        QDialog* dialog = new QDialog(this);
        HelpWidget* widget = new HelpWidget(dialog);
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        QLayout* layout = new QHBoxLayout(dialog);
        widget->openHelp(instruction);
        layout->addWidget(widget);
        dialog->setLayout(layout);
        dialog->resize(IDESettings::showHelpDialogSize.first, IDESettings::showHelpDialogSize.second);
        dialog->show();
    }
}

void MainWindow::save()
{
    CodeEditor* ce = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(ce != nullptr)
    {
        if(ce->getFilePath() == "")
            saveas();
        else
        {
            std::ofstream file;
            file.open(ce->getFilePath().toStdString());
            file << getStdStringFromTab(ui->tabWidget->currentIndex());
            file.close();
            saveFileToRecentFiles(ce->getFilePath());
            ce->setSaved(true);
        }
    }
}

void MainWindow::save(CodeEditor *editor)
{
    if(editor->getFilePath() == "")
        saveas();
    else
    {
        QFile file(editor->getFilePath());
        file.open(QIODevice::WriteOnly);
        if(file.isOpen())
        {
            file.write(editor->toPlainText().toLatin1());
            file.close();
            editor->setSaved(true);
        }
    }
}

void MainWindow::saveAs(CodeEditor *editor)
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save File As"), "./", tr("Files (*.asm)"));
    if(path != "")
    {
        if(QFileInfo(path).completeSuffix() == "asm")
            path+=".asm";
        QFile file(path);
        if(file.isOpen())
        {
            file.write(editor->toPlainText().toLatin1());
            file.close();
            editor->setSaved(true);
            editor->setFilePath(path);
            saveFileToRecentFiles(path);
        }
    }
}
void MainWindow::open()
{
    QStringList paths = QFileDialog::getOpenFileNames(this, tr("Open File"), "./", tr("Files (*.asm)"));
    for(const auto& path : std::as_const(paths))
    {
        openFileInNewTab(path);
    }
}
void MainWindow::openDirPressed()
{
    QString path = QFileDialog::getExistingDirectory(this, tr("Open Directory", "./"));
    if(path != "")
    {
        openDir(path);
        showFileSystemTree();
    }
}

void MainWindow::openDir(const QString &path)
{
    ui->treeView->open(path);
    QProcess process;
    process.setWorkingDirectory(path);
    process.startCommand("git status");
    process.waitForStarted();
    process.waitForFinished();
    process.waitForReadyRead();
    ui->treeView->setHasGitRepository(process.readAllStandardError().isEmpty());
    if(ui->treeView->getHasGitRepository())
    {
        ui->gitWidget->setRepositoryPath(path);
    }
}
void MainWindow::saveas()
{
    QString path = QFileDialog::getSaveFileName(this, tr("Save File As"), "./", tr("Files (*.asm)"));
    if(path != "")
    {
        std::ofstream file;
        if(QFileInfo(path).completeSuffix() == "asm")
            file.open(path.toStdString());
        else
            file.open(path.toStdString()+".asm");
        file << getStdStringFromTab(ui->tabWidget->currentIndex());
        file.close();
        saveFileToRecentFiles(path);
        CodeEditor* ce = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
        if(ce != nullptr)
        {
            ce->setFilePath(path);
            ce->setSaved(true);
        }
    }
}
void MainWindow::openProject()
{
    QString path = QFileDialog::getOpenFileName(this, tr("Open Project"), "./", tr("Files (*.config)"));
    if(path!="")
    {
        openProject(path);
    }
}

void MainWindow::openProject(const QString &path)
{
    if(path!="")
    {
        simHandeler->openProject(path);
        QFileInfo info(path);
        openDir(info.dir().absolutePath());
        showFileSystemTree();
        saveProjectToRecentProjects(path);
    }
}
void MainWindow::closeProject()
{
    simHandeler->closeProject();
    openDir(QDir::homePath());
}
void MainWindow::quit()
{
    qApp->exit();
}

void MainWindow::addTab(QWidget *widget, const QString &title)
{
    ui->tabWidget->addTab(widget, title);
    ui->tabWidget->setCurrentIndex(ui->tabWidget->count() - 1);
}
void MainWindow::closeTab(int index)
{
    QWidget* widget = ui->tabWidget->widget(index);
    CodeEditor* tmp = dynamic_cast<CodeEditor*>(widget);
    if(tmp!=nullptr && !tmp->isSaved())
    {
        SaveWarningDialog* dialog = new SaveWarningDialog();
        dialog->setAttribute(Qt::WA_DeleteOnClose);
        dialog->setFilePath(tmp->getFilePath());
        if(dialog->exec() == QDialog::Accepted)
        {
            save(tmp);
        }
    }

    ui->tabWidget->removeTab(index);
    delete widget;
}
void MainWindow::tabChanged()
{
    CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(tmp)
    {
        if(ui->searchWidget->isVisible())
        {
            tmp->highlightTextSequence(ui->searchWidget->getSearchFieldText());
        }
        else
        {
            tmp->clearSearchFormatting();
        }
        ui->actionOverwrite_mode->setChecked(tmp->overwriteMode());
        ui->actionRead_only->setChecked(tmp->isReadOnly());
        ui->actionLine_wrap->setChecked(tmp->lineWrapMode() == CodeEditor::NoWrap ? false : true);
        ui->fontSizeLabel->setText(tr("Font Size: %1").arg(tmp->font().pointSize()));
    }
    else
    {
        ui->fontSizeLabel->setText("");
    }
}
void MainWindow::undo()
{
    CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(tmp != nullptr)
        tmp->undo();
}
void MainWindow::redo()
{
    CodeEditor* tmp = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(tmp != nullptr)
        tmp->redo();
}
std::string MainWindow::getStdStringFromTab(int index)
{
    return getPlainTextFromTab(index).toStdString();
}
QString MainWindow::getPlainTextFromTab(int index)
{
    QWidget* ce = ui->tabWidget->widget(index);
    CodeEditor* c = dynamic_cast<CodeEditor*>(ce);
    if(c != nullptr)
        return c->toPlainText();
    else
        return "";
}

MainWindow::~MainWindow()
{
    delete ui;
    delete simHandeler;
}

void MainWindow::copy()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->copy();
    }
}

void MainWindow::selectAll()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->selectAll();
    }
}

void MainWindow::cut()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->cut();
    }
}

void MainWindow::paste()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->paste();
    }
}

void MainWindow::fontSizeChanged(int size)
{
    ui->fontSizeLabel->setText(tr("Font Size: %1").arg(size));
}

void MainWindow::openPasteFromFile()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        const QStringList paths = QFileDialog::getOpenFileNames(this, tr("Paste from file"), QDir::homePath());
        if(!paths.isEmpty())
        {
            for(const auto& path : paths)
            {
                QFile file(path);
                file.open(QIODevice::ReadOnly);
                if(file.isOpen())
                {
                    widget->appendPlainText(file.readAll());
                    file.close();
                }
            }
        }
    }
}

void MainWindow::setLineWrap(bool val)
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->setLineWrapMode(val ? CodeEditor::LineWrapMode::WidgetWidth : CodeEditor::LineWrapMode::NoWrap);
    }
}

void MainWindow::increaseFontSize()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->increaseFontSize();
    }
}

void MainWindow::decreaseFontSize()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->decreaseFontSize();
    }
}

void MainWindow::resetFontSize()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->setFontSize(10);
    }
}

void MainWindow::setFontSize()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        QDialog* dialog = new QDialog(this);
        QVBoxLayout* mainLayout = new QVBoxLayout(dialog);
        QLineEdit* lineEdit = new QLineEdit(dialog);
        lineEdit->setPlaceholderText(tr("Enter font size"));
        mainLayout->addWidget(lineEdit);
        QPushButton* okButton = new QPushButton(dialog);
        QPushButton* cancelButton = new QPushButton(dialog);
        QHBoxLayout* buttonsLayout = new QHBoxLayout();
        okButton->setText(tr("Ok"));
        cancelButton->setText(tr("Cancel"));
        buttonsLayout->addWidget(okButton);
        buttonsLayout->addWidget(cancelButton);
        mainLayout->addLayout(buttonsLayout);
        connect(okButton, &QPushButton::clicked, dialog, &QDialog::accept);
        connect(cancelButton, &QPushButton::clicked, dialog, &QDialog::reject);
        if(dialog->exec() == QDialog::Accepted)
        {
            widget->setFontSize(lineEdit->text().toInt());
        }
        delete buttonsLayout;
    }
}

void MainWindow::closeAllButThis()
{
    for(int i=ui->tabWidget->count()-1; i >= 0;--i)
    {
        if(i != ui->tabWidget->currentIndex())
            closeTab(i);
    }
}

void MainWindow::reloadCurrent()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget && !widget->getFilePath().isEmpty())
    {
        if(!widget->isSaved())
        {
            openSaveWarningDialog(widget);
        }
        QFile file(widget->getFilePath());
        file.open(QIODevice::ReadOnly);
        if(file.isOpen())
        {
            widget->setPlainText(file.readAll());
            file.close();
            widget->setSaved(true);
        }
    }
}

void MainWindow::reloadAll()
{
    for(int i=0; i<ui->tabWidget->count(); i++)
    {
        CodeEditor* editor = dynamic_cast<CodeEditor*>(ui->tabWidget->widget(i));
        if(editor != nullptr && !editor->getFilePath().isEmpty())
        {
            if(!editor->isSaved())
            {
                openSaveWarningDialog(editor);
            }
            QFile file(editor->getFilePath());
            file.open(QIODevice::ReadOnly);
            if(file.isOpen())
            {
                editor->setPlainText(file.readAll());
                file.close();
                editor->setSaved(true);
            }
        }
    }
}

void MainWindow::openPrint()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        QPrinter printer(QPrinter::HighResolution);
        QPrintDialog dialog(&printer, this);
        if(dialog.exec() == QDialog::Accepted)
        {
            widget->print(&printer);
        }
    }
}

void MainWindow::overwriteModeChanged(bool val)
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->setOverwriteMode(val);
    }
}

void MainWindow::readOnlyChanget(bool val)
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->setReadOnly(val);
    }
}

void MainWindow::mergeLines()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->mergeSelectedLines();
    }
}

void MainWindow::deleteSelected()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->deleteSelected();
    }
}

void MainWindow::deleteAll()
{
    CodeEditor* widget = dynamic_cast<CodeEditor*>(ui->tabWidget->currentWidget());
    if(widget)
    {
        widget->deleteAll();
    }
}

void MainWindow::openSaveWarningDialog(CodeEditor* editor)
{
    SaveWarningDialog* dialog = new SaveWarningDialog();
    dialog->setFilePath(editor->getFilePath());
    dialog->setAttribute(Qt::WA_DeleteOnClose);
    if(dialog->exec() == QDialog::Accepted)
    {
        save(editor);
    }
}

