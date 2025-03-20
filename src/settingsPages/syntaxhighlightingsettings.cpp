#include "syntaxhighlightingsettings.h"
#include "idesettings.h"
#include "ui_syntaxhighlightingsettings.h"

#include <QColorDialog>

SyntaxHighlightingSettings::SyntaxHighlightingSettings(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SyntaxHighlightingSettings)
{
    ui->setupUi(this);
    connect(ui->selectColor8lsm, &QPushButton::clicked, [=](){openColorPicker(ColorOptions::b8lsm);});
    connect(ui->selectColor16lsm, &QPushButton::clicked, [=](){openColorPicker(ColorOptions::b16lsm);});
    connect(ui->selectColor8al, &QPushButton::clicked, [=](){openColorPicker(ColorOptions::b8al);});
    connect(ui->selectColor16al, &QPushButton::clicked, [=](){openColorPicker(ColorOptions::b16al);});
    connect(ui->selectColorJMP, &QPushButton::clicked, [=](){openColorPicker(ColorOptions::jc);});
    connect(ui->selectColormisc, &QPushButton::clicked, [=](){openColorPicker(ColorOptions::misc);});
    connect(ui->selectColorpinst, &QPushButton::clicked, [=](){openColorPicker(ColorOptions::pinst);});
    connect(ui->selectColorcomm, &QPushButton::clicked, [=](){openColorPicker(ColorOptions::comm);});
    connect(ui->reset8lsm, &QPushButton::clicked, [=](){setColorToDefault(ColorOptions::b8lsm);});
    connect(ui->reset16lsm, &QPushButton::clicked, [=](){setColorToDefault(ColorOptions::b16lsm);});
    connect(ui->reset8al, &QPushButton::clicked, [=](){setColorToDefault(ColorOptions::b8al);});
    connect(ui->reset16al, &QPushButton::clicked, [=](){setColorToDefault(ColorOptions::b16al);});
    connect(ui->resetJMP, &QPushButton::clicked, [=](){setColorToDefault(ColorOptions::jc);});
    connect(ui->resetmiscInst, &QPushButton::clicked, [=](){setColorToDefault(ColorOptions::misc);});
    connect(ui->resetpInst, &QPushButton::clicked, [=](){setColorToDefault(ColorOptions::pinst);});
    connect(ui->resetcomm, &QPushButton::clicked, [=](){setColorToDefault(ColorOptions::comm);});
    connect(ui->selectColorChars, &QPushButton::clicked, [=](){openColorPicker(ColorOptions::ch);});
    connect(ui->resetChars, &QPushButton::clicked, [=](){setColorToDefault(ColorOptions::ch);});
    connect(ui->selectColorLabels, &QPushButton::clicked, [=](){openColorPicker(ColorOptions::label);});
    connect(ui->resetLabels, &QPushButton::clicked, [=](){setColorToDefault(ColorOptions::label);});
    connect(ui->applyButton, &QPushButton::clicked, this, &SyntaxHighlightingSettings::apply);
    updateColors();
}

SyntaxHighlightingSettings::~SyntaxHighlightingSettings()
{
    delete ui;
}

