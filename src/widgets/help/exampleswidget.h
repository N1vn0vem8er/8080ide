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
    QStringList helpPagesList = {"Hello World", "Hello World 2"};
    QStringList translations = {tr("Hello World"), tr("Hello World 2")};
};

#endif // EXAMPLESWIDGET_H
