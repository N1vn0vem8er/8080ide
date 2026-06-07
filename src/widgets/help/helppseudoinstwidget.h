#ifndef HELPPSEUDOINSTWIDGET_H
#define HELPPSEUDOINSTWIDGET_H

#include <QStringListModel>
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
    void openInstructionHelp(const QString& instruction);

private slots:
    void onInstructionClicked(const QModelIndex &index);

private:
    Ui::HelpPseudoInstWidget *ui;
    QStringListModel* model;
    QString languageSuffix;
    QStringList instructionList{"ARRAY", "STRING", "IF", "ENDIF", "SET", "EQU", "MACRO", "ENDM", "END", "DB", "DW"};
};

#endif // HELPPSEUDOINSTWIDGET_H
