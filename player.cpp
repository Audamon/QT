#include "player.h"
#include <QGraphicsScene>
#include <QObject>
#include <QGraphicsItem>
#include <QDebug>
#include <QKeyEvent>
#include "bullet.h"
#include "enemy.h"
#include "health.h"
#include "game.h"
extern Game *game;

Player::Player(QGraphicsItem *parent): QGraphicsPixmapItem(parent)
{
    setPixmap(QPixmap(":/images/Sprites/Ship/Ship.png"));
    bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl("qrc:/sounds/sounds/SpaceShipShooting/Plasmabellshot.mp3"));
    movement = new QMediaPlayer();
    movement->setMedia(QUrl("qrc:/sounds/sounds/space_ship.mp3"));



}

void Player::keyPressEvent(QKeyEvent *event)
{

 //qDebug()<<"Key press detected";

 if(event->key() == Qt::Key_Left)
  {

  if(pos().x() > 0)
  setPos(x()-10,y());

     movement->play();
  }
  else if(event->key() == Qt::Key_Right)
  {

  if(pos().x() + 100 < 1080 )
  setPos(x()+10,y());

       movement->play();


  }
  else if(event->key() == Qt::Key_Up)
  {
  setPos(x(),y()-10);


       movement->play();

  }
  else if(event->key() == Qt::Key_Down)
  {
  setPos(x(),y()+10);



       movement->play();

  }
 else if(event->key() == Qt::Key_Space)
 {

 // qDebug()<<"Bullet created";
  Bullet * bullet = new Bullet();
  bullet->setPos(x()+65,y()-5);
  scene()->addItem(bullet);
  Bullet * bullet1 = new Bullet();
  bullet1->setPos(x()+115,y()-5);
  scene()->addItem(bullet1);
  if(bulletsound->state() == QMediaPlayer::PlayingState)
   {
       bulletsound->setPosition(0);
   }
   else if(bulletsound->state() == QMediaPlayer::StoppedState)
   {
       bulletsound->play();
   }

 }




}
void Player::spawn()
{


 if(game->health->getHealth() > 0)
 {
     Enemy * enemy = new Enemy();
     scene()->addItem(enemy);

 }

}


