#ifndef INSTINMEMORYDIALOG_H
#define INSTINMEMORYDIALOG_H

#include <QDialog>

namespace Ui {
class InstInMemoryDialog;
}

class InstInMemoryDialog : public QDialog
{
    Q_OBJECT

public:
    explicit InstInMemoryDialog(QWidget *parent = nullptr);
    void setText(QString text);
    ~InstInMemoryDialog();

private:
    Ui::InstInMemoryDialog *ui;
    QString text;
    void count();
    QStringList oneByteInsts = {"MOV", "CMP", "NOP", "STAX", "INX", "INR", "DCR", "RLC", "DAD", "LDAX", "DCX", "DCR", "RRC", "RAL", "RAR", "DAA", "CMA", "STC", "CMC", "HLT", "ADD", "ADC", "SUB", "SBB", "ANA", "XRA",
                                "ORA", "RNZ", "POP", "PUSH", "RST", "RZ", "RET", "RNC", "RC", "RPO", "XTHL", "RPE", "PCHL", "XCHG", "RP", "DI", "EI", "RM", "SPHL", "DB"};
    QStringList twoByteInsts = {"MVI", "ADI", "SUI", "ANI", "ORI", "IN", "OUT", "ACI", "SBI", "XRI", "CPI", "DW"};
    QStringList threeByteInsts = {"JMP", "JNZ", "JZ", "JP", "JPE", "LXI", "STA", "SHLD", "LHLD", "JNC", "CNZ", "CNC", "CPO", "CP", "JC", "JM", "CZ", "CC", "CPE", "CM", "CALL"};
};

#endif // INSTINMEMORYDIALOG_H
