#ifndef SYNTAXHIGHLIGHTINGSETTINGS_H
#define SYNTAXHIGHLIGHTINGSETTINGS_H

#include <QWidget>

namespace Ui {
class SyntaxHighlightingSettings;
}

class SyntaxHighlightingSettings : public QWidget
{
    Q_OBJECT

public:
    explicit SyntaxHighlightingSettings(QWidget *parent = nullptr);
    ~SyntaxHighlightingSettings();

private:
    enum ColorOptions
    {
        b8lsm,
        b16lsm,
        b8al,
        b16al,
        jc,
        pinst,
        misc,
        comm,
        ch,
        label
    };
    Ui::SyntaxHighlightingSettings *ui;
    void updateColors() const;
    void openColorPicker(ColorOptions option) const;
    void setColorToDefault(ColorOptions option);
    void apply() const;
};

#endif // SYNTAXHIGHLIGHTINGSETTINGS_H
