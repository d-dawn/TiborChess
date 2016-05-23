#ifndef BLUETOWER_H
#define BLUETOWER_H
#include "Tower.h"

class BlueTower : public Tower
{
    Q_OBJECT
public:
    BlueTower(QGraphicsItem * parent =0);
    void fire();
public slots:
    void aquire_target();
};

#endif // BLUETOWER_H
