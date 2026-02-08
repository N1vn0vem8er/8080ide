#include "idesettings.h"
#include "qplaintextedit.h"
#include "qsettings.h"
#include "ssettings.h"

#include <QApplication>

#include <qtermwidget6/qtermwidget.h>

IDESettings::IDESettings() {}

void IDESettings::saveSettings()
{
    QSettings settings(settingsFileName);
    settings.setValue("showHelpTypeAny", IDESettings::showHelpTypeAny);
    settings.setValue("showHelpTypeCode", IDESettings::showHelpTypeCode);
    settings.setValue("showHelpDialogSizeHight", IDESettings::showHelpDialogSize.first);
    settings.setValue("showHelpDialogSizeWidth", IDESettings::showHelpDialogSize.second);
    settings.setValue("showCalculatorType", IDESettings::showCalculatorType);

    settings.setValue("syntaxHightlightingColors.lsm8bitInstR", std::get<0>(IDESettings::syntaxHightlightingColors.lsm8bitInst));
    settings.setValue("syntaxHightlightingColors.lsm8bitInstG", std::get<1>(IDESettings::syntaxHightlightingColors.lsm8bitInst));
    settings.setValue("syntaxHightlightingColors.lsm8bitInstB", std::get<2>(IDESettings::syntaxHightlightingColors.lsm8bitInst));
    settings.setValue("syntaxHightlightingColors.al8bitInstR", std::get<0>(IDESettings::syntaxHightlightingColors.al8bitInst));
    settings.setValue("syntaxHightlightingColors.al8bitInstG", std::get<1>(IDESettings::syntaxHightlightingColors.al8bitInst));
    settings.setValue("syntaxHightlightingColors.al8bitInstB", std::get<2>(IDESettings::syntaxHightlightingColors.al8bitInst));
    settings.setValue("syntaxHightlightingColors.jumpCallInstR", std::get<0>(IDESettings::syntaxHightlightingColors.jumpCallInst));
    settings.setValue("syntaxHightlightingColors.jumpCallInstG", std::get<1>(IDESettings::syntaxHightlightingColors.jumpCallInst));
    settings.setValue("syntaxHightlightingColors.jumpCallInstB", std::get<2>(IDESettings::syntaxHightlightingColors.jumpCallInst));
    settings.setValue("syntaxHightlightingColors.lsm16bitInstR", std::get<0>(IDESettings::syntaxHightlightingColors.lsm16bitInst));
    settings.setValue("syntaxHightlightingColors.lsm16bitInstG", std::get<1>(IDESettings::syntaxHightlightingColors.lsm16bitInst));
    settings.setValue("syntaxHightlightingColors.lsm16bitInstB", std::get<2>(IDESettings::syntaxHightlightingColors.lsm16bitInst));
    settings.setValue("syntaxHightlightingColors.al16bitInstR", std::get<0>(IDESettings::syntaxHightlightingColors.al16bitInst));
    settings.setValue("syntaxHightlightingColors.al16bitInstG", std::get<1>(IDESettings::syntaxHightlightingColors.al16bitInst));
    settings.setValue("syntaxHightlightingColors.al16bitInstB", std::get<2>(IDESettings::syntaxHightlightingColors.al16bitInst));
    settings.setValue("syntaxHightlightingColors.miscInstR", std::get<0>(IDESettings::syntaxHightlightingColors.miscInst));
    settings.setValue("syntaxHightlightingColors.miscInstG", std::get<1>(IDESettings::syntaxHightlightingColors.miscInst));
    settings.setValue("syntaxHightlightingColors.miscInstB", std::get<2>(IDESettings::syntaxHightlightingColors.miscInst));
    settings.setValue("syntaxHightlightingColors.macrosInstR", std::get<0>(IDESettings::syntaxHightlightingColors.macrosInst));
    settings.setValue("syntaxHightlightingColors.macrosInstG", std::get<1>(IDESettings::syntaxHightlightingColors.macrosInst));
    settings.setValue("syntaxHightlightingColors.macrosInstB", std::get<2>(IDESettings::syntaxHightlightingColors.macrosInst));
    settings.setValue("syntaxHightlightingColors.commentsR", std::get<0>(IDESettings::syntaxHightlightingColors.comments));
    settings.setValue("syntaxHightlightingColors.commentsG", std::get<1>(IDESettings::syntaxHightlightingColors.comments));
    settings.setValue("syntaxHightlightingColors.commentsB", std::get<2>(IDESettings::syntaxHightlightingColors.comments));
    settings.setValue("syntaxHightlightingColors.charsR", std::get<0>(IDESettings::syntaxHightlightingColors.chars));
    settings.setValue("syntaxHightlightingColors.charsG", std::get<1>(IDESettings::syntaxHightlightingColors.chars));
    settings.setValue("syntaxHightlightingColors.charsB", std::get<2>(IDESettings::syntaxHightlightingColors.chars));
    settings.setValue("syntaxHightlightingColors.labelsR", std::get<0>(IDESettings::syntaxHightlightingColors.labels));
    settings.setValue("syntaxHightlightingColors.labelsG", std::get<1>(IDESettings::syntaxHightlightingColors.labels));
    settings.setValue("syntaxHightlightingColors.labelsB", std::get<2>(IDESettings::syntaxHightlightingColors.labels));

    settings.setValue("startupWidgetsVisibitity.startPage", IDESettings::startupWidgetsVisibitity.startPage);
    settings.setValue("startupWidgetsVisibitity.simulator", IDESettings::startupWidgetsVisibitity.simulator);
    settings.setValue("startupWidgetsVisibitity.diagnostics", IDESettings::startupWidgetsVisibitity.diagnostics);
    settings.setValue("startupWidgetsVisibitity.converter", IDESettings::startupWidgetsVisibitity.converter);
    settings.setValue("startupWidgetsVisibitity.fileTree", IDESettings::startupWidgetsVisibitity.fileTree);

    settings.setValue("simMemorySize", IDESettings::simMemorySize);
    settings.setValue("simStartAddress", IDESettings::simStartAddress);

    settings.setValue("theme", IDESettings::theme);

    settings.setValue("terminalTheme", IDESettings::terminalTheme);
    settings.setValue("defaultTerminalFontSize", IDESettings::defaultTerminalFontSize);
    settings.setValue("defaultFontSize", IDESettings::defaultFontSize);
    settings.setValue("defaultLinesWrap", IDESettings::defaultLinesWrap);
    settings.setValue("defaultEditorFont", IDESettings::defaultEditorFont);
    settings.setValue("defaultTerminalFont", IDESettings::defaultTerminalFont);

    settings.setValue("lineHighlightColor.r", IDESettings::lineHighlightColor.red());
    settings.setValue("lineHighlightColor.g", IDESettings::lineHighlightColor.green());
    settings.setValue("lineHighlightColor.b", IDESettings::lineHighlightColor.blue());
    settings.setValue("createProjectLastLocation", IDESettings::createProjectLastLocation);
    settings.setValue("openProjectLastLocation", IDESettings::openProjectLastLocation);
    settings.setValue("fileLastLocation", IDESettings::fileLastLocation);
    settings.setValue("openScreenType", static_cast<int>(IDESettings::openScreenType));
    settings.setValue("simFullSpeed", IDESettings::simFullSpeed);

    settings.beginWriteArray("recentFiles");
    for(int i = 0; i<recentFiles.size(); i++)
    {
        settings.setArrayIndex(i);
        settings.setValue("path", IDESettings::recentFiles.at(i));
    }
    settings.endArray();
    settings.beginWriteArray("recentProjects");
    for(int i = 0; i<recentProjects.size(); i++)
    {
        settings.setArrayIndex(i);
        settings.setValue("path", IDESettings::recentProjects.at(i));
    }
    settings.endArray();
    settings.beginWriteArray("recentDirs");
    for(int i = 0; i<recentDirs.size(); i++)
    {
        settings.setArrayIndex(i);
        settings.setValue("path", IDESettings::recentDirs.at(i));
    }
    settings.endArray();
}

