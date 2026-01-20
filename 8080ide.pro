QT       += core gui \
printsupport \
    widgets

greaterThan(QT_MAJOR_VERSION, 6): QT += widgets

CONFIG += c++20

SOURCES += \
    src/8080/assembler.cpp \
    src/dialogs/projectconfigurationwidget.cpp \
    src/editor/codeeditor.cpp \
    src/editor/hovertooltipwidget.cpp \
    src/idesettings.cpp \
    src/processmanager.cpp \
    src/settingsPages/simsettingspage.cpp \
    src/settingsPages/startupsettingspage.cpp \
    src/settingsPages/terminalsettingspage.cpp \
    src/utils/projectconfig.cpp \
    src/widgets/guiprojectconfigwidget.cpp \
    src/widgets/runningprocesseslabel.cpp \
    src/widgets/screenwidget.cpp \
    src/widgets/terminalwidget.cpp \
    src/utils/mimefinderworker.cpp \
    src/utils/numberconverterwidget.cpp \
    src/settingsPages/helpsettings.cpp \
    src/settingsPages/stylesettingspage.cpp \
    src/settingsPages/syntaxhighlightingsettings.cpp \
    src/dialogs/createprojectwindow.cpp \
    src/filesystemtree.cpp \
    src/utils/git/customgitcommanddialog.cpp \
    src/editor/labelfinder.cpp \
    src/main.cpp \
    src/mainwindow.cpp \
    src/utils/memorywindow.cpp \
    src/widgets/projectglobalsearchwidget.cpp \
    src/projectmanager.cpp \
    src/dialogs/savewarningdialog.cpp \
    src/widgets/registerseditor.cpp \
    src/widgets/searchwidget.cpp \
    src/dialogs/settings.cpp \
    src/simrunner.cpp \
    src/ssettings.cpp \
    src/widgets/starttabwidget.cpp \
    src/utils/git/gitbranchdialog.cpp \
    src/utils/instinmemorydialog.cpp \
    src/utils/tabledatageneratordialog.cpp \
    src/utils/stringtablegeneratordialog.cpp \
    src/editor/syntaxhighlighter.cpp \
    src/tabview.cpp \
    src/dialogs/textinputdialog.cpp \
    src/simhandeler.cpp \
    src/8080/Symulator.cpp \
    src/utils/calcdialog.cpp \
    src/utils/numberconverterdialog.cpp \
    src/widgets/help/helpidewidget.cpp \
    src/widgets/help/helpinstructionswidget.cpp \
    src/widgets/help/helppseudoinstwidget.cpp \
    src/widgets/helpwidget.cpp \
    src/utils/git/gitfilestatusitemdelegate.cpp \
    src/utils/git/gitfilestatusmodel.cpp \
    src/utils/git/gitwidget.cpp \
    src/utils/git/gitfilesview.cpp

HEADERS += \
    src/8080/assembler.h \
    src/dialogs/projectconfigurationwidget.h \
    src/editor/LineNumberArea.h \
    src/editor/codeeditor.h \
    src/editor/hovertooltipwidget.h \
    src/idesettings.h \
    src/processmanager.h \
    src/settingsPages/simsettingspage.h \
    src/settingsPages/startupsettingspage.h \
    src/settingsPages/terminalsettingspage.h \
    src/structs.h \
    src/utils/projectconfig.h \
    src/widgets/guiprojectconfigwidget.h \
    src/widgets/runningprocesseslabel.h \
    src/widgets/screenwidget.h \
    src/widgets/terminalwidget.h \
    src/utils/mimefinderworker.h \
    src/utils/numberconverterwidget.h \
    src/settingsPages/helpsettings.h \
    src/settingsPages/stylesettingspage.h \
    src/settingsPages/syntaxhighlightingsettings.h \
    src/dialogs/createprojectwindow.h \
    src/filesystemtree.h \
    src/utils/git/customgitcommanddialog.h \
    src/globals.h \
    src/editor/labelfinder.h \
    src/mainwindow.h \
    src/utils/memorywindow.h \
    src/widgets/projectglobalsearchwidget.h \
    src/projectmanager.h \
    src/dialogs/savewarningdialog.h \
    src/widgets/registerseditor.h \
    src/widgets/searchwidget.h \
    src/dialogs/settings.h \
    src/simrunner.h \
    src/ssettings.h \
    src/widgets/starttabwidget.h \
    src/utils/git/gitbranchdialog.h \
    src/utils/instinmemorydialog.h \
    src/utils/tabledatageneratordialog.h \
    src/utils/stringtablegeneratordialog.h \
    src/editor/syntaxhighlighter.h \
    src/tabview.h \
    src/dialogs/textinputdialog.h \
    src/simhandeler.h \
    src/8080/Symulator.h \
    src/utils/calcdialog.h \
    src/utils/numberconverterdialog.h \
    src/widgets/help/helpidewidget.h \
    src/widgets/help/helpinstructionswidget.h \
    src/widgets/help/helppseudoinstwidget.h \
    src/widgets/helpwidget.h \
    src/utils/git/gitfilestatusitemdelegate.h \
    src/utils/git/gitfilestatusmodel.h \
    src/utils/git/gitwidget.h \
    src/utils/git/gitfilesview.h

FORMS += \
    src/dialogs/projectconfigurationwidget.ui \
    src/settingsPages/simsettingspage.ui \
    src/settingsPages/startupsettingspage.ui \
    src/settingsPages/terminalsettingspage.ui \
    src/widgets/guiprojectconfigwidget.ui \
    src/widgets/terminalwidget.ui \
    src/utils/numberconverterwidget.ui \
    src/settingsPages/helpsettings.ui \
    src/settingsPages/stylesettingspage.ui \
    src/settingsPages/syntaxhighlightingsettings.ui \
    src/dialogs/createprojectwindow.ui \
    src/utils/git/customgitcommanddialog.ui \
    src/mainwindow.ui \
    src/utils/memorywindow.ui \
    src/widgets/projectglobalsearchwidget.ui \
    src/dialogs/savewarningdialog.ui \
    src/widgets/registerseditor.ui \
    src/widgets/searchwidget.ui \
    src/dialogs/settings.ui \
    src/widgets/starttabwidget.ui \
    src/utils/git/gitbranchdialog.ui \
    src/utils/instinmemorydialog.ui \
    src/utils/tabledatageneratordialog.ui \
    src/utils/stringtablegeneratordialog.ui \
    src/dialogs/textinputdialog.ui \
    src/utils/calcdialog.ui \
    src/utils/numberconverterdialog.ui \
    src/widgets/help/helpidewidget.ui \
    src/widgets/help/helpinstructionswidget.ui \
    src/widgets/help/helppseudoinstwidget.ui \
    src/widgets/helpwidget.ui \
    src/utils/git/gitwidget.ui

INCLUDEPATH += \
    src

TRANSLATIONS += \
    src/8080ide_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

TARGET = 8080ide

target.path = /usr/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    src/resources/helpPages.qrc \
    src/resources/hintFiles.qrc \
    src/resources/icons/icons.qrc

LIBS += -lqtermwidget6

