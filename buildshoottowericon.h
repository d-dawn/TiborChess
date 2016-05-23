#ifndef BUILDTOWERICON_H
#define BUILDTOWERICON_H
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>


class BuildShootTowerIcon : public QGraphicsPixmapItem
{
public:
    BuildShootTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // BUILDTOWERICON_H
