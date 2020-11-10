#include <QGraphicsScene>
#include <QTimer>
#include <QDebug>
#include "bullet.h"
#include "game.h"
#include <QList>
#include "enemy.h"
#include <QVector>
#include <QImage>

extern Game * game;
Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent)
{
   setPixmap(QPixmap(":/images/Sprites/Bullets/Bullet.png"));

 QTimer * timer = new QTimer();
 connect(timer,SIGNAL(timeout()),this,SLOT(move()));

 timer->start(50);
}
void Bullet::move()
{

 QList<QGraphicsItem *> colliding_item = collidingItems();
 for(int i = 0, n = colliding_item.size(); i < n; i++)
 {
 if(typeid(*(colliding_item[i]))== typeid(Enemy))
 {
    game->score->increase();
    this->setPixmap(QPixmap(":/images/Sprites/Bullets/explosion1.png"));
    scene()->removeItem(colliding_item[i]);
   // scene()->removeItem(this);
    delete colliding_item[i];
    delete this;
    return;
 }
 }

 setPos(x(),y()-10);

 if(pos().y() < -10)
 {
 scene()->removeItem(this);
 delete this;
 qDebug()<<"Bullet removed";
 }
}

