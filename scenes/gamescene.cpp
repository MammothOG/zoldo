#include "gamescene.h"

#include "config.h"
#include "core/player.h"
#include "core/adventure.h"
#include "core/level.h"
#include "core/enemy.h"
#include "core/unit.h"
#include "core/projectile.h"
#include "core/background.h"
#include "core/healthbar.h"
#include "elements/buttons/pausebutton.h"
#include "elements/buttons/restartbutton.h"
#include "elements/buttons/resumebutton.h"
#include "scenes/pausemenu.h"


#include <QDebug>
GameScene::GameScene()
{
    setSceneRect(0, 0, WIN_WIDTH, WIN_HEIGHT);
    setBackgroundBrush(Qt::black);

    sceneVerticalSize = BLOCK_SIZE*HORIZONTAL_BLOCK;
    sceneHorizontalSize = BLOCK_SIZE*VERTICAL_BLOCK;

    sceneElements = new QGraphicsItemGroup();
    addItem(sceneElements);

    sceneProjectiles = new QGraphicsItemGroup();
    addItem(sceneProjectiles);

    loadAdventure();

    pauseButton = new PauseButton();
    connect(pauseButton, SIGNAL(onPressClick()), this, SLOT(onPause()));
    pauseButton->setPos(BLOCK_SIZE*(HORIZONTAL_BLOCK-1), 0);
    addItem(pauseButton);

    pauseMenu = new PauseMenu();
    pauseMenu->setPos(WIN_WIDTH/2, WIN_HEIGHT/2);
    connect(pauseMenu->getResumeButton(), SIGNAL(onReleaseClick()), this, SLOT(onResume()));
    connect(pauseMenu->getRestartButton(), SIGNAL(onPressClick()), this, SLOT(onRestart()));

    clock  = new QTimer(this);
    connect(clock, SIGNAL(timeout()), this, SLOT(updateState()));
    clock->start(1000/FPS);
    setBackgroundBrush(Qt::black);
}

void GameScene::loadAdventure()
{
    adventure = new Adventure();
    // init TEST adventure
    adventure->generateTestAdventure();

    player = adventure->getPlayer();
    sceneElements->addToGroup(player);
    sceneElements->addToGroup(player->getHealthBar());

    Level * currentLevel = adventure->getCurrentLevel();
    player->setPos(currentLevel->getSpawnX(), currentLevel->getSpawnY());

    drawLevel();
}

void GameScene::drawLevel()
{
    currentLevel = adventure->getCurrentLevel();

    addItem(currentLevel->getBackground());

    if (currentLevel->getUnitList()->length() > 0)
        enemyTargeted = currentLevel->getUnitList()->at(0);
    else
        enemyTargeted = nullptr;

    for(Element * element : *currentLevel->getElementList()){
        sceneElements->addToGroup(element);
    }

    for(Unit * unit : *currentLevel->getUnitList()){
        sceneElements->addToGroup(unit);
    }
}

void GameScene::updateState()
{
    updatePlayer();
    updateUnitState();
}

void GameScene::updateUnitState()
{
    float minPlayerDistance = 2 * WIN_HEIGHT;

    for(Unit * unit: *currentLevel->getUnitList()){
        Enemy * enemy = dynamic_cast<Enemy*>(unit);

        checkCollision(enemy);

        enemy->moveUnit();

        enemy->lockTarget(player);

        if (minPlayerDistance > enemy->getTargetDistance())
        {
            enemyTargeted = enemy;
        }

        updateProjectile(enemy);
    }
}

void GameScene::updatePlayer()
{
    // TODO sometime crash (reopen fast)
    if (enemyTargeted != nullptr)
        player->lockTarget(enemyTargeted);

    for(Element * el: *currentLevel->getElementList()){
        player->isUnitColliding(el);
    }

    checkCollision(player);

    player->moveUnit();

    updateProjectile(player);

}

void GameScene::checkCollision(Unit * unit)
{
    for(Element * el: *currentLevel->getElementList()){
        unit->isUnitColliding(el);
    }
}

void GameScene::updateProjectile(UnitAnimate * unit)
{
    for(Projectile * projectile: *unit->getProjectileList()){
        // adding the projectile to the scene
        if (projectile->group()== nullptr)
        {
            sceneProjectiles->addToGroup(projectile);
        }

        // remove projectile if projectile is not in the scene or hit target
        if (!projectile->isInScene(sceneHorizontalSize, sceneVerticalSize))
        {
            removeItem(projectile);
            unit->getProjectileList()->removeOne(projectile);
            delete projectile;
        }

        projectile->moveUnit();
    }
}

void GameScene::onPause()
{
    qDebug() << "click in pause";
    addItem(pauseMenu);
}

void GameScene::onRestart()
{
    qDebug() << "click on restart";
}

void GameScene::onResume()
{
    qDebug() << "click on resume";
    removeItem(pauseMenu);
    pauseButton->setPressed(false);
}

void GameScene::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left){
        player->setHorizontalMov(- 1);
    }
    if (event->key() == Qt::Key_Right){
        player->setHorizontalMov(1);
    }
    if (event->key() == Qt::Key_Up){
        player->setVerticalMov(-1);
    }
    if (event->key() == Qt::Key_Down){
        player->setVerticalMov(1);
    }
}


void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left ||event->key() == Qt::Key_Right){
        player-> setHorizontalMov(0);
    }
    if (event->key() == Qt::Key_Up||event->key() == Qt::Key_Down){
        player-> setVerticalMov(0);
    }
}
