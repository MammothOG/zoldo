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


GameScene::GameScene()
{
    sceneHeight = VERTICAL_BLOCK * BLOCKSIZE;
    sceneWidth = HORIZONTAL_BLOCK * BLOCKSIZE;

    setSceneRect(0, 0, sceneWidth, sceneHeight);
    setBackgroundBrush(Qt::black);


    adventure = new Adventure();
    adventure->load("testadventure");
    //adventure->generateTestAdventure();
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
    player = adventure->getPlayer();
    addItem(player);

    HealthBar * playerHealthBar = new HealthBar();
    player->addHealthBar(playerHealthBar);
    addItem(playerHealthBar);

    currentLevel = adventure->getCurrentLevel();

    drawLevel();
}

void GameScene::drawLevel()
{
    levelElements = new QGraphicsItemGroup();
    addItem(levelElements);

    player->setPos(currentLevel->getSpawnX(), currentLevel->getSpawnY());

    currentLevel = adventure->getCurrentLevel();

    levelElements->addToGroup(currentLevel->getBackground());

    if (currentLevel->getUnitList()->length() > 0)
        enemyTargeted = currentLevel->getUnitList()->at(0);
    else
        enemyTargeted = nullptr;

    for(Element * element : *currentLevel->getElementList()){
        levelElements->addToGroup(element);
    }

    for(Unit * unit : *currentLevel->getUnitList()){
        HealthBar * unitHealthBar = new HealthBar();
        unit->addHealthBar(unitHealthBar);
        levelElements->addToGroup(unitHealthBar);

        unit->setCenterAsReferencial();
        levelElements->addToGroup(unit);
    }
}

void GameScene::updateState()
{
    updateUnit(player);

    for(Unit * unit: *currentLevel->getUnitList()){
        updateUnit(unit);
        //qDebug() << unit->getHealth();
    }

    removeDeadUnit();

    updateGame();
}

void GameScene::updateUnit(Unit * unit)
{
    unit->moveUnit();

    checkCollision(unit);

    if (unit->isType(UNIT_ANIMATE) && enemyTargeted != nullptr) {
        updateUnitAnimate(dynamic_cast<UnitAnimate*>(unit));
    }
}

void GameScene::updateUnitAnimate(UnitAnimate * unitAnimate)
{
    if (unitAnimate->isType(PLAYER)) {
        unitAnimate->lockTarget(enemyTargeted);

    } else if (unitAnimate->isType(ENEMY)) {
        // move to class
        float minPlayerDistance = 2 * sceneHeight;
        // end

        unitAnimate->lockTarget(player);

        if (minPlayerDistance > unitAnimate->getTargetDistance()) {
            enemyTargeted = unitAnimate;
        }

    }

    updateProjectile(unitAnimate);
}

void GameScene::updateProjectile(UnitAnimate * unit)
{
    for(Projectile * projectile: *unit->getProjectileList()) {
        // adding the projectile to the scene
        if (projectile->group()== nullptr) {
            levelElements->addToGroup(projectile);
        }

        // check if projectile hit unit
        projectile->isColliding(player);

        for (Unit * enemy: * currentLevel->getUnitList()) {
            projectile->isColliding(enemy);
        }

        // check if projectil is inside the scene
        projectile->isInside();

        // move the projectile
        if (!projectile->isDead())
            projectile->moveUnit();
    }
}

void GameScene::updateGame()
{
    if (!player->isLeavingLevel()) {
        if (currentLevel->getUnitList()->length() == 0) {
        // if no more ennemies activate all exit
        for (Element * el: * currentLevel->getElementList()) {
            if (el->isExit()) {
            el->activate();
            }
        }
        }
        else if (player->isDead()) {
            clock->stop();
        }
    }
    else {
        qDebug() << "leave level";
        player->setLeavingLevel(false);
        removeItem(levelElements);
        adventure->nextLevel();
        currentLevel = adventure->getCurrentLevel();

        drawLevel();
    }

}

void GameScene::removeDeadProjectile(UnitAnimate * unit)
{
    for(Projectile * projectile: *unit->getProjectileList()) {
        if (projectile->isDead()) {
            removeItem(projectile);

            delete projectile;
        }
    }
}

void GameScene::removeDeadUnit()
{
    for(Unit * unit: *currentLevel->getUnitList()) {
        if (unit->isDead()) {
            // if player die dont do this
            currentLevel->getUnitList()->removeOne(unit);

            removeItem(unit);
            delete unit;
        }
        else {
            if (unit->isType(UNIT_ANIMATE)) {
                removeDeadProjectile(dynamic_cast<UnitAnimate*>(unit));
            }
        }
    }

    if (player->isDead()) {
        removeItem(player);

        //delete player;
    }
    else {
        removeDeadProjectile(dynamic_cast<UnitAnimate*>(player));
    }
}

void GameScene::checkCollision(Unit * unit)
{
    if (!unit->isInside()) {
        unit->stoneUnit();
    }
    else {
        for(Element * el: *currentLevel->getElementList()) {
            if (el->getCollider()) {
                if (unit->isColliding(el)) {
                    unit->stoneUnit();
                }
            }
        }
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
