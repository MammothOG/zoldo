#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsView>
#include <QTimer>
#include <QKeyEvent>


class Adventure;

class Level;

class Player;

class Unit;

class GameEngine: public QGraphicsView
{
private:
    int windowWidth;

    int windowHeight;

protected:
    void mousePressEvent(QMouseEvent *event);

    void mouseReleaseEvent(QMouseEvent *event);

public:
    GameEngine();

};

#endif // GAMEENGINE_H
