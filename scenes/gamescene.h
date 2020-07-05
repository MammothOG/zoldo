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

class RestartButton;

class PauseMenu;

class UnitAnimate;

class GameScene : public QGraphicsScene
{
     Q_OBJECT
private:
    int sceneVerticalSize;

    int sceneHorizontalSize;

    PauseButton * pauseButton;

    PauseMenu * pauseMenu;

    QGraphicsItemGroup * sceneElements;

    QGraphicsItemGroup * sceneProjectiles;

    QGraphicsItemGroup * uiView;

    QTimer * clock;

    Adventure * adventure;

    Player * player;

    Unit * enemyTargeted;

    Level * currentLevel;

signals:
    void signalQuitScene();

public slots:
    void updateState();

    void onPause();

    void onRestart();

    void onResume();

public:
    GameScene();

    void loadAdventure();

    void drawLevel();

    void updateUnitState();

    void updatePlayer();

    void updateProjectile(UnitAnimate * enemy);

    void checkCollision(Unit * unit);

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);

};

#endif // GAMESCENE_H
