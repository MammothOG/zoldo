#include "gameengine.h"


GameEngine::GameEngine()
{
    windowWidth = WIN_WIDTH;
    windowHeight = WIN_HEIGHT;

    setWindowTitle(TITLE);
    resize(windowWidth, windowHeight);

    // create the scene
    scene = new QGraphicsScene(-100, -100, WIN_WIDTH, WIN_HEIGHT);

    mapPlan = new QGraphicsItemGroup();
    scene->addItem(mapPlan);

    // init map TEST
    level = new Level();
    level->generateTestLevel();

    scene->setBackgroundBrush(QImage(level->getBackground()));

    for(Element * element : *level->getElementList()){
        mapPlan->addToGroup(element);
    }

    setScene(scene);
 }

GameEngine::~GameEngine()
{

}

void GameEngine::loadMap(QString mapName)
{

}

void GameEngine::drawMap(Map map)
{

}

