#ifndef NUMBERCONVERTERDIALOG_H
#define NUMBERCONVERTERDIALOG_H

#include <QDialog>

#define DEC_IN 0
#define HEX_IN 1
#define BIN_IN 2
#define HEX_OUT 0
#define DEC_OUT 1
#define BIN_OUT 2

namespace Ui {
class NumberConverterDialog;
}

class NumberConverterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NumberConverterDialog(QWidget *parent = nullptr);
    ~NumberConverterDialog();

private:
    Ui::NumberConverterDialog *ui;
    void input();
    void changeMaxInLength();
};

#endif // NUMBERCONVERTERDIALOG_H
