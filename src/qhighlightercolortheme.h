#ifndef QHIGHLIGHTERCOLORTHEME_H
#define QHIGHLIGHTERCOLORTHEME_H
#include <QColor>
#include <QFont>


class QHighlighterColorTheme
{
public:
    QHighlighterColorTheme();

    QColor commentColor = QColor(255, 255, 255);
    QColor ampColor = QColor(140, 20, 30);
    QColor stringColor = QColor(20, 70, 140);
    QColor numberColor = QColor(200, 160, 20);
    QColor boolColor = QColor(150, 20, 200);
};

#endif // QHIGHLIGHTERCOLORTHEME_H
