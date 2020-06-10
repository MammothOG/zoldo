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

    clock  = new QTimer(this);
    connect(clock, SIGNAL(timeout()), this, SLOT(updateState()));

    loadAdventure();
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
        qDebug() << "unit";
    }

}

void GameEngine::loadAdventure()
{
    // init TEST adventure
    adventure = new Adventure();
    adventure->generateTestAdventure();

    drawLevel(adventure->getCurrentLevel());

    setScene(scene);

}

void GameEngine::updateState()
{
    updateUnitState();
}

void GameEngine::updateUnitState()
{

}
