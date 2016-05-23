#ifndef HEALTH_H
#define HEALTH_H


#include <QGraphicsTextItem>
#include <QFont>


class Health: public QGraphicsTextItem
{
public:
    Health(QGraphicsItem *parent);
    void increase();
    int getHealth();
    void decrease(int price);
    void setHealth(int n);
private:
    int health;
};

#endif // HEALTH_H
