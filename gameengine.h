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

class GameEngine: public QGraphicsView
{
    Q_OBJECT

private:
    Player * player;

    QGraphicsScene * scene;

    QGraphicsItemGroup * sceneElements;

    QGraphicsItemGroup * sceneProjectiles;

    int windowWidth;

    int windowHeight;

    Adventure * adventure;

    Level * currentLevel;

    QTimer * clock;

public slots:
    void updateState();

public:
    GameEngine();

    ~GameEngine();

    void updatePlayer();

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);

    void loadAdventure();

    void drawLevel();

    void updateUnitState();



};

#endif // GAMEENGINE_H
