QT       += core gui \
printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    8080/assembler.cpp \
    editor/codeeditor.cpp \
    idesettings.cpp \
    processmanager.cpp \
    settingsPages/simsettingspage.cpp \
    settingsPages/startupsettingspage.cpp \
    widgets/runningprocesseslabel.cpp \
    widgets/terminalwidget.cpp \
    utils/mimefinderworker.cpp \
    utils/numberconverterwidget.cpp \
    settingsPages/helpsettings.cpp \
    settingsPages/stylesettingspage.cpp \
    settingsPages/syntaxhighlightingsettings.cpp \
    dialogs/createprojectwindow.cpp \
    filesystemtree.cpp \
    utils/git/customgitcommanddialog.cpp \
    editor/labelfinder.cpp \
    main.cpp \
    mainwindow.cpp \
    utils/memorywindow.cpp \
    widgets/projectglobalsearchwidget.cpp \
    projectmanager.cpp \
    dialogs/savewarningdialog.cpp \
    widgets/registerseditor.cpp \
    widgets/searchwidget.cpp \
    dialogs/settings.cpp \
    simrunner.cpp \
    ssettings.cpp \
    widgets/starttabwidget.cpp \
    utils/git/gitbranchdialog.cpp \
    utils/instinmemorydialog.cpp \
    utils/tabledatageneratordialog.cpp \
    utils/stringtablegeneratordialog.cpp \
    editor/syntaxhighlighter.cpp \
    tabview.cpp \
    dialogs/textinputdialog.cpp \
    simhandeler.cpp \
    8080/Symulator.cpp \
    utils/calcdialog.cpp \
    utils/numberconverterdialog.cpp \
    widgets/help/helpidewidget.cpp \
    widgets/help/helpinstructionswidget.cpp \
    widgets/help/helppseudoinstwidget.cpp \
    widgets/helpwidget.cpp \
    utils/git/gitfilestatusitemdelegate.cpp \
    utils/git/gitfilestatusmodel.cpp \
    utils/git/gitwidget.cpp \
    utils/git/gitfilesview.cpp

HEADERS += \
    8080/assembler.h \
    editor/LineNumberArea.h \
    editor/codeeditor.h \
    idesettings.h \
    processmanager.h \
    settingsPages/simsettingspage.h \
    settingsPages/startupsettingspage.h \
    structs.h \
    widgets/runningprocesseslabel.h \
    widgets/terminalwidget.h \
    utils/mimefinderworker.h \
    utils/numberconverterwidget.h \
    settingsPages/helpsettings.h \
    settingsPages/stylesettingspage.h \
    settingsPages/syntaxhighlightingsettings.h \
    dialogs/createprojectwindow.h \
    filesystemtree.h \
    utils/git/customgitcommanddialog.h \
    globals.h \
    editor/labelfinder.h \
    mainwindow.h \
    utils/memorywindow.h \
    widgets/projectglobalsearchwidget.h \
    projectmanager.h \
    dialogs/savewarningdialog.h \
    widgets/registerseditor.h \
    widgets/searchwidget.h \
    dialogs/settings.h \
    simrunner.h \
    ssettings.h \
    widgets/starttabwidget.h \
    utils/git/gitbranchdialog.h \
    utils/instinmemorydialog.h \
    utils/tabledatageneratordialog.h \
    utils/stringtablegeneratordialog.h \
    editor/syntaxhighlighter.h \
    tabview.h \
    dialogs/textinputdialog.h \
    simhandeler.h \
    8080/Symulator.h \
    utils/calcdialog.h \
    utils/numberconverterdialog.h \
    widgets/help/helpidewidget.h \
    widgets/help/helpinstructionswidget.h \
    widgets/help/helppseudoinstwidget.h \
    widgets/helpwidget.h \
    utils/git/gitfilestatusitemdelegate.h \
    utils/git/gitfilestatusmodel.h \
    utils/git/gitwidget.h \
    utils/git/gitfilesview.h

FORMS += \
    settingsPages/simsettingspage.ui \
    settingsPages/startupsettingspage.ui \
    widgets/terminalwidget.ui \
    utils/numberconverterwidget.ui \
    settingsPages/helpsettings.ui \
    settingsPages/stylesettingspage.ui \
    settingsPages/syntaxhighlightingsettings.ui \
    dialogs/createprojectwindow.ui \
    utils/git/customgitcommanddialog.ui \
    mainwindow.ui \
    utils/memorywindow.ui \
    widgets/projectglobalsearchwidget.ui \
    dialogs/savewarningdialog.ui \
    widgets/registerseditor.ui \
    widgets/searchwidget.ui \
    dialogs/settings.ui \
    widgets/starttabwidget.ui \
    utils/git/gitbranchdialog.ui \
    utils/instinmemorydialog.ui \
    utils/tabledatageneratordialog.ui \
    utils/stringtablegeneratordialog.ui \
    dialogs/textinputdialog.ui \
    utils/calcdialog.ui \
    utils/numberconverterdialog.ui \
    widgets/help/helpidewidget.ui \
    widgets/help/helpinstructionswidget.ui \
    widgets/help/helppseudoinstwidget.ui \
    widgets/helpwidget.ui \
    utils/git/gitwidget.ui

TRANSLATIONS += \
    8080ide_pl_PL.ts
CONFIG += lrelease
CONFIG += embed_translations

TARGET = 8080ide


# Default rules for deployment.
# qnx: target.path = /tmp/$${TARGET}/bin
# else: unix:!android: target.path = /opt/$${TARGET}/bin
target.path = /usr/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources/helpPages.qrc \
    resources/icons/icons.qrc

LIBS += -lqtermwidget6

