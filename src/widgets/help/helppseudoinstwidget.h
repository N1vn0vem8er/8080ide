#ifndef HELPPSEUDOINSTWIDGET_H
#define HELPPSEUDOINSTWIDGET_H

#include <QWidget>

namespace Ui {
class HelpPseudoInstWidget;
}

class HelpPseudoInstWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HelpPseudoInstWidget(QWidget *parent = nullptr);
    ~HelpPseudoInstWidget();
    void openInstructionHelp(QString instruction) const;

private:
    Ui::HelpPseudoInstWidget *ui;
    QString language;
    QStringList instructionList = {"ARRAY", "STRING", "IF", "ENDIF", "SET", "EQU", "MACRO", "ENDM", "END", "DB", "DW"};
};

#endif // HELPPSEUDOINSTWIDGET_H
