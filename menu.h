#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include "game.h"
#include <QMouseEvent>

class menu : public QGraphicsView/*, public QMainWindow*/
{
    Q_OBJECT
public:
    menu();
    QGraphicsScene * menuscene;
private slots :
    void startButton();
    void kilepButton();
private:
    QPushButton * start;
    QPushButton * kilep;
};

#endif // MENU_H
