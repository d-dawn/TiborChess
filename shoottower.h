#ifndef SHOOTTOWER_H
#define SHOOTTOWER_H
#include "Tower.h"

class ShootTower : public Tower
{
    Q_OBJECT
public:
    ShootTower(QGraphicsItem * parent =0);
    void fire();
public slots:
    void aquire_target();
private :
};

#endif // SHOOTTOWER_H
