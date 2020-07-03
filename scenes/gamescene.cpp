#include "gamescene.h"

#include "config.h"
#include "core/player.h"
#include "core/adventure.h"
#include "core/level.h"
#include "core/enemy.h"
#include "core/unit.h"
#include "core/projectile.h"
#include "core/background.h"
#include "elements/buttons/pausebutton.h"
#include "elements/buttons/restartbutton.h"
#include "elements/buttons/resumebutton.h"
#include "scenes/pausemenu.h"


GameScene::GameScene()
{
    setSceneRect(0, 0, WIN_WIDTH, WIN_HEIGHT);
    setBackgroundBrush(Qt::black);


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

    Level * currentLevel = adventure->getCurrentLevel();
    player->setPos(currentLevel->getSpawnX(), currentLevel->getSpawnY());

    drawLevel();
}

void GameScene::drawLevel()
{
    currentLevel = adventure->getCurrentLevel();

    addItem(currentLevel->getBackground());

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

            if (nextXProj < 0 || nextYProj < 0 ||
                nextXProj < 0 || nextYProj < 0)
            if (projectile->group()== nullptr)
            {
                sceneProjectiles->addToGroup(projectile);
            }

            projectile->setPos(nextXProj, nextYProj);
        }
    }
}

void GameScene::updateProjectile(Enemy * enemy)
{

}

void GameScene::updatePlayer()
{
    int nextXPlayer = player->x() + player->getHorizontalMov();
    int nextYPlayer = player->y() + player->getVerticalMov();

    player->setPos(nextXPlayer, nextYPlayer);

    // TODO sometime crash (reopen fast)
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

#include <QDebug>
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


void GameScene::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left ||event->key() == Qt::Key_Right){
        player-> setHorizontalMov(0);
    }
    else if (event->key() == Qt::Key_Up||event->key() == Qt::Key_Down){
        player-> setVerticalMov(0);

    }
}
