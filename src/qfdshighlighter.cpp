#include "qfdshighlighter.h"

QFDSHighlighter::QFDSHighlighter(QTextDocument *parent) :
    QSyntaxHighlighter(parent)
{
    HighlightingRule rule;

    // comments
    singleLineCommentFormat.setForeground(colorTheme.commentColor);
    // TODO: fail pattern
    rule.pattern = QRegExp("^(?!\\&).*");
    rule.format = singleLineCommentFormat;
    highlightingRules.append(rule);

    // &ANY
    ampLineFormat.setForeground(colorTheme.ampColor);
    // TODO: fail pattern
    rule.pattern = QRegExp("\\&\\w*");
    rule.format = ampLineFormat;
    highlightingRules.append(rule);


    // numbers
    numberFormat.setForeground(colorTheme.numberColor);
    rule.pattern = QRegExp("\\d+\\.?\\d*");
    rule.format = numberFormat;
    highlightingRules.append(rule);
    numberFormatBad.setForeground(colorTheme.numberColor);
    rule.pattern = QRegExp("\\.\\d*");
    rule.format = numberFormatBad;
    highlightingRules.append(rule);

    // strings like 'sdsd'
    stringFormat.setForeground(colorTheme.stringColor);
    QString quotedString("%1([^%1]*(%1%1[^%1]*)*)(%1|$)");
    rule.format  = stringFormat;
    rule.pattern = QRegExp(quotedString.arg('"'), Qt::CaseInsensitive, QRegExp::RegExp2);
    highlightingRules.append(rule);
    rule.pattern = QRegExp(quotedString.arg('\''), Qt::CaseInsensitive, QRegExp::RegExp2);
    highlightingRules.append(rule);

    boolFormat.setForeground(colorTheme.boolColor);
    // TODO: fail pattern
    rule.pattern = QRegExp("\\.\\w*\\.");
    rule.format = boolFormat;
    highlightingRules.append(rule);

}

QFDSHighlighter::~QFDSHighlighter()
{

}

QHighlighterColorTheme QFDSHighlighter::getColorTheme() const
{
    return colorTheme;
}

void QFDSHighlighter::setColorTheme(const QHighlighterColorTheme &value)
{
    colorTheme = value;
}

void QFDSHighlighter::highlightBlock(const QString &text)
{
    if (!text.isEmpty()) {
        foreach (const HighlightingRule &rule, highlightingRules) {
            QRegExp expression(rule.pattern);
            int index = expression.indexIn(text);
            while (index >= 0) {
                int length = expression.matchedLength();
                setFormat(index, length, rule.format);
                index = expression.indexIn(text, index + length);
            }
        }
    }

}

