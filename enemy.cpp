#include <QTimer>
#include <QGraphicsScene>
#include <stdlib.h>
#include <QDebug>
#include "enemy.h"
#include "game.h"
extern Game * game;
Enemy::Enemy()
{
 // posição aleatoria
 int random_number = rand() % 1000;
 setPos(random_number,0);
 // desenhar o inimigo
 setPixmap(QPixmap(":/images/Sprites/Enemies/Enemy1.png"));
 //movimentação
 QTimer * timer = new QTimer();
 connect(timer, SIGNAL(timeout()), this, SLOT(move()));
 timer->start(50);
}
void Enemy::move()
{
  setPos(x(),y()+5);
  if(pos().y() > 720)
  {
   game->health->decrease();
   scene()->removeItem(this);
   delete this;
   qDebug()<<"Enemy removed";
  }
  QList<QGraphicsItem *> colliding_item = collidingItems();
  for(int i = 0, n = colliding_item.size(); i < n; i++)
  {
  if(typeid(*(colliding_item[i]))== typeid(Player))
  {
  game->health->decrease();


  scene()->removeItem(this);

  delete this;
  return;
  }
  }
}


