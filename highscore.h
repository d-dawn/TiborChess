#ifndef HIGHSCORE_H
#define HIGHSCORE_H
#include <QGraphicsTextItem>
#include <QFont>

class Highscore: public QGraphicsTextItem
{
public:
    Highscore(QGraphicsItem *parent);
    void increase();
    int getScore();
    void setScore(int n);
private:
    int score;
};

#endif // HIGHSCORE_H
