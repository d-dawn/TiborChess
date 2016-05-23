#include <QApplication>
#include "Game.h"
#include "menu.h"



Game * game;
menu * alma;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

   // game = new Game();
    //game->show();
    alma = new menu();
    alma->show();

    return a.exec();
}
