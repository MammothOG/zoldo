#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsView>

#include "config.h"

class GameEngine: public QGraphicsView
{
    Q_OBJECT

private:
    QGraphicsScene * levelScene;

    QGraphicsItemGroup * gamePlan;

    int windowWidth;

    int windowHeight;

public:
    GameEngine();

    ~GameEngine();
};

#endif // GAMEENGINE_H
