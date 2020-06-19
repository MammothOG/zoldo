#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QKeyEvent>


class Unit;

class Adventure;

class Player;

class Level;

class PauseButton;

class GameScene : public QGraphicsScene
{
     Q_OBJECT
private:
    PauseButton * pauseButton;

    QGraphicsItemGroup * sceneElements;

    QGraphicsItemGroup * sceneProjectiles;

    QGraphicsItemGroup * uiView;

    QTimer * clock;

    Adventure * adventure;

    Player * player;

    Unit * enemyTargeted;

    Level * currentLevel;

public slots:
    void updateState();

    void onPause();

public:
    GameScene();

    void loadAdventure();

    void drawLevel();

    void updateUnitState();

    void updatePlayer();

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);

};

#endif // GAMESCENE_H
