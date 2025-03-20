#ifndef HELPWIDGET_H
#define HELPWIDGET_H

#include <QWidget>

namespace Ui {
class HelpWidget;
}

class HelpWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HelpWidget(QWidget *parent = nullptr);
    void openHelp(QString instruction);
    ~HelpWidget();

private:
    Ui::HelpWidget *ui;
    const QStringList helpInstructions = {"MVI" , "MOV" , "STAX" , "LDAX" , "LDA" , "STA",
                                          "RZN" , "RZC" , "RPO" , "RP" , "JNZ" , "JNC" ,
                                          "JPO" , "JP" , "JMP" , "CNZ" , "CNC" , "CPO" ,
                                          "CP" , "RST" , "RET" , "PCHL" , "RZ" , "RC" ,
                                          "RPE" , "RM" , "JZ" , "JC" , "JPE" , "JM" ,
                                          "CZ" , "CC" , "CPE" , "CM" , "CALL" , "RNC" ,
                                          "INR" , "DCR" , "RLC" , "RAL" , "bAA" , "STC" ,
                                          "RRC" , "RAR" , "CMA" , "CMC" , "ADD" , "SUB" ,
                                          "ADC" , "SBB" , "ANA" , "XRA" , "ORA" , "CMP" ,
                                          "ADI" , "SUI" , "ANI" , "ORI" , "ACI" , "SBI" ,
                                          "XRI" , "CPI" , "LXI" , "SHLD" , "LHLD" , "POP" , "PUSH" , "SPHL" , "XCHG",
                                          "NOP" , "HLT" , "OUT" , "IN" , "DI" , "EI" ,
                                          "INX","DAD","DCX"};
    const QStringList helpPseudoInstructions = {"STRING", "ARRAY", "ENDIF", "ENDM", "END", "IF", "MACRO", "SET", "EQU", "DB", "DW"};
};

#endif // HELPWIDGET_H
