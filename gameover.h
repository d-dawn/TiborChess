#ifndef GAMEOVER_H
#define GAMEOVER_H


#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"
#include <QMouseEvent>
#include "menu.h"

class gameover : public QGraphicsView/*, public QMainWindow*/
{
    Q_OBJECT
public:
    gameover();
    QGraphicsScene * goscene;
private slots :
    void startButton();
private:
    QPushButton * start;
    menu * gomenu;
};
#endif // GAMEOVER_H
