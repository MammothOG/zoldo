#include "gameengine.h"

#include <QDebug>
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


void GameEngine::drawLevel(Level * level)
{
    scene->setBackgroundBrush(QImage(level->getBackground()));

    for(Element * element : *level->getElementList()){
        sceneElements->addToGroup(element);
    }

    for(Unit * unit : *level->getUnitList()){
        sceneElements->addToGroup(unit);
    }

}

void GameEngine::loadAdventure()
{
    // init TEST adventure
    adventure = new Adventure();
    adventure->generateTestAdventure();

    currentLevel = adventure->getCurrentLevel();

    drawLevel(currentLevel);
    setScene(scene);

}

void GameEngine::updateState()
{
    updateUnitState();
}

void GameEngine::updateUnitState()
{
    for(Unit * unit: *currentLevel->getUnitList()){
        Enemy * enemy = dynamic_cast<Enemy*>(unit);
        enemy->move();

        int nextX = enemy->x() + enemy->getHorizontalMov();
        int nextY = enemy->y() + enemy->getVerticalMov();

        enemy->setPos(nextX, nextY);

    }
}
