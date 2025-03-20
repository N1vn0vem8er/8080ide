#ifndef SYNTAXHIGHLIGHTER_H
#define SYNTAXHIGHLIGHTER_H
#include "qtextformat.h"
#include <QObject>
#include <QSyntaxHighlighter>
#include <QRegularExpression>

class SyntaxHighLighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    SyntaxHighLighter(QTextDocument *parent = 0);
    void setSpellChackEnabled(bool val);
    bool getSpellcheckEnabled() const;

protected:
    void highlightBlock(const QString &text) override;

private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QList<HighlightingRule> highlightingRules;
    QList<HighlightingRule> spellCheckRules;
    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;
    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
    QTextCharFormat spellCheckFormat;
    QTextCharFormat spellCheckMistakeFormat;
    QStringList labels;
    QStringList previousLabels;
    bool spellcheckEnabled = true;
public slots:
    void updateLabels(const QStringList& resoults);
};

#endif // SYNTAXHIGHLIGHTER_H
