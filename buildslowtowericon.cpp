#include "buildslowtowericon.h"
#include "game.h"
#include "shoottower.h"
#include "slowtower.h"

extern Game * game;

BuildSlowTowerIcon::BuildSlowTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap blueenemy(":/images/water.png");
    QPixmap newPixmap = blueenemy.scaled(QSize(50,50),  Qt::KeepAspectRatio);
    setPixmap(QPixmap(newPixmap));
}

void BuildSlowTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{   if(game->score->getScore() >= 5){
    if(!game->build){
      game->build = new SlowTower();
      game->score->decrease(5);
      QPixmap blueenemy(":/images/water.png");
      QPixmap newPixmap = blueenemy.scaled(QSize(50,50),  Qt::KeepAspectRatio);
      setPixmap(QPixmap(newPixmap));





      game->setCursor(newPixmap);
    }
    }
}
