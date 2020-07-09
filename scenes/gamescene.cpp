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
    sceneHeight = VERTICAL_BLOCK * BLOCKSIZE;
    sceneWidth = HORIZONTAL_BLOCK * BLOCKSIZE;

    setSceneRect(0, 0, sceneWidth, sceneHeight);
    setBackgroundBrush(Qt::black);

    sceneElements = new QGraphicsItemGroup();
    addItem(sceneElements);

    sceneProjectiles = new QGraphicsItemGroup();
    addItem(sceneProjectiles);

    loadAdventure();

//    pauseButton = new PauseButton();
//    connect(pauseButton, SIGNAL(onPressClick()), this, SLOT(onPause()));
//    pauseButton->setPos(BLOCKSIZE*(HORIZONTAL_BLOCK-1), 0);
//    addItem(pauseButton);
//
//    pauseMenu = new PauseMenu();
//    pauseMenu->setPos(WIN_WIDTH/2, WIN_HEIGHT/2);
//    connect(pauseMenu->getResumeButton(), SIGNAL(onReleaseClick()), this, SLOT(onResume()));
//    connect(pauseMenu->getRestartButton(), SIGNAL(onPressClick()), this, SLOT(onRestart()));

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

    HealthBar * playerHealthBar = new HealthBar();
    player->addHealthBar(playerHealthBar);
    sceneElements->addToGroup(playerHealthBar);

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
        HealthBar * unitHealthBar = new HealthBar();
        unit->addHealthBar(unitHealthBar);
        sceneElements->addToGroup(unit);
        sceneElements->addToGroup(unitHealthBar);
    }
}

void GameScene::updateState()
{
    updatePlayer();
    updateUnit();

    updateGame();
}

void GameScene::updatePlayer()
{
    // TODO sometime crash (reopen fast)
    if (enemyTargeted != nullptr)
        player->lockTarget(enemyTargeted);


    player->moveUnit();

    checkCollision(player);

    updateProjectile(player);
}

void GameScene::updateUnit()
{
    float minPlayerDistance = 2 * sceneHeight;

    for(Unit * unit: *currentLevel->getUnitList()){
        Enemy * enemy = dynamic_cast<Enemy*>(unit);
        if (!enemy->isDead()){

            enemy->moveUnit();

            checkCollision(enemy);

            enemy->lockTarget(player);

            if (minPlayerDistance > enemy->getTargetDistance())
            {
                enemyTargeted = enemy;
            }
        }
        else {
            removeElement(enemy);
        }

        updateProjectile(enemy);

    }
}

void GameScene::updateProjectile(UnitAnimate * unit)
{
    if (!unit->isDead()) {
        for(Projectile * projectile: *unit->getProjectileList()) {
            // adding the projectile to the scene
            if (projectile->group()== nullptr) {
                sceneProjectiles->addToGroup(projectile);
            }

            if (projectile->isColliding(player)) {}
            else if (!projectile->isInside()) {}
            else {
                for (Unit * enemy: * currentLevel->getUnitList()) {
                    projectile->isColliding(enemy);
                }
            }


            // remove projectile if projectile is not in the scene or hit target
            if (projectile->isDead()) {
                removeElement(projectile);
            }
            else {
                projectile->moveUnit();
            }
        }
    }
}

void GameScene::removeElement(Element *element)
{
    if (element->getType() == ENEMY) {
        Unit * unit = dynamic_cast<Unit*>(element);

        switch (element->getType()) {
        case ENEMY:
            currentLevel->getUnitList()->removeOne(unit);
            break;
        }

        removeItem(unit->getHealthBar());
    } else if(element->getType() == PROJECTILE) {

    }


    removeItem(element);

    delete element;
}

void GameScene::checkCollision(Unit * unit)
{
    for(Element * el: *currentLevel->getElementList()) {
        if (unit->isColliding(el))
        {
            if (el->getCollider()) {
                unit->stoneUnit();
            }
        }
    }
}

void GameScene::updateGame()
{
    if (currentLevel->getUnitList()->length() == 0) {
        player->setWon(true);
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