void SyntaxHighlightingSettings::updateColors()
{
    QPalette palette = ui->bit8lsmInstLabel->palette();
    palette.setColor(ui->bit8lsmInstLabel->foregroundRole(), QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.lsm8bitInst),
                                                                                 std::get<1>(IDESettings::syntaxHightlightingColors.lsm8bitInst),
                                                                                 std::get<2>(IDESettings::syntaxHightlightingColors.lsm8bitInst)));
    ui->bit8lsmInstLabel->setPalette(palette);
    palette = ui->jmpcallInstLabel->palette();
    palette.setColor(ui->jmpcallInstLabel->foregroundRole(), QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.jumpCallInst),
                                                                                std::get<1>(IDESettings::syntaxHightlightingColors.jumpCallInst),
                                                                                std::get<2>(IDESettings::syntaxHightlightingColors.jumpCallInst)));
    ui->jmpcallInstLabel->setPalette(palette);
    palette = ui->bit16lsmInstLabel->palette();
    palette.setColor(ui->bit16lsmInstLabel->foregroundRole(), QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.lsm16bitInst),
                                                                                std::get<1>(IDESettings::syntaxHightlightingColors.lsm16bitInst),
                                                                                std::get<2>(IDESettings::syntaxHightlightingColors.lsm16bitInst)));
    ui->bit16lsmInstLabel->setPalette(palette);
    palette = ui->bit8alInstLabel->palette();
    palette.setColor(ui->bit8alInstLabel->foregroundRole(), QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.al8bitInst),
                                                                                std::get<1>(IDESettings::syntaxHightlightingColors.al8bitInst),
                                                                                std::get<2>(IDESettings::syntaxHightlightingColors.al8bitInst)));
    ui->bit8alInstLabel->setPalette(palette);
    palette = ui->bit16alInstLabel->palette();
    palette.setColor(ui->bit16alInstLabel->foregroundRole(), QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.al16bitInst),
                                                                                std::get<1>(IDESettings::syntaxHightlightingColors.al16bitInst),
                                                                                std::get<2>(IDESettings::syntaxHightlightingColors.al16bitInst)));
    ui->bit16alInstLabel->setPalette(palette);
    palette = ui->miscInstLabel->palette();
    palette.setColor(ui->miscInstLabel->foregroundRole(), QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.miscInst),
                                                                                std::get<1>(IDESettings::syntaxHightlightingColors.miscInst),
                                                                                std::get<2>(IDESettings::syntaxHightlightingColors.miscInst)));
    ui->miscInstLabel->setPalette(palette);
    palette = ui->pInstLabel->palette();
    palette.setColor(ui->pInstLabel->foregroundRole(), QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.macrosInst),
                                                                                std::get<1>(IDESettings::syntaxHightlightingColors.macrosInst),
                                                                                std::get<2>(IDESettings::syntaxHightlightingColors.macrosInst)));
    ui->pInstLabel->setPalette(palette);
    palette = ui->commentLabel->palette();
    palette.setColor(ui->commentLabel->foregroundRole(), QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.comments),
                                                                          std::get<1>(IDESettings::syntaxHightlightingColors.comments),
                                                                          std::get<2>(IDESettings::syntaxHightlightingColors.comments)));
    ui->commentLabel->setPalette(palette);
    palette = ui->charsLabel->palette();
    palette.setColor(ui->charsLabel->foregroundRole(), QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.chars),
                                                                        std::get<1>(IDESettings::syntaxHightlightingColors.chars),
                                                                          std::get<2>(IDESettings::syntaxHightlightingColors.chars)));
    ui->charsLabel->setPalette(palette);
    palette = ui->labelsLabel->palette();
    palette.setColor(ui->labelsLabel->foregroundRole(), QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.labels),
                                                                          std::get<1>(IDESettings::syntaxHightlightingColors.labels),
                                                                          std::get<2>(IDESettings::syntaxHightlightingColors.labels)));
    ui->labelsLabel->setPalette(palette);
}

