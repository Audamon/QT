#include <QFont>
#include "health.h"
#include "game.h"


extern Game *game;
Health::Health(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
  health = 10;
  setPlainText(QString("Health: ") + QString::number(health));
  setDefaultTextColor(Qt::green);
  setFont(QFont("times",16));
}
void Health::decrease()
{
  health--;
  setPlainText(QString("Health: ") + QString::number(health));
  setDefaultTextColor(Qt::green);
  setFont(QFont("times",16));
  if(health<= 0 )
  {

     game->music->stop();
     game->health->setPos(this->x()+500,this->y()+250);
     setPlainText(QString("GAME OVER "));
     setDefaultTextColor(Qt::red);
     setFont(QFont("times",36));



  }

}
int Health::getHealth()
{
  return health;
}