void IDESettings::loadSettings()
{
    QSettings settings(settingsFileName);

    if(!QDir(dataPath).exists())
    {
        QDir().mkpath(dataPath);
    }

    IDESettings::defaultSyntaxHightlightingColors.lsm8bitInst = std::make_tuple(44461, 55512, 59110);
    IDESettings::defaultSyntaxHightlightingColors.al8bitInst = std::make_tuple(65535, 65535, 0);
    IDESettings::defaultSyntaxHightlightingColors.jumpCallInst = std::make_tuple(65535, 42405, 0);
    IDESettings::defaultSyntaxHightlightingColors.lsm16bitInst = std::make_tuple(37008, 61166, 37008);
    IDESettings::defaultSyntaxHightlightingColors.al16bitInst = std::make_tuple(65535, 49344, 52171);
    IDESettings::defaultSyntaxHightlightingColors.miscInst = std::make_tuple(32896, 0, 32896);
    IDESettings::defaultSyntaxHightlightingColors.macrosInst = std::make_tuple(18504, 15677, 35723);
    IDESettings::defaultSyntaxHightlightingColors.comments = std::make_tuple(0, 32896, 0);
    IDESettings::defaultSyntaxHightlightingColors.labels = std::make_tuple(7710, 37008, 65535);
    IDESettings::defaultSyntaxHightlightingColors.chars = std::make_tuple(59881, 38550, 31354);

    IDESettings::showHelpTypeAny = (IDESettings::OpenNewType)settings.value("showHelpTypeAny", IDESettings::OpenNewType::window).toInt();
    IDESettings::showHelpTypeCode =(IDESettings::OpenNewType)settings.value("showHelpTypeCode", IDESettings::OpenNewType::tab).toInt();
    IDESettings::showHelpDialogSize = std::make_pair(settings.value("showHelpDialogSizeHight", 1200).toInt(), settings.value("showHelpDialogSizeWidth", 600).toInt());
    IDESettings::showCalculatorType = (IDESettings::OpenNewType)settings.value("showCalculatorType", IDESettings::OpenNewType::window).toInt();

    IDESettings::syntaxHightlightingColors.lsm8bitInst = std::make_tuple(settings.value("syntaxHightlightingColors.lsm8bitInstR", 44461).toInt(), settings.value("syntaxHightlightingColors.lsm8bitInstG", 55512).toInt(), settings.value("syntaxHightlightingColors.lsm8bitInstB", 59110).toInt());
    IDESettings::syntaxHightlightingColors.al8bitInst = std::make_tuple(settings.value("syntaxHightlightingColors.al8bitInstR", 65535).toInt(), settings.value("syntaxHightlightingColors.al8bitInstG", 65535).toInt(), settings.value("syntaxHightlightingColors.al8bitInstB", 0).toInt());
    IDESettings::syntaxHightlightingColors.jumpCallInst = std::make_tuple(settings.value("syntaxHightlightingColors.jumpCallInstR", 65535).toInt(), settings.value("syntaxHightlightingColors.jumpCallInstG", 42405).toInt(), settings.value("syntaxHightlightingColors.jumpCallInstB", 0).toInt());
    IDESettings::syntaxHightlightingColors.lsm16bitInst = std::make_tuple(settings.value("syntaxHightlightingColors.lsm16bitInstR", 37008).toInt(), settings.value("syntaxHightlightingColors.lsm16bitInstG", 61166).toInt(), settings.value("syntaxHightlightingColors.lsm16bitInstB", 37008).toInt());
    IDESettings::syntaxHightlightingColors.al16bitInst = std::make_tuple(settings.value("syntaxHightlightingColors.al16bitInstR", 65535).toInt(), settings.value("syntaxHightlightingColors.al16bitInstG", 49344).toInt(), settings.value("syntaxHightlightingColors.al16bitInstB", 52171).toInt());
    IDESettings::syntaxHightlightingColors.miscInst = std::make_tuple(settings.value("syntaxHightlightingColors.miscInstR", 32896).toInt(), settings.value("syntaxHightlightingColors.miscInstG", 0).toInt(), settings.value("syntaxHightlightingColors.miscInstB", 32896).toInt());
    IDESettings::syntaxHightlightingColors.macrosInst = std::make_tuple(settings.value("syntaxHightlightingColors.macrosInstR", 18504).toInt(), settings.value("syntaxHightlightingColors.macrosInstG", 15677).toInt(), settings.value("syntaxHightlightingColors.macrosInstB", 35723).toInt());
    IDESettings::syntaxHightlightingColors.comments = std::make_tuple(settings.value("syntaxHightlightingColors.commentsR", 0).toInt(), settings.value("syntaxHightlightingColors.commentsG", 32896).toInt(), settings.value("syntaxHightlightingColors.commentsB", 0).toInt());
    IDESettings::syntaxHightlightingColors.labels = std::make_tuple(settings.value("syntaxHightlightingColors.labelsR", 7710).toInt(), settings.value("syntaxHightlightingColors.labelsG", 37008).toInt(), settings.value("syntaxHightlightingColors.labelsB", 65535).toInt());
    IDESettings::syntaxHightlightingColors.chars = std::make_tuple(settings.value("syntaxHightlightingColors.charsR", 59881).toInt(), settings.value("syntaxHightlightingColors.charsG", 38550).toInt(), settings.value("syntaxHightlightingColors.charsB", 31354).toInt());

    IDESettings::startupWidgetsVisibitity.startPage = (IDESettings::WidgetsVisibility)settings.value("startupWidgetsVisibitity.startPage", IDESettings::show).toInt();
    IDESettings::startupWidgetsVisibitity.simulator = (IDESettings::WidgetsVisibility)settings.value("startupWidgetsVisibitity.simulator", IDESettings::hide).toInt();
    IDESettings::startupWidgetsVisibitity.diagnostics = (IDESettings::WidgetsVisibility)settings.value("startupWidgetsVisibitity.diagnostics", IDESettings::hide).toInt();
    IDESettings::startupWidgetsVisibitity.converter = (IDESettings::WidgetsVisibility)settings.value("startupWidgetsVisibitity.converter", IDESettings::hide).toInt();
    IDESettings::startupWidgetsVisibitity.fileTree = (IDESettings::WidgetsVisibility)settings.value("startupWidgetsVisibitity.fileTree", IDESettings::hide).toInt();

    IDESettings::terminalTheme = settings.value("terminalTheme", "").toString();
    IDESettings::defaultTerminalFontSize = settings.value("defaultTerminalFontSize", 10).toInt();
    IDESettings::defaultFontSize = settings.value("defaultFontSize", 10).toInt();
    IDESettings::defaultLinesWrap = settings.value("defaultLinesWrap", true).toBool();
    IDESettings::defaultEditorFont = settings.value("defaultEditorFont").toString();
    IDESettings::defaultTerminalFont = settings.value("defaultTerminalFont").toString();
    IDESettings::createProjectLastLocation = settings.value("createProjectLastLocation", QDir::homePath()).toString();
    IDESettings::openProjectLastLocation = settings.value("openProjectLastLocation", QDir::homePath()).toString();
    IDESettings::fileLastLocation = settings.value("fileLastLocation", QDir::homePath()).toString();

    IDESettings::lineHighlightColor = QColor::fromRgb(settings.value("lineHighlightColor.r", 255).toInt(), settings.value("lineHighlightColor.g", 255).toInt(), settings.value("lineHighlightColor.b", 0).toInt());

    IDESettings::openScreenType = static_cast<IDESettings::OpenScreenType>(settings.value("openScreenType", static_cast<int>(IDESettings::OpenScreenType::window)).toInt());

    IDESettings::simFullSpeed = settings.value("simFullSpeed", false).toBool();

    simMemorySize = settings.value("simMemorySize", 1024).toInt();
    simStartAddress = settings.value("simStartAddress", 0).toInt();

    IDESettings::recentFiles.clear();
    int size = settings.beginReadArray("recentFiles");
    for(int i = 0; i<size; i++)
    {
        settings.setArrayIndex(i);
        const QString path = settings.value("path").toString();
        if(!path.isEmpty())
            IDESettings::recentFiles.append(path);
    }
    settings.endArray();
    IDESettings::recentProjects.clear();
    size = settings.beginReadArray("recentProjects");
    for(int i = 0; i<size; i++)
    {
        settings.setArrayIndex(i);
        const QString path = settings.value("path").toString();
        if(!path.isEmpty())
            IDESettings::recentProjects.append(path);
    }
    settings.endArray();
    size = settings.beginReadArray("recentDirs");
    for(int i = 0; i<size; i++)
    {
        settings.setArrayIndex(i);
        const QString path = settings.value("path").toString();
        if(!path.isEmpty())
            IDESettings::recentDirs.append(path);
    }
    settings.endArray();

    Ssettings::memSize = simMemorySize;
    Ssettings::memStart = simStartAddress;

    IDESettings::theme = settings.value("theme", "").toString();

}

