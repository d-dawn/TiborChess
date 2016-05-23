#ifndef SCORE_H
#define SCORE_H
#include <QGraphicsTextItem>


class Score: public QGraphicsTextItem
{
public:
    Score(QGraphicsItem *parent);
    void increase();
    int getScore();
    void decrease(int price);
    void setScore(int n);
private:
    int score;
};

#endif // SCORE_H
