#include "highscore.h"


Highscore::Highscore(QGraphicsItem *parent)
{
    score = 0;
    setPlainText(QString("Score: ") + QString::number(score));
    setDefaultTextColor(Qt::green);
    setFont(QFont("times",16));
    setPos(650,60);
}
void Highscore::increase()
{
    score ++;
    setPlainText(QString("Score: ") + QString::number(score));
}

int Highscore::getScore()
{
    return score;
}


void Highscore::setScore(int n)
{
    score += n;
    setPlainText(QString("Score: ") + QString::number(score));
}
