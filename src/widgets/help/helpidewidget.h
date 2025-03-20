#ifndef HELPIDEWIDGET_H
#define HELPIDEWIDGET_H

#include <QWidget>

namespace Ui {
class HelpIDEWidget;
}

class HelpIDEWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HelpIDEWidget(QWidget *parent = nullptr);
    ~HelpIDEWidget();
    void openInstructionHelp(QString instruction);

private:
    Ui::HelpIDEWidget *ui;
    QString language;
    QStringList helpPagesList = {"Welcome", "Projects", "Assembler", "Labels"};
    QStringList translations = {tr("Welcome"), tr("Projects"), tr("Assembler"), tr("Labels")};
};

#endif // HELPIDEWIDGET_H
