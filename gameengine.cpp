#include <QDebug>

#include "gameengine.h"
#include "config.h"
#include "level.h"
#include "adventure.h"
#include "enemy.h"
#include "background.h"
#include "player.h"
#include "projectile.h"


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

    sceneProjectiles = new QGraphicsItemGroup();
    scene->addItem(sceneProjectiles);

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
    float minPlayerDistance = 2 * WIN_HEIGHT;

    for(Unit * unit: *currentLevel->getUnitList()){
        Enemy * enemy = dynamic_cast<Enemy*>(unit);

        int nextX = enemy->x() + enemy->getHorizontalMov();
        int nextY = enemy->y() + enemy->getVerticalMov();

        enemy->setPos(nextX, nextY);
        enemy->lockTarget(player);

        if (minPlayerDistance > enemy->getTargetDistance())
        {
          enemyTargeted = enemy;
        }

        for(Projectile * projectile: *enemy->getProjectileList()){
            int nextXProj = projectile->x() + projectile->getHorizontalMov();
            int nextYProj = projectile->y() + projectile->getVerticalMov();

            if (projectile->group()== nullptr)
            {
                sceneProjectiles->addToGroup(projectile);
            }

            projectile->setPos(nextXProj, nextYProj);
        }
    }
}

void GameEngine::updatePlayer()
{
    int nextXPlayer = player->x() + player->getHorizontalMov();
    int nextYPlayer = player->y() + player->getVerticalMov();

    player->setPos(nextXPlayer, nextYPlayer);
    if (enemyTargeted != nullptr)
        player->lockTarget(enemyTargeted);

    for(Projectile * projectile: *player->getProjectileList()){
        int nextXProj = projectile->x() + projectile->getHorizontalMov();
        int nextYProj = projectile->y() + projectile->getVerticalMov();

        if (projectile->group()== nullptr)
        {
            sceneProjectiles->addToGroup(projectile);
        }

        projectile->setPos(nextXProj, nextYProj);
    }
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


