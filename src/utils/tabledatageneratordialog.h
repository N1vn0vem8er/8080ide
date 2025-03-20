#ifndef TABLEDATAGENERATORDIALOG_H
#define TABLEDATAGENERATORDIALOG_H

#include <QDialog>

namespace Ui {
class TableDataGeneratorDialog;
}

class TableDataGeneratorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TableDataGeneratorDialog(QWidget *parent = nullptr);
    ~TableDataGeneratorDialog();

private:
    Ui::TableDataGeneratorDialog *ui;
    void generate();
    void copy();
};

#endif // TABLEDATAGENERATORDIALOG_H
