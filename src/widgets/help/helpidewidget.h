#ifndef HELPIDEWIDGET_H
#define HELPIDEWIDGET_H

#include <QStringListModel>
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
    void openInstructionHelp(const QString& instruction);

private slots:
    void onInstructionClicked(const QModelIndex &index);

private:
    void initTranslations();

private:
    Ui::HelpIDEWidget *ui;
    QStringListModel* model;
    QString languageSuffix;
    QStringList helpPagesList{"Welcome", "Projects", "Assembler", "Labels", "Graphics_Screen", "random_number_generator"};
};

#endif // HELPIDEWIDGET_H
