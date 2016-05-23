#ifndef MAP_H
#define MAP_H


#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QObject>
#include <QPointF>


class map: public QGraphicsRectItem{
public:
    map(QGraphicsRectItem * parent=0);

};

#endif // MAP_H
