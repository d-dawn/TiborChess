#include "shoottower.h"
#include <QTimer>
#include "bullet.h"
#include "game.h"
#include "enemy.h"
#include <typeinfo>

extern Game * game;

ShootTower::ShootTower(QGraphicsItem *parent)
{
    QPixmap blueenemy(":/images/shoot.png");
    QPixmap newPixmap = blueenemy.scaled(QSize(50,50),  Qt::KeepAspectRatio);
    setPixmap(QPixmap(newPixmap));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer->start(2000);
}

void ShootTower::fire()
{
    QList<QGraphicsItem *> collidin_items = attack_area->collidingItems();



    for (int i = 0, n = collidin_items.size(); i < n; ++i){
        if (typeid(*(collidin_items[i])) == typeid(Enemy)){

    Bullet * bullet = new Bullet();
    bullet->setPos(x()+25,y()+25);

    QLineF ln(QPointF(x()+25,y()+25),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
        }
    }
}


void ShootTower::aquire_target()
{
    Tower::acquire_target();
}
