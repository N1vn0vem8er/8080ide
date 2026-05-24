#ifndef EXAMPLESWIDGET_H
#define EXAMPLESWIDGET_H

#include <QWidget>

namespace Ui {
class ExamplesWidget;
}

class ExamplesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ExamplesWidget(QWidget *parent = nullptr);
    ~ExamplesWidget();
    void openInstructionHelp(QString instruction) const;

private:
    Ui::ExamplesWidget *ui;
    QString language;
    QStringList helpPagesList = {"helloworld", "helloworld2", "drawline", "drawcircle", "drawfigure", "fillscreen", "fillscreenwithcolors", "generaterandomnumber"};
    QStringList translations = {tr("Hello World"), tr("Hello World 2"), tr("Draw line"), tr("Draw circle"), tr("Draw figure"), tr("Fill screen"), tr("Fill screen with colors"), tr("Generate random number")};
};

#endif // EXAMPLESWIDGET_H