void SyntaxHighlightingSettings::openColorPicker(ColorOptions option)
{
    QColorDialog dialog;
    if(dialog.exec() == QDialog::Accepted)
    {
    switch(option)
    {

    case b8lsm:
        IDESettings::syntaxHightlightingColors.lsm8bitInst = std::make_tuple(dialog.selectedColor().rgba64().red(), dialog.selectedColor().rgba64().green(), dialog.selectedColor().rgba64().blue());
        break;
    case b16lsm:
        IDESettings::syntaxHightlightingColors.lsm16bitInst = std::make_tuple(dialog.selectedColor().rgba64().red(), dialog.selectedColor().rgba64().green(), dialog.selectedColor().rgba64().blue());
        break;
    case b8al:
        IDESettings::syntaxHightlightingColors.al8bitInst = std::make_tuple(dialog.selectedColor().rgba64().red(), dialog.selectedColor().rgba64().green(), dialog.selectedColor().rgba64().blue());
        break;
    case b16al:
        IDESettings::syntaxHightlightingColors.al16bitInst = std::make_tuple(dialog.selectedColor().rgba64().red(), dialog.selectedColor().rgba64().green(), dialog.selectedColor().rgba64().blue());
        break;
    case jc:
        IDESettings::syntaxHightlightingColors.jumpCallInst = std::make_tuple(dialog.selectedColor().rgba64().red(), dialog.selectedColor().rgba64().green(), dialog.selectedColor().rgba64().blue());
        break;
    case pinst:
        IDESettings::syntaxHightlightingColors.macrosInst = std::make_tuple(dialog.selectedColor().rgba64().red(), dialog.selectedColor().rgba64().green(), dialog.selectedColor().rgba64().blue());
        break;
    case misc:
        IDESettings::syntaxHightlightingColors.miscInst = std::make_tuple(dialog.selectedColor().rgba64().red(), dialog.selectedColor().rgba64().green(), dialog.selectedColor().rgba64().blue());
        break;
    case comm:
        IDESettings::syntaxHightlightingColors.comments = std::make_tuple(dialog.selectedColor().rgba64().red(), dialog.selectedColor().rgba64().green(), dialog.selectedColor().rgba64().blue());
        break;
    case ch:
        IDESettings::syntaxHightlightingColors.chars = std::make_tuple(dialog.selectedColor().rgba64().red(), dialog.selectedColor().rgba64().green(), dialog.selectedColor().rgba64().blue());
        break;
    case label:
        IDESettings::syntaxHightlightingColors.labels = std::make_tuple(dialog.selectedColor().rgba64().red(), dialog.selectedColor().rgba64().green(), dialog.selectedColor().rgba64().blue());
        break;
    }
    updateColors();
    }
}

void SyntaxHighlightingSettings::setColorToDefault(ColorOptions option)
{
    switch(option)
    {

    case b8lsm:
        IDESettings::syntaxHightlightingColors.lsm8bitInst = IDESettings::defaultSyntaxHightlightingColors.lsm8bitInst;
        break;
    case b16lsm:
        IDESettings::syntaxHightlightingColors.lsm16bitInst = IDESettings::defaultSyntaxHightlightingColors.lsm16bitInst;
        break;
    case b8al:
        IDESettings::syntaxHightlightingColors.al8bitInst = IDESettings::defaultSyntaxHightlightingColors.al8bitInst;
        break;
    case b16al:
        IDESettings::syntaxHightlightingColors.al16bitInst = IDESettings::defaultSyntaxHightlightingColors.al16bitInst;
        break;
    case jc:
        IDESettings::syntaxHightlightingColors.jumpCallInst = IDESettings::defaultSyntaxHightlightingColors.jumpCallInst;
        break;
    case pinst:
        IDESettings::syntaxHightlightingColors.macrosInst = IDESettings::defaultSyntaxHightlightingColors.macrosInst;
        break;
    case misc:
        IDESettings::syntaxHightlightingColors.miscInst = IDESettings::defaultSyntaxHightlightingColors.miscInst;
        break;
    case comm:
        IDESettings::syntaxHightlightingColors.comments = IDESettings::defaultSyntaxHightlightingColors.comments;
        break;
    case ch:
        IDESettings::syntaxHightlightingColors.chars = IDESettings::defaultSyntaxHightlightingColors.chars;
        break;
    case label:
        IDESettings::syntaxHightlightingColors.labels = IDESettings::defaultSyntaxHightlightingColors.labels;
        break;
    }
    updateColors();
}

void SyntaxHighlightingSettings::apply()
{
    IDESettings s;
    s.saveSettings();
}
