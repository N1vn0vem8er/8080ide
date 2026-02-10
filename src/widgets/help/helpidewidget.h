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
    void openInstructionHelp(QString instruction) const;

private:
    Ui::HelpIDEWidget *ui;
    QString language;
    QStringList helpPagesList = {"Welcome", "Projects", "Assembler", "Labels", "Graphics_Screen", "random_number_generator"};
    QStringList translations = {tr("Welcome"), tr("Projects"), tr("Assembler"), tr("Labels"), tr("Graphics Screen"), tr("Random Number Generator")};
};

#endif // HELPIDEWIDGET_H
