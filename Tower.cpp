#include "Tower.h"
#include <QPixmap>
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include "Bullet.h"
#include <QPointF>
#include <QLineF>
#include "Game.h"
#include <QTimer>
#include <QGraphicsRectItem>
#include "enemy.h"

extern Game * game;

Tower::Tower(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    QVector<QPointF> points;
    points << QPoint(1,0) << QPoint(2,0) << QPoint(3,1) << QPoint(3,2) << QPoint(2,3)
               << QPoint(1,3) << QPoint(0,2) << QPoint(0,1);

    int SCALE_FACTOR = 75;
    for (size_t i = 0, n = points.size(); i < n; i++){
        points[i] *= SCALE_FACTOR;
    }

    attack_area = new QGraphicsPolygonItem(QPolygonF(points),this);
    attack_area->setPen(QPen(Qt::DotLine));

    QPointF poly_center(1.5,1.5);
    poly_center *= SCALE_FACTOR;
    poly_center = mapToScene(poly_center);;
    QPointF tower_center(x()+25,y()+25);
    QLineF ln(poly_center,tower_center);
    attack_area->setPos(x()+ln.dx(),y()+ln.dy());


    attack_dest = QPointF(800,600);
}

double Tower::distanceTo(QGraphicsItem *item)
{
    QLineF ln(pos(),item->pos());
    return ln.length();
}

void Tower::fire()
{
    Bullet * bullet = new Bullet();
    bullet->setPos(x()+50,y()+50);

    QLineF ln(QPointF(x()+50,y()+50),attack_dest);
    int angle = -1 * ln.angle();

    bullet->setRotation(angle);
    game->scene->addItem(bullet);
}

void Tower::acquire_target()
{
    QList<QGraphicsItem *> collidin_items = attack_area->collidingItems();

    if(collidin_items.size() == 1){
        has_target = false;
        return;
    }

    double closest_dist = 300;
    QPointF closest_pt = QPoint(0,0);
    for (size_t i = 0, n = collidin_items.size(); i < n ; i++){
        Enemy * enemy = dynamic_cast<Enemy *>(collidin_items[i]);
        if (enemy){
            double this_dist = distanceTo(enemy);
            if(this_dist < closest_dist){
                closest_dist = this_dist;
                closest_pt = collidin_items[i]->pos();
                has_target = true;
            }
        }
    }
    attack_dest = closest_pt;
    fire();
}
