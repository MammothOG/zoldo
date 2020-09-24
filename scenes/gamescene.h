#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QGraphicsScene>
#include <QGraphicsItemGroup>
#include <QTimer>
#include <QKeyEvent>
#include <QMediaPlayer>


class Unit;

class Adventure;

class Player;

class Level;

class QuitButton;

class UnitAnimate;

class Projectile;

class Element;

class EndGameVisual;

class GameScene : public QGraphicsScene
{
     Q_OBJECT
private:
    int sceneHeight;

    int sceneWidth;

    bool successLoaded;

    QuitButton * quitButton;

    QGraphicsItemGroup * levelElements;

    QGraphicsItemGroup * uiView;

    EndGameVisual * endGameVisual;

    QTimer * clock;

    Adventure * adventure;

    Player * player;

    UnitAnimate * enemyTargeted;

    Level * currentLevel;

    float distancePlayerTarget;

    QMediaPlayer * bgMusic;

signals:
    void signalQuitScene();

public slots:
    void updateState();

public:
    GameScene(QGraphicsView * sceneManager);

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

    bool getSuccessLoaded() const;

    void setSuccessLoaded(bool value);
};

#endif // GAMESCENE_H
