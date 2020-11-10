#include <QGraphicsTextItem>
#include "game.h"
#include <QTimer>
#include "enemy.h"
#include <QImage>
#include <QBrush>
#include <QMediaPlayer>

Game::Game(QWidget *parent)
{
  scene = new QGraphicsScene();

  scene->setSceneRect(0,0,1280,720);
  scene->setBackgroundBrush(QBrush(QImage(":/images/Sprites/Background/espaço.jpg")));

  setScene(scene);

  setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  setFixedSize(1280,720);

  player = new Player();
  //player->setRect(0,0,80,80);
  player->setPos(300,500);

  player->setFlag(QGraphicsItem::ItemIsFocusable);
  player->setFocus();

  scene->addItem(player);

  QTimer * timer = new QTimer();
  QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
  timer->start(2000);
  score = new Score();
  scene->addItem(score);
  health = new Health();
  health->setPos(health->x(), health->y()+25);
  scene->addItem(health);

 music = new QMediaPlayer(this);
  music->setMedia(QUrl("qrc:/sounds/sounds/through space.mp3"));
  music->play();



  show();
}
