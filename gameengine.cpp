#include <QDebug>

#include "gameengine.h"
#include "config.h"
#include "level.h"
#include "adventure.h"
#include "enemy.h"
#include "background.h"
#include "player.h"


GameEngine::GameEngine()
{
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    windowWidth = WIN_WIDTH;
    windowHeight = WIN_HEIGHT;

    setWindowTitle(TITLE);
    resize(windowWidth, windowHeight);

    // create the scene
    scene = new QGraphicsScene(0, 0, WIN_WIDTH, WIN_HEIGHT);
    scene->setBackgroundBrush(Qt::black);

    sceneElements = new QGraphicsItemGroup();
    scene->addItem(sceneElements);

    loadAdventure();

    clock  = new QTimer(this);
    connect(clock, SIGNAL(timeout()), this, SLOT(updateState()));
    clock->start(1000/FPS);
}

GameEngine::~GameEngine()
{

}


void GameEngine::drawLevel()
{
    Level * level = adventure->getCurrentLevel();

    scene->addItem(level->getBackground());

    for(Element * element : *level->getElementList()){
        sceneElements->addToGroup(element);
    }

    for(Unit * unit : *level->getUnitList()){
        sceneElements->addToGroup(unit);
    }
}

void GameEngine::loadAdventure()
{
    adventure = new Adventure();
    // init TEST adventure
    adventure->generateTestAdventure();

    player = adventure->getPlayer();
    sceneElements->addToGroup(player);

    currentLevel = adventure->getCurrentLevel();
    player->setPos(currentLevel->getSpawnX(), currentLevel->getSpawnY());

    drawLevel();
    setScene(scene);
}

void GameEngine::updateState()
{
    updatePlayer();
    updateUnitState();
}

void GameEngine::updateUnitState()
{
    for(Unit * unit: *currentLevel->getUnitList()){
        Enemy * enemy = dynamic_cast<Enemy*>(unit);

        int nextX = enemy->x() + enemy->getHorizontalMov();
        int nextY = enemy->y() + enemy->getVerticalMov();

        enemy->setPos(nextX, nextY);
        enemy->lockTarget(player);

    }
}

void GameEngine::updatePlayer()
{
    int nextX = player->x() + player->getHorizontalMov();
    int nextY = player->y() + player->getVerticalMov();

    player->setPos(nextX, nextY);
}

void GameEngine::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        player->setHorizontalMov(- 1);
    }
    else if (event->key() == Qt::Key_Right){
        player->setHorizontalMov(1);

    }
    else if (event->key() == Qt::Key_Up){
        player->setVerticalMov(-1);
    }

    else if (event->key() == Qt::Key_Down){
        player->setVerticalMov(1);
    }
}


void GameEngine::keyReleaseEvent(QKeyEvent *event)
{
    //qDebug() << "key released" ;
    if (event->key() == Qt::Key_Left ||event->key() == Qt::Key_Right){
        player-> setHorizontalMov(0);
    }
    else if (event->key() == Qt::Key_Up||event->key() == Qt::Key_Down){
        player-> setVerticalMov(0);
    }
}
