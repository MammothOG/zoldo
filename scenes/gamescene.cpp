#include "gamescene.h"

#include <QTime>

#include "config.h"
#include "core/player.h"
#include "core/adventure.h"
#include "core/level.h"
#include "core/enemy.h"
#include "core/unit.h"
#include "core/projectile.h"
#include "core/background.h"
#include "elements/healthbar/zeldahealthbar.h"
#include "elements/healthbar/basichealthbar.h"
#include "elements/buttons/quitbutton.h"
#include "elements/visual/endgamevisual.h"
#include "scenes/pausemenu.h"


GameScene::GameScene(QGraphicsView * sceneManager)
{
    successLoaded = false;

    sceneHeight = VERTICAL_BLOCK * BLOCKSIZE;
    sceneWidth = HORIZONTAL_BLOCK * BLOCKSIZE;

    distancePlayerTarget = 0;

    setSceneRect(0, 0, sceneWidth, sceneHeight);
    setBackgroundBrush(Qt::black);

    bgMusic = new QMediaPlayer();

    QString advName = "the-beginning";
    //QString advName = "testadventure";
    adventure = new Adventure();
    if (adventure->load(advName)){

        loadAdventure();

        clock  = new QTimer(this);
        clock->setTimerType(Qt::PreciseTimer);
        connect(clock, SIGNAL(timeout()), this, SLOT(updateState()));
        clock->start(1000/FPS);
        setBackgroundBrush(Qt::black);

        bgMusic->play();

        successLoaded = true;
    }
    else {
        delete adventure;
        qWarning("Adventure loading has been interrupted!");
    }

    quitButton = new QuitButton();
    quitButton->setPos(BLOCKSIZE*(HORIZONTAL_BLOCK-0.5), BLOCKSIZE*0.5);
    addItem(quitButton);
    //
    //    pauseMenu = new PauseMenu();
    //    pauseMenu->setPos(WIN_WIDTH/2, WIN_HEIGHT/2);
    //    connect(pauseMenu->getResumeButton(), SIGNAL(onReleaseClick()), this, SLOT(onResume()));
    //    connect(pauseMenu->getRestartButton(), SIGNAL(onPressClick()), this, SLOT(onRestart()));

}

GameScene::~GameScene()
{
    bgMusic->stop();
    delete bgMusic;
}

void GameScene::loadAdventure()
{
    if(!adventure->getMusic().isEmpty()) {
        bgMusic->setMedia(QUrl::fromLocalFile(adventure->getMusic()));
        bgMusic->setVolume(5);
        bgMusic->play();
    }

    player = adventure->getPlayer();
    addItem(player);

    HealthBar * playerHealthBar = new ZeldaHealthBar(3);
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

    enemyTargeted = nullptr;

    for(Element * element : *currentLevel->getElementList()){
        levelElements->addToGroup(element);
    }

    for(Unit * unit : *currentLevel->getUnitList()){
        HealthBar * unitHealthBar = new BasicHealthBar(0, unit->getHeight()/2);
        unit->addHealthBar(unitHealthBar);
        levelElements->addToGroup(unitHealthBar);

        unit->setCenterAsReferencial();
        levelElements->addToGroup(unit);
    }
}

bool GameScene::getSuccessLoaded() const
{
    return successLoaded;
}

void GameScene::setSuccessLoaded(bool value)
{
    successLoaded = value;
}

void GameScene::updateState()
{
    distancePlayerTarget = 2 * sceneHeight;

    for(Unit * unit: *currentLevel->getUnitList()){
        updateUnit(unit);
    }

    updateUnit(player);

    removeDeadUnit();

    updateGame();
}

void GameScene::removeDeadUnit()
{
    for(Unit * unit: *currentLevel->getUnitList()) {
        if (unit->isDead()) {
            // if player die dont do this
            currentLevel->getUnitList()->removeOne(unit);

            // remove projectile from the scene if unit is dead
            if(unit->isType(UNIT_ANIMATE)) {
                UnitAnimate * unitAnimate = dynamic_cast<UnitAnimate*>(unit);
                for(Projectile * projectile: *unitAnimate->getProjectileList()) {
                    removeItem(projectile);
                    delete projectile;
                }
            }

            removeItem(unit);

            delete unit;
        }
    }
}

void GameScene::updateUnit(Unit * unit)
{
    unit->moveUnit();

    checkCollision(unit);

    if (unit->isType(UNIT_ANIMATE)) {
        updateUnitAnimate(dynamic_cast<UnitAnimate*>(unit));
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

void GameScene::updateUnitAnimate(UnitAnimate * unitAnimate)
{
    if (unitAnimate->isType(PLAYER) &&
            currentLevel->getUnitList()->length() > 0 &&
            enemyTargeted != nullptr) {
        unitAnimate->lockTarget(enemyTargeted);

    }
    else if (unitAnimate->isType(ENEMY)) {

        unitAnimate->lockTarget(player);

        if (distancePlayerTarget > unitAnimate->getTargetDistance()) {
            enemyTargeted = unitAnimate;
            distancePlayerTarget = unitAnimate->getTargetDistance();
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

        // check if projectile hit player
        projectile->isColliding(player);
        // and all units
        for (Unit * enemy: * currentLevel->getUnitList()) {
            projectile->isColliding(enemy);
        }

        // check if projectile is inside the scene
        projectile->isInside();

        // move the projectile
        if (projectile->isDead() || unit->isDead()) {
            removeItem(projectile);
            delete projectile;
        }
        else {
            projectile->moveUnit();
        }
    }
}

bool GameScene::updateGame()
{
    if (currentLevel->isLevelDone()) {
        // if no more ennemies activate all exit
        for (Element * el: * currentLevel->getElementList()) {
            if (el->isExit()) {
                if(!el->isActivated())
                    el->activate();

                if(el->isColliding(player))
                    changeLevel();
            }
        }
        player->defaultDirectionSprite();
    }

    if (player->isDead() || adventure->isWin()) {
        clock->stop();

        endGameVisual = new EndGameVisual(adventure->isWin());
        endGameVisual->setPos(this->width()/2,this->height()/2);
        addItem(endGameVisual);

        for (Unit * unit: * currentLevel->getUnitList()) {
            if (unit->isType(ENEMY)) {
                Enemy * enemy = dynamic_cast<Enemy*>(unit);
                enemy->stop();
            }
        }
        player->stopShooting();

        return false;

    }
    else if (currentLevel->getUnitList()->length() == 0) {
        currentLevel->setLevelDone(true);
        player->stopShooting();

    }

    return true;
}

void GameScene::changeLevel()
{
    if(adventure->nextLevel()) {
        qDebug() << "leaving";
        removeItem(levelElements);
        currentLevel = adventure->getCurrentLevel();

        currentLevel->setLevelDone(false);

        drawLevel();

        player->startShooting();
    }
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
