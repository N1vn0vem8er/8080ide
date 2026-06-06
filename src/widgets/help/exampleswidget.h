#ifndef EXAMPLESWIDGET_H
#define EXAMPLESWIDGET_H

#include <QStringListModel>
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
    void loadInstructionHelp(const QString &instruction);

private slots:
    void onInstructionClicked(const QModelIndex &index);

private:
    void initTranslations();

private:
    Ui::ExamplesWidget *ui;
    QStringListModel* model;
    QString languageSuffix;
    const QStringList helpPagesList{"helloworld", "helloworld2", "drawline", "drawcircle", "drawfigure", "fillscreen", "fillscreenwithcolors", "generaterandomnumber", "randomcolors", "guessinggame"};
};

#endif // EXAMPLESWIDGET_H
