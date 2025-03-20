#ifndef HELPINSTRUCTIONSWIDGET_H
#define HELPINSTRUCTIONSWIDGET_H

#include <QWidget>

namespace Ui {
class HelpInstructionsWidget;
}

class HelpInstructionsWidget : public QWidget
{
    Q_OBJECT

public:
    enum Instructions
    {
        NOP,LXI,STAX,INX,INR,DCR,MVI,RLC,DAD,LDAX,DCX,RRC,RAL,RAR,SHLD,DAA,LHLD,CMA,STA,STC,LDA,CMC,MOV,HLT,ADD,ADC,SUB,SBB,ANA,XRA,ORA,CMP,RNZ,POP,JNZ,JMP,CNZ,PUSH,ADI,RST,RZ,RAT,JZ,CZ,CALL,ACI,RNC,
        JNC,OUT,CNC,SUI,RC,JC,IN,CC,SBI,RPO,JPO,XTHL,CPO,ANI,RPE,PCHL,JPE,XCHG,CPE,XRI,RP,JP,DI,CP,ORI,RM,SPHL,JM,EI,CM,CPI
    };
    struct InstDesc
    {
        QString name;
        QString descriptionHTML;
    };

    explicit HelpInstructionsWidget(QWidget *parent = nullptr);
    ~HelpInstructionsWidget();
    void openInstructionHelp(QString instruction);

private:
    Ui::HelpInstructionsWidget *ui;
    QString language = "";
    QStringList instructionList = {"NOP", "MVI", "MOV", "LXI", "STAX", "SHLD", "STA", "INX", "INR", "DCR", "RLC", "RAL", "RRC", "RAR", "DAA", "STC", "DAD", "LDA", "LDAX", "LHLD", "CMC", "CMA", "HLT", "ADD", "SUB", "DCX", "ADC", "SBB", "ANA",
                                    "XRA", "ORA", "CMP", "RNZ", "RNC", "RPO", "RP", "POP", "PUSH", "ADI", "SUI", "ANI", "ORI", "ACI", "SBI", "XRI", "CPI", "OUT", "IN", "XTHL", "XCHG", "JNZ", "JNC", "JPO", "JP", "JMP", "CNZ", "CNC",
                                    "CPO", "CP", "RST", "RC", "RM", "RPE", "RZ", "RET", "PCHL", "JC", "JM", "JPE", "JZ", "CPE", "CC", "CM", "CZ", "CALL"};
};

#endif // HELPINSTRUCTIONSWIDGET_H
