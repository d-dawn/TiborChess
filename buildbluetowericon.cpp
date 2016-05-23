#include "buildbluetowericon.h"
#include "game.h"
#include "shoottower.h"
#include "bluetower.h"

extern Game * game;

BuildBlueTowerIcon::BuildBlueTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap blueenemy(":/images/blue.png");
    QPixmap newPixmap = blueenemy.scaled(QSize(50,50),  Qt::KeepAspectRatio);
    setPixmap(QPixmap(newPixmap));
}

void BuildBlueTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{   if(game->score->getScore() >= 20){
    if(!game->build){
      game->build = new BlueTower();
      game->score->decrease(20);
      QPixmap blueenemy(":/images/blue.png");
      QPixmap newPixmap = blueenemy.scaled(QSize(50,50),  Qt::KeepAspectRatio);
      setPixmap(QPixmap(newPixmap));





      game->setCursor(newPixmap);
    }
    }
}

