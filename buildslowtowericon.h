#ifndef BUILDSLOWTOWERICON_H
#define BUILDSLOWTOWERICON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildSlowTowerIcon : public QGraphicsPixmapItem
{
public:
    BuildSlowTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // BUILDSLOWTOWERICON_H
