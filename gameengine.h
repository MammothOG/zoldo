#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QGraphicsView>

#include "config.h"
#include "level.h"
#include "adventure.h"

class GameEngine: public QGraphicsView
{
    Q_OBJECT

private:
    QGraphicsScene * scene;

    QGraphicsItemGroup * mapPlan;

    int windowWidth;

    int windowHeight;

    Level * level;

public:
    GameEngine();

    ~GameEngine();

    void loadMap(QString MapName);

    void drawMap(Adventure map);
};

#endif // GAMEENGINE_H
