#include "home.h"

Home::Home(QGraphicsItem *parent)
{
    QPixmap blueenemy(":/images/home.png");
    QPixmap newPixmap = blueenemy.scaled(QSize(100,100),  Qt::KeepAspectRatio);
    setPixmap(QPixmap(newPixmap));




}
