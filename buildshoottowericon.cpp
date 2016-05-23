#include "buildshoottowericon.h"
#include "game.h"
#include "shoottower.h"

extern Game * game;

BuildShootTowerIcon::BuildShootTowerIcon(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    QPixmap blueenemy(":/images/shoot.png");
    QPixmap newPixmap = blueenemy.scaled(QSize(50,50),  Qt::KeepAspectRatio);
    setPixmap(QPixmap(newPixmap));
}

void BuildShootTowerIcon::mousePressEvent(QGraphicsSceneMouseEvent *event)
{   if(game->score->getScore() >= 10){
    if(!game->build){
      game->build = new ShootTower();
      game->score->decrease(10);
      QPixmap blueenemy(":/images/shoot.png");
      QPixmap newPixmap = blueenemy.scaled(QSize(50,50),  Qt::KeepAspectRatio);
      setPixmap(QPixmap(newPixmap));





      game->setCursor(newPixmap);
    }
    else return;
    }
    else return;
}
