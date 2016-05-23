#ifndef SLOWTOWER_H
#define SLOWTOWER_H
#include "Tower.h"

class SlowTower : public Tower
{
    Q_OBJECT
public:
    SlowTower(QGraphicsItem * parent =0);
    void fire();
public slots:
    void aquire_target();
};

#endif // SLOWTOWER_H
