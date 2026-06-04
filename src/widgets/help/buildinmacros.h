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
    QStringList helpPagesList{"printchar"};
    QStringList translations{tr("PRINTCHAR")};
};

#endif // BUILDINMACROS_H
