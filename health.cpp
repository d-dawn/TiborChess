#include "health.h"

Health::Health(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
health = 0;
setPlainText(QString("Health: ") + QString::number(health));
setDefaultTextColor(Qt::green);
setFont(QFont("times",16));
setPos(650,0);
}

void Health::increase()
{
    health ++;
    setPlainText(QString("Health: ") + QString::number(health));
}

int Health::getHealth()
{
    return health;
}

void Health::decrease(int dmg)
{
    health -= dmg;
    setPlainText(QString("Health: ") + QString::number(health));
}

void Health::setHealth(int n)
{
    health += n;
    setPlainText(QString("Health: ") + QString::number(health));
}