QString IDESettings::theme;
IDESettings::Languages IDESettings::language;
IDESettings::OpenNewType IDESettings::showHelpTypeCode;
IDESettings::OpenNewType IDESettings::showHelpTypeAny;
std::pair<int, int> IDESettings::showHelpDialogSize;
IDESettings::SyntaxHightlightingColors IDESettings::syntaxHightlightingColors;
IDESettings::SyntaxHightlightingColors IDESettings::defaultSyntaxHightlightingColors;
IDESettings::StartupWidgetsVisibitity IDESettings::startupWidgetsVisibitity;
IDESettings::OpenNewType IDESettings::showCalculatorType;
int IDESettings::simMemorySize;
int IDESettings::simStartAddress;
QString IDESettings::terminalTheme;
int IDESettings::defaultTerminalFontSize;
int IDESettings::defaultFontSize;
bool IDESettings::defaultLinesWrap;
QColor IDESettings::lineHighlightColor;
QString IDESettings::defaultEditorFont;
QString IDESettings::defaultTerminalFont;
QString IDESettings::createProjectLastLocation;
QString IDESettings::openProjectLastLocation;
QString IDESettings::fileLastLocation;
bool IDESettings::simFullSpeed;
QStringList IDESettings::recentFiles;
QStringList IDESettings::recentProjects;
QStringList IDESettings::recentDirs;
IDESettings::OpenScreenType IDESettings::openScreenType;
const QString IDESettings::dataPath = QDir::homePath() + QDir::separator() + ".local" + QDir::separator() + "share" + QDir::separator() + "8080ide";
