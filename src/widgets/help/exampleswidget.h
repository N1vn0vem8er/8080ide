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
    QStringList helpPagesList = {"Hello World"};
    QStringList translations = {tr("Hello World")};
};

#endif // EXAMPLESWIDGET_H
