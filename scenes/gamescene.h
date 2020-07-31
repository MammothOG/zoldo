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

class Projectile;

class Element;

class GameScene : public QGraphicsScene
{
     Q_OBJECT
private:
    int sceneHeight;

    int sceneWidth;

    PauseButton * pauseButton;

    PauseMenu * pauseMenu;

    QGraphicsItemGroup * levelElements;

    QGraphicsItemGroup * uiView;

    QTimer * clock;

    Adventure * adventure;

    Player * player;

    UnitAnimate * enemyTargeted;

    Level * currentLevel;

    float distancePlayerTarget;
signals:
    void signalQuitScene();

public slots:
    void updateState();

    void onPause();

    void onRestart();

    void onResume();

public:
    GameScene(QGraphicsView * sceneManger);

    ~GameScene();

    void loadAdventure();

    void drawLevel();

    void updateUnit(Unit * unit);

    void updateUnitAnimate(UnitAnimate * unitAnimate);

    void updateProjectile(UnitAnimate * unit);

    bool updateGame();

    void removeDeadUnit();

    void checkCollision(Unit * unit);

    void changeLevel();

    void keyPressEvent(QKeyEvent *event);

    void keyReleaseEvent(QKeyEvent *event);

};

#endif // GAMESCENE_H
