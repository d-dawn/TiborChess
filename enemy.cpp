#include "enemy.h"
#include <QPixmap>
#include <QTimer>
#include <QtMath>
#include <typeinfo>
#include "game.h"
#include "bullet.h"
#include "slowdart.h"
#include "triplearrow.h"
#include "home.h"

extern Game *game;

Enemy::Enemy(QList<QPointF> pointsToFollow,QGraphicsItem *parent)
{

 QPixmap blueenemy(":/images/red.png");
 QPixmap newPixmap = blueenemy.scaled(QSize(30,30),  Qt::KeepAspectRatio);
 setPixmap(QPixmap(newPixmap));
 points = pointsToFollow;
 point_index = 0;
 dest = points[0];
 rotateToPoint(dest);
 Health = 100;


 timer = new QTimer(this);
 connect(timer,SIGNAL(timeout()),this,SLOT(move_forward()));
         timer->start(200);
}

void Enemy::rotateToPoint(QPointF p)
{
    QLineF ln(pos(),p);
    setRotation(-1*ln.angle());
}

void Enemy::move_forward()
{
    QLineF ln(pos(),dest);
    if(ln.length() < 5){
     if(point_index<points.size()-1){
        point_index++;
        dest = points[point_index];
        rotateToPoint(dest);}
    }




    int STEP_SIZE = 5;
    double theta = rotation(); // degrees

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

     QList<QGraphicsItem *> colliding_items = collidingItems();

    for (int i = 0, n = colliding_items.size(); i < n; ++i){
         if (typeid(*(colliding_items[i])) == typeid(Bullet)){
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            this->set_Health(game->getShootdmg());
            if(this->Health <= 0){
            scene()->removeItem(this);
            delete this;
            game->score->increase();
            game->hscore->increase();
            }
            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(slowdart)){




            scene()->removeItem(colliding_items[i]);
            this->timer->start(60*game->getSlowtime());
            delete colliding_items[i];



            return;
        }
        if (typeid(*(colliding_items[i])) == typeid(Home)){


            if(game->health->getHealth()!=10){
            scene()->removeItem(this);
            delete this;
            game->health->decrease(10);}
            else{
                scene()->removeItem(this);
                delete this;
                game->health->decrease(10);
                delete (game);
                go = new gameover;
                go->show();


            }
            return;
        }

        if (typeid(*(colliding_items[i])) == typeid(triplearrow)){
            scene()->removeItem(colliding_items[i]);
            delete colliding_items[i];
            this->set_Health(game->getBluedmg());
            if(this->Health <= 0){
            scene()->removeItem(this);
            delete this;
            game->score->increase();
            game->hscore->increase();
            }




            return;
        }
    }
    setPos(x()+dx, y()+dy);
}

void Enemy::set_Health(int dmg)
{
    Health = Health-dmg;
}
