#ifndef QFDSHIGHLIGHTER_H
#define QFDSHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>
#include "qhighlightercolortheme.h"

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class QFDSHighlighter : public QSyntaxHighlighter
{
    Q_OBJECT

public:
    QFDSHighlighter(QTextDocument *parent = 0);
    ~QFDSHighlighter();

    QHighlighterColorTheme getColorTheme() const;
    void setColorTheme(const QHighlighterColorTheme &value);

protected:
    void highlightBlock(const QString &text) Q_DECL_OVERRIDE;


private:

    QHighlighterColorTheme colorTheme;
    struct HighlightingRule
    {
        QRegExp pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat ampLineFormat;
    QTextCharFormat stringFormat;
    QTextCharFormat numberFormat;
    QTextCharFormat numberFormatBad;
    QTextCharFormat boolFormat;
};

#endif // QFDSHIGHLIGHTER_H
