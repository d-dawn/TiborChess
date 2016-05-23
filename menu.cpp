#include "menu.h"
extern Game *game;

menu::menu() :QGraphicsView()/*, QMainWindow()*/
{
start = new QPushButton("Start",this);
connect(start, SIGNAL (clicked()), this, SLOT (startButton()));
start->setGeometry(QRect(QPoint(100, 50),QSize(200, 50)));

kilep = new QPushButton("Kilep",this);
connect(kilep, SIGNAL (clicked()), this, SLOT (kilepButton()));
kilep->setGeometry(QRect(QPoint(100, 100),QSize(200, 50)));

menuscene = new QGraphicsScene(this);
menuscene->setSceneRect(0,0,400,400);
setScene(menuscene);
}

void menu::startButton()
{
    delete(this);
    game = new Game;
    game->show();
}
void menu::kilepButton()
{

    delete(this);
}
//menuscene->addItem(QGraphicsItem:: start);


