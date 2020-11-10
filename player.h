#ifndef PLAYER_H
#define PLAYER_H

#include <QGraphicsPixmapItem>
#include <QObject>
#include <QGraphicsItem>
#include <QMediaPlayer>
#include <QMediaPlaylist>

class Player: public QObject, public QGraphicsPixmapItem
{
 Q_OBJECT
public:
 Player(QGraphicsItem * parent=0);
 void keyPressEvent(QKeyEvent * event);

public slots:
 void spawn();

private:
 QMediaPlayer * bulletsound;
 QMediaPlayer * movement;

};
#endif // PLAYER_H
