#include "gameover.h"

gameover::gameover() :QGraphicsView()/*, QMainWindow()*/
{
QPixmap blueenemy(":/images/dark-souls-you-died.jpg");
QPixmap newPixmap = blueenemy.scaled(QSize(800,600));
//setPixmap(QPixmap(newPixmap));


start = new QPushButton("Vissza a menube",this);
connect(start, SIGNAL (clicked()), this, SLOT (startButton()));
start->setGeometry(QRect(QPoint(315, 425),QSize(200, 50)));

goscene = new QGraphicsScene(this);
goscene->setSceneRect(0,0,800,600);
setScene(goscene);
goscene->addPixmap(newPixmap);
}

void gameover::startButton()
{
    delete(this);
    gomenu = new menu;
    gomenu->show();
}

