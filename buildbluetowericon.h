#ifndef BUILDBLUETOWERICON_H
#define BUILDBLUETOWERICON_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class BuildBlueTowerIcon : public QGraphicsPixmapItem
{
public:
    BuildBlueTowerIcon(QGraphicsItem * parent=0);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);
};

#endif // BUILDBLUETOWERICON_H
