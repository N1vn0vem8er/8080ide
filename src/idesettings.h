#ifndef IDESETTINGS_H
#define IDESETTINGS_H

#include <QColor>
#include <QDir>
#include <qstring.h>

class IDESettings
{
public:
    enum Languages
    {
        english,
        polish
    };
    enum OpenNewType{
        window,
        tab
    };
    struct SyntaxHightlightingColors{
        std::tuple<ushort, ushort, ushort> lsm8bitInst;
        std::tuple<ushort, ushort, ushort> lsm16bitInst;
        std::tuple<ushort, ushort, ushort> jumpCallInst;
        std::tuple<ushort, ushort, ushort> al8bitInst;
        std::tuple<ushort, ushort, ushort> al16bitInst;
        std::tuple<ushort, ushort, ushort> miscInst;
        std::tuple<ushort, ushort, ushort> macrosInst;
        std::tuple<ushort, ushort, ushort> comments;
        std::tuple<ushort, ushort, ushort> labels;
        std::tuple<ushort, ushort, ushort> chars;
    };
    enum WidgetsVisibility{
        hide,
        show
    };
    struct StartupWidgetsVisibitity{
        WidgetsVisibility startPage;
        WidgetsVisibility simulator;
        WidgetsVisibility diagnostics;
        WidgetsVisibility converter;
        WidgetsVisibility fileTree;
    };

    IDESettings();
    static QString theme;
    static Languages language;
    static OpenNewType showHelpTypeCode;
    static OpenNewType showHelpTypeAny;
    static OpenNewType showCalculatorType;
    static std::pair<int, int> showHelpDialogSize;
    static SyntaxHightlightingColors syntaxHightlightingColors;
    static SyntaxHightlightingColors defaultSyntaxHightlightingColors;
    static StartupWidgetsVisibitity startupWidgetsVisibitity;
    static QString terminalTheme;
    static int defaultTerminalFontSize;
    static int defaultFontSize;
    static bool defaultLinesWrap;
    static int simMemorySize;
    static int simStartAddress;
    static QColor lineHighlightColor;
    static QString defaultEditorFont;
    static QString defaultTerminalFont;
    static QString createProjectLastLocation;
    static QString openProjectLastLocation;
    static QString fileLastLocation;
    static QStringList recentFiles;
    static QStringList recentProjects;
    static QStringList recentDirs;
    const QString settingsDirName = "ide8080";
    const QString settingsFileName = "idssettings";
    static const QString dataPath;
    void saveSettings();
    void loadSettings();
};

#endif // IDESETTINGS_H
