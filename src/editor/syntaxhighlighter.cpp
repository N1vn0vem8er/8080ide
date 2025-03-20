#include "syntaxhighlighter.h"
#include "qtextdocument.h"
#include "idesettings.h"

SyntaxHighLighter::SyntaxHighLighter(QTextDocument *parent)
    : QSyntaxHighlighter(parent)
{
    HighlightingRule rule;
    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.lsm8bitInst), std::get<1>(IDESettings::syntaxHightlightingColors.lsm8bitInst), std::get<2>(IDESettings::syntaxHightlightingColors.lsm8bitInst)));
    const QString lsm8bitInst[] = { QStringLiteral("\\bMVI\\b"), QStringLiteral("\\bMOV\\b"), QStringLiteral("\\bSTAX\\b"), QStringLiteral("\\bLDAX\\b"), QStringLiteral("\\bLDA\\b"), QStringLiteral("\\bSTA\\b")};
    for(const QString& pattern : lsm8bitInst)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.jumpCallInst), std::get<1>(IDESettings::syntaxHightlightingColors.jumpCallInst), std::get<2>(IDESettings::syntaxHightlightingColors.jumpCallInst)));
    const QString jumpCallInst[] = {QStringLiteral("\\bRZN\\b"), QStringLiteral("\\bRZC\\b"), QStringLiteral("\\bRPO\\b"), QStringLiteral("\\bRP\\b"), QStringLiteral("\\bJNZ\\b"), QStringLiteral("\\bJNC\\b"),
                                   QStringLiteral("\\bJPO\\b"), QStringLiteral("\\bJP\\b"), QStringLiteral("\\bJMP\\b"), QStringLiteral("\\bCNZ\\b"), QStringLiteral("\\bCNC\\b"), QStringLiteral("\\bCPO\\b"),
                                   QStringLiteral("\\bCP\\b"), QStringLiteral("\\bRST\\b"), QStringLiteral("\\bRET\\b"), QStringLiteral("\\bPCHL\\b"), QStringLiteral("\\bRZ\\b"), QStringLiteral("\\bRC\\b"),
                                   QStringLiteral("\\bRPE\\b"), QStringLiteral("\\bRM\\b"), QStringLiteral("\\bJZ\\b"), QStringLiteral("\\bJC\\b"), QStringLiteral("\\bJPE\\b"), QStringLiteral("\\bJM\\b"),
                                   QStringLiteral("\\bCZ\\b"), QStringLiteral("\\bCC\\b"), QStringLiteral("\\bCPE\\b"), QStringLiteral("\\bCM\\b"), QStringLiteral("\\bCALL\\b"), QStringLiteral("\\bRNC\\b")};
    for(const QString& pattern : jumpCallInst)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.al8bitInst), std::get<1>(IDESettings::syntaxHightlightingColors.al8bitInst), std::get<2>(IDESettings::syntaxHightlightingColors.al8bitInst)));
    const QString al8bitInst[] = {QStringLiteral("\\bINR\\b"), QStringLiteral("\\bDCR\\b"), QStringLiteral("\\bRLC\\b"), QStringLiteral("\\bRAL\\b"), QStringLiteral("D\\bAA\\b"), QStringLiteral("\\bSTC\\b"),
                             QStringLiteral("\\bRRC\\b"), QStringLiteral("\\bRAR\\b"), QStringLiteral("\\bCMA\\b"), QStringLiteral("\\bCMC\\b"), QStringLiteral("\\bADD\\b"), QStringLiteral("\\bSUB\\b"),
                             QStringLiteral("\\bADC\\b"), QStringLiteral("\\bSBB\\b"), QStringLiteral("\\bANA\\b"), QStringLiteral("\\bXRA\\b"), QStringLiteral("\\bORA\\b"), QStringLiteral("\\bCMP\\b"),
                             QStringLiteral("\\bADI\\b"), QStringLiteral("\\bSUI\\b"), QStringLiteral("\\bANI\\b"), QStringLiteral("\\bORI\\b"), QStringLiteral("\\bACI\\b"), QStringLiteral("\\bSBI\\b"),
                             QStringLiteral("\\bXRI\\b"), QStringLiteral("\\bCPI\\b")};
    for(const QString& pattern : al8bitInst)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.lsm16bitInst), std::get<1>(IDESettings::syntaxHightlightingColors.lsm16bitInst), std::get<2>(IDESettings::syntaxHightlightingColors.lsm16bitInst)));
    const QString lsm16bitInst[] = {QStringLiteral("\\bLXI\\b"), QStringLiteral("\\bSHLD\\b"), QStringLiteral("\\bLHLD\\b"), QStringLiteral("\\bPOP\\b"), QStringLiteral("\\bPUSH\\b"), QStringLiteral("\\bSPHL\\b"), QStringLiteral("\\bXCHG\\b"),
                                    QStringLiteral("\\bXTHL\\b")};
    for(const QString& pattern : lsm16bitInst)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.miscInst), std::get<1>(IDESettings::syntaxHightlightingColors.miscInst), std::get<2>(IDESettings::syntaxHightlightingColors.miscInst)));
    const QString miscInst[] = {QStringLiteral("\\bNOP\\b"), QStringLiteral("\\bHLT\\b"), QStringLiteral("\\bOUT\\b"), QStringLiteral("\\bIN\\b"), QStringLiteral("\\bDI\\b"), QStringLiteral("\\bEI\\b")};
    for(const QString& pattern : miscInst)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.al16bitInst), std::get<1>(IDESettings::syntaxHightlightingColors.al16bitInst), std::get<2>(IDESettings::syntaxHightlightingColors.al16bitInst)));
    const QString al16bitInst[] = {QStringLiteral("\\bINX\\b"), QStringLiteral("\\bDAD\\b"), QStringLiteral("\\bDCX\\b")};
    for(const QString& pattern : al16bitInst)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }

    const QString macrosInst[] = {QStringLiteral("\\bSTRING\\b"), QStringLiteral("\\bARRAY\\b"), QStringLiteral("\\bEQU\\b"),
                                  QStringLiteral("\\bSET\\b"), QStringLiteral("\\bEND\\b"), QStringLiteral("\\bIF\\b"), QStringLiteral("\\bENDIF\\b"), QStringLiteral("\\bENDM\\b"), QStringLiteral("\\bMACRO\\b"), QStringLiteral("\\bDB\\b"),
                                  QStringLiteral("\\bDW\\b")};
    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.macrosInst), std::get<1>(IDESettings::syntaxHightlightingColors.macrosInst), std::get<2>(IDESettings::syntaxHightlightingColors.macrosInst)));

    for(const QString& pattern : macrosInst)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = keywordFormat;
        highlightingRules.append(rule);
    }
    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.chars), std::get<1>(IDESettings::syntaxHightlightingColors.chars), std::get<2>(IDESettings::syntaxHightlightingColors.chars)));
    rule.pattern = QRegularExpression(QStringLiteral("\'.*\'"));
    rule.format = keywordFormat;
    highlightingRules.append(rule);

    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.labels), std::get<1>(IDESettings::syntaxHightlightingColors.labels), std::get<2>(IDESettings::syntaxHightlightingColors.labels)));
    rule.pattern = QRegularExpression(QStringLiteral("[a-z|A-Z]*:"));
    rule.format = keywordFormat;
    highlightingRules.append(rule);

    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.comments), std::get<1>(IDESettings::syntaxHightlightingColors.comments), std::get<2>(IDESettings::syntaxHightlightingColors.comments)));
    rule.pattern = QRegularExpression(QStringLiteral("//.*"));
    rule.format = keywordFormat;
    highlightingRules.append(rule);

    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.chars), std::get<1>(IDESettings::syntaxHightlightingColors.chars), std::get<2>(IDESettings::syntaxHightlightingColors.chars)));
    rule.pattern = QRegularExpression(QStringLiteral("\".*\""));
    rule.format = keywordFormat;
    highlightingRules.append(rule);
    keywordFormat.setForeground(QColor::fromRgba64(std::get<0>(IDESettings::syntaxHightlightingColors.comments), std::get<1>(IDESettings::syntaxHightlightingColors.comments), std::get<2>(IDESettings::syntaxHightlightingColors.comments)));
    rule.pattern = QRegularExpression(QStringLiteral(";.*"));
    rule.format = keywordFormat;
    highlightingRules.append(rule);

    const QString spellCheck[] = {QStringLiteral("^([a-z|A-Z]*:\\s|\\tMVI\\s[A-EHML]\\,.*)|MVI\\s[A-EHML]\\,.*$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(MOV\\s[A-EHML]\\,[A-EHML])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(STAX\\s[BD])((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(LDAX\\s[BD])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(LDA\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(STA\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RPO\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RP\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(JNZ\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(JNC\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(JPO\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(JP\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(JMP\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CZN\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CNC\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CPO\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CP\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RST\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RET\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(PCHL)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RZ\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RC\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RPE\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RM\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(JZ\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(JC\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(JPE\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(JM\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CZ\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CC\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CPE\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CM\\s.*)((\\s|\\t)\\;.*)?$" ),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CALL\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(INR\\s[A-EHML])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(DCR\\s[A-EHML])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RLC$)((\\s|\\t)\\;.*)?") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RAL\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(DAA$)((\\s|\\t)\\;.*)?") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(STC$)((\\s|\\t)\\;.*)?") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RRC)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RAR)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CMA)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CMC\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(ADD\\s[A-EHML])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(SUB\\s[A-EHML])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(ADC\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(SBB\\s[A-EHML])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(ANA\\s[A-EHML])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(XRA\\s[A-EHML])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(ORA\\s[A-EHML])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CMP\\s[A-EHML])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(ADI\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(SUI\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(ANI\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(ORI\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(ACI\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(SBI\\s.)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(XRI\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(CPI\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(LXI\\s([A-EHML]|SP)\\,.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(SHLD\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(LHLD\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(POP\\s[BDH])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(PUSH\\s[BDH])((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(SPHL)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(XCHG)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(XTHL)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(NOP)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(HLT)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(OUT\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(IN\\s.*)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(DI)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(EI)((\\s|\\t)\\;.*)?$") ,
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(RNC)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(INX\\s([BDH]|SP))((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(DAD\\s([A-EHML]|SP))((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(DCX\\s([BDH]|SP))((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^\\.*$"),
                                  QStringLiteral("^\\:.*$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(STRING\\s\".*\")((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(ARRAY\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(EQU\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(SET\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(END)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(IF\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^ENDIF((\\s|\\t)\\;.*)$"),
                                  QStringLiteral("^ENDM((\\s|\\t)\\;.*)$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)(MACRO)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(DB\\s.*)((\\s|\\t)\\;.*)?$"),
                                  QStringLiteral("^(([a-z]|[A-Z])*:\\s|\\t)?(DW\\s.*)((\\s|\\t)\\;.*)?$")};
    for(const QString& pattern : spellCheck)
    {
        rule.pattern = QRegularExpression(pattern);
        rule.format = spellCheckFormat;
        spellCheckRules.append(rule);
    }
    spellCheckMistakeFormat.setUnderlineColor(Qt::red);
    spellCheckMistakeFormat.setUnderlineStyle(QTextCharFormat::SpellCheckUnderline);
}

void SyntaxHighLighter::setSpellChackEnabled(bool val)
{
    spellcheckEnabled = val;
}
void SyntaxHighLighter::highlightBlock(const QString &text)
{
    if(spellcheckEnabled)
    {
        setFormat(0, text.length(), spellCheckMistakeFormat);
        for(const HighlightingRule& rule : std::as_const(spellCheckRules))
        {
            QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
            while(matchIterator.hasNext())
            {
                QRegularExpressionMatch match = matchIterator.next();
                setFormat(match.capturedStart(), match.capturedLength(), rule.format);
            }
        }
    }
    for(const HighlightingRule& rule : std::as_const(highlightingRules))
    {
        QRegularExpressionMatchIterator matchIterator = rule.pattern.globalMatch(text);
        while(matchIterator.hasNext())
        {
            QRegularExpressionMatch match = matchIterator.next();
            setFormat(match.capturedStart(), match.capturedLength(), rule.format);
        }
    }
}

bool SyntaxHighLighter::getSpellcheckEnabled() const
{
    return spellcheckEnabled;
}

void SyntaxHighLighter::updateLabels(const QStringList &resoults)
{
    bool labelsChanged = false;
    HighlightingRule rule;
    for(const QString& i : previousLabels)
    {
        if(!resoults.contains(i))
        {
            labelsChanged = true;
            labels.removeAll(i);
            QString pattern = QString("^.*%1\\b").arg(i);
            spellCheckRules.erase(std::remove_if(spellCheckRules.begin(), spellCheckRules.end(), [=](HighlightingRule r){return r.pattern == QRegularExpression(pattern);}));
        }
    }
    for(const QString& i : resoults)
    {
        if(labels.contains(i))
            continue;
        QString pattern = QString("^.*%1\\b").arg(i);
        rule.pattern = QRegularExpression(pattern);
        rule.format = spellCheckFormat;
        spellCheckRules.append(rule);
        labels.append(i);
    }
    previousLabels = labels;
    if(labelsChanged)
        rehighlight();
}
