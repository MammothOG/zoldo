#include "gameengine.h"

GameEngine::GameEngine()
{

    windowWidth = WIN_WIDTH;
    windowHeight = WIN_HEIGHT;

    setWindowTitle(TITLE);
    resize(windowWidth, windowHeight);

    // create the scene
    levelScene = new QGraphicsScene();

    gamePlan = new QGraphicsItemGroup();
    levelScene->addItem(gamePlan);



    // init map
    //map = new Map();
}

GameEngine::~GameEngine()
{

}
