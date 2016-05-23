#include "score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
score = 0;
setPlainText(QString("Money: ") + QString::number(score));
setDefaultTextColor(Qt::green);
setFont(QFont("times",16));
setPos(650,30);
}

void Score::increase()
{
    score ++;
    setPlainText(QString("Money: ") + QString::number(score));
}

int Score::getScore()
{
    return score;
}

void Score::decrease(int price)
{
    score -= price;
    setPlainText(QString("Money: ") + QString::number(score));
}

void Score::setScore(int n)
{
    score += n;
    setPlainText(QString("Money: ") + QString::number(score));
}
