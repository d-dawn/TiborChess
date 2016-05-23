#ifndef GAME_H
#define GAME_H

#include <QGraphicsView>
#include <QMouseEvent>
#include "Tower.h"
#include <QTimer>
#include "score.h"
#include "health.h"
#include "home.h"
#include "highscore.h"
#include <QPushButton>
#include "map.h"

class Game: public QGraphicsView{
    Q_OBJECT
public:
    // member functions
    Game();
    void mousePressEvent(QMouseEvent *event);
    void setCursor(QPixmap filename);
    void mouseMoveEvent(QMouseEvent *event);
    void createEnemies(int numberOfEnemies);
    // member attributes
    QGraphicsScene * scene;
    QGraphicsPixmapItem * cursor;
    Tower *build;
    QTimer * spawnTimer;
    int enemiesSpawned;
    int maxNumberOfEnemies;
    QList<QPointF> pointsToFollow;
    Score *score;
    Health * health;
    Highscore * hscore;
    int getShootdmg();
    int getSlowtime();
    int getBluedmg();

public slots:
    void spawnEnemy();
    void upgradesotw();
    void upgradeslow();
    void upgradeblue();
private:
    QPushButton *shoottw;
    QPushButton *slowtw;
    QPushButton *bluetw;
    map *tegla;
    int p;
    int shootdmg;
    int slowtime;
    int bluedmg;
};

#endif // GAME_H
