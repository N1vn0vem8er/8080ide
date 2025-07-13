#ifndef CALCDIALOG_H
#define CALCDIALOG_H

#include <QDialog>

namespace Ui {
class CalcDialog;
}

class CalcDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CalcDialog(QWidget *parent = nullptr);
    ~CalcDialog();

private:
    Ui::CalcDialog *ui;
    enum ModeIndex{
        HEX,
        DEC,
        BIN
    };
    enum Operations{
        ADD,
        SUB,
        MUL,
        DIV,
        SL,
        SR,
        AND,
        OR,
        XOR,
        MOD,
        CMP
    };

    int currentMode = 0;
    QString displayBuffer;
    long numBuffer;
    long opNumBuffer;
    int operationBuffer;
    void modeChanged(int mode);
    void handleKey(int key);
    void doMath();
    void displayResoults();

protected:
    void keyPressEvent(QKeyEvent *event) override;
};

#endif // CALCDIALOG_H
