#ifndef BUILDINMACROS_H
#define BUILDINMACROS_H

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
    void openInstructionHelp(QString instruction) const;

private:
    Ui::BuildinMacros *ui;
    QString language;
    QStringList helpPagesList{"printchar", "inchar", "gclear"};
    QStringList translations{tr("PRINTCHAR"), tr("INCHAR"), tr("GCLEAR")};
};

#endif // BUILDINMACROS_H
