#include "Game.h"
#include <QGraphicsScene>
#include "Tower.h"
#include "Bullet.h"
#include "enemy.h"
#include "buildshoottowericon.h"
#include <QGraphicsPixmapItem>
#include "shoottower.h"
#include "buildbluetowericon.h"
#include "buildslowtowericon.h"
#include <typeinfo>
Game::Game(): QGraphicsView(){
    QPixmap blueenemy(":/images/map.jpg");
    QPixmap newPixmap = blueenemy.scaled(QSize(800,600));

    p=0;
    shootdmg = 60;
    bluedmg = 35;
    slowtime = 5;


    scene = new QGraphicsScene(this);
    scene->setSceneRect(0,0,800,600);

    setScene(scene);
    scene->addPixmap(newPixmap);

    shoottw = new QPushButton("Upgrade(20)",this);
    connect(shoottw, SIGNAL (clicked()), this, SLOT (upgradesotw()));
    shoottw->setGeometry(QRect(QPoint(50, 5),QSize(75, 25)));

    bluetw = new QPushButton("Upgrade(40)",this);
    connect(bluetw, SIGNAL (clicked()), this, SLOT (upgradeblue()));
    bluetw->setGeometry(QRect(QPoint(50, 55),QSize(75, 25)));

    slowtw = new QPushButton("Upgrade(10)",this);
    connect(slowtw, SIGNAL (clicked()), this, SLOT (upgradeslow()));
    slowtw->setGeometry(QRect(QPoint(50, 105),QSize(75, 25)));



    cursor = nullptr;
    build = nullptr;
    setMouseTracking(true);

    setFixedSize(800,600);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    spawnTimer = new QTimer(this);
    enemiesSpawned = 0;
    maxNumberOfEnemies = 0;
    pointsToFollow << QPointF(800,340) << QPointF(0,340);

    score = new Score(0);
    score->setScore(30);
    scene->addItem(score);
    health = new Health(0);
    health->setHealth(100);
    scene->addItem(health);
    hscore = new Highscore(0);
    scene->addItem(hscore);
    tegla = new map;
    scene->addItem(tegla);

    createEnemies(10);

    BuildShootTowerIcon *sic = new BuildShootTowerIcon();
    scene->addItem(sic);
    BuildBlueTowerIcon *bic = new BuildBlueTowerIcon();
    BuildSlowTowerIcon *slic = new BuildSlowTowerIcon();
    Home * home = new Home();
    home->setPos(x()-10,y()+270);
    scene->addItem(home);

   bic->setPos(x(),y()+50);
   slic->setPos(x(),y()+100);
   scene->addItem(bic);
   scene->addItem(slic);

}

void Game::mousePressEvent(QMouseEvent *event){
 if(build){
     QList<QGraphicsItem *> items = cursor->collidingItems();
     for(size_t i=0,n = items.size();i<n; i++){
         if (dynamic_cast<Tower*>(items[i])){
             return;
         }

         if (dynamic_cast<map*>(items[i])){
             return;
         }


     }
     scene->addItem(build);
     build->setPos(event->pos());
     cursor = nullptr;
     build = nullptr;
 }
 else {
     QGraphicsView::mousePressEvent(event);
 }

}

void Game::setCursor(QPixmap filename)
{
    if (cursor){
        scene->removeItem(cursor);
        delete cursor;
    }
    cursor = new QGraphicsPixmapItem();
    cursor->setPixmap(filename);
    scene->addItem(cursor);
}

void Game::mouseMoveEvent(QMouseEvent *event)
{
    if(cursor){
        cursor->setPos(event->pos());
    }
}

void Game::createEnemies(int numberOfEnemies)
{
    maxNumberOfEnemies = numberOfEnemies;
    connect(spawnTimer,SIGNAL(timeout()),this,SLOT(spawnEnemy()));
    spawnTimer->start(1500);
}

int Game::getShootdmg()
{
 return shootdmg;
}

int Game::getSlowtime()
{
 return slowtime;
}

int Game::getBluedmg()
{
return bluedmg;
}

void Game::spawnEnemy()
{
Enemy * enemy = new Enemy(pointsToFollow);
enemy->setPos(pointsToFollow[0]);
enemy->set_Health(-p);
p += 3;
scene->addItem(enemy);
enemiesSpawned +=1;

if(health->getHealth() <=0){
    spawnTimer->disconnect();
}
}

void Game::upgradesotw()
{
 if(score->getScore()>=20){
 shootdmg = shootdmg*1.5;
 score->decrease(20);
 }
}

void Game::upgradeslow()
{
 if(score->getScore()>=10){
 slowtime = slowtime+1;
 score->decrease(10);
 }
}

void Game::upgradeblue()
{
 if(score->getScore()>=40){
 bluedmg = bluedmg*1.5 ;
 score->decrease(40);
 }
}
