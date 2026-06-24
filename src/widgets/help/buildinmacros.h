#ifndef BUILDINMACROS_H
#define BUILDINMACROS_H

#include <QStringListModel>
#include <QWidget>

namespace Ui {
class BuildinMacros;
}

class BuildinMacros : public QWidget
{
    Q_OBJECT

public:
    explicit BuildinMacros(QWidget *parent = nullptr);
    ~BuildinMacros();
    void loadInstructionHelp(const QString &instruction);

private slots:
    void onInstructionClicked(const QModelIndex &index);

private:
    void initTranslations();

private:
    Ui::BuildinMacros *ui;
    QStringListModel* model;
    QString languageSuffix;
    const QStringList helpPagesList{"printchar", "inchar", "gclear", "gdraw", "gx", "gy", "gline", "gpfill", "gpfigure", "gfill", "gcfelipse", "gpfelipse", "gcelipse", "gpelipse", "randset", "randin"};
};

#endif // BUILDINMACROS_H
