#ifndef ENEMY_H
#define ENEMY_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QList> // list << element
#include <QPointF>
#include "gameover.h"

class Enemy: public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
    Enemy(QList<QPointF> pointsToFollow,QGraphicsItem * parent=0);
    void rotateToPoint(QPointF p);
public slots:
    void move_forward();
    void set_Health(int dmg);
private:
    QList<QPointF> points;
    QPointF dest;
    int point_index;
    int Health;
    QTimer * timer;
    gameover *go;
};

#endif // ENEMY_H
