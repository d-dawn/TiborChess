#include "bluetower.h"
#include <QTimer>
#include "bullet.h"
#include "game.h"
#include "triplearrow.h"
#include "enemy.h"
#include <typeinfo>

extern Game * game;



BlueTower::BlueTower(QGraphicsItem *parent)
{
    QPixmap blueenemy(":/images/blue.png");
    QPixmap newPixmap = blueenemy.scaled(QSize(50,50),  Qt::KeepAspectRatio);
    setPixmap(QPixmap(newPixmap));

    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(acquire_target()));
    timer->start(1500);
}

void BlueTower::fire()
{
    QList<QGraphicsItem *> collidin_items = attack_area->collidingItems();



    for (int i = 0, n = collidin_items.size(); i < n; ++i){
        if (typeid(*(collidin_items[i])) == typeid(Enemy)){

    triplearrow * bullet1 = new triplearrow();
    triplearrow * bullet2 = new triplearrow();
    triplearrow * bullet3 = new triplearrow();
    bullet1->setPixmap(QPixmap(":/images/arrow.png"));
    bullet2->setPixmap(QPixmap(":/images/arrow.png"));
    bullet3->setPixmap(QPixmap(":/images/arrow.png"));
    bullet1->setPos(x()+25,y()+25);
    bullet2->setPos(x()+25,y()+25);
    bullet3->setPos(x()+25,y()+25);

    QLineF ln(QPointF(x()+25,y()+25),attack_dest);
    int angle = -1 * ln.angle();

    bullet1->setRotation(angle);
    game->scene->addItem(bullet1);
    bullet2->setRotation(angle+10);
    game->scene->addItem(bullet2);
    bullet3->setRotation(angle-10);
    game->scene->addItem(bullet3);
}
    }
}

void BlueTower::aquire_target()
{
        Tower::acquire_target();
}
