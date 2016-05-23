#ifndef HOME_H
#define HOME_H

#include <QGraphicsPixmapItem>
#include <QGraphicsPolygonItem>
#include <QGraphicsItem>
#include <QObject>
#include <QPointF>


class Home :public QObject, public QGraphicsPixmapItem{
    Q_OBJECT
public:
   Home(QGraphicsItem * parent=0);
};

#endif // HOME_H
