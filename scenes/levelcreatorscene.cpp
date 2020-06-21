#include "levelcreatorscene.h"
#include "levelcreatorscene.h"

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneWheelEvent>
#include <QKeyEvent>

#include "config.h"
#include "core/element.h"
#include "core/block.h"
#include "core/background.h"
#include "core/player.h"
#include "core/unit.h"

#include "items/blocks/wall.h"
#include "items/blocks/water.h"
#include "items/background/testbackground.h"
#include "items/enemies/testator.h"



LevelCreatorScene::LevelCreatorScene()
{
    setSceneRect(0, 0, WIN_WIDTH, WIN_HEIGHT);
    setBackgroundBrush(Qt::white);

    elementIndex = 0;
    elementListIndex = 1;

    // player region
    QList<Element*> * playerList = new QList<Element*>();
    Player * player = new Player();
    playerList->append(player);

    // block region
    QList<Element*> * blockList = new QList<Element*>();

    Wall * wall = new Wall();
    blockList->append(wall);

    Water * water = new Water();
    blockList->append(water);

    // background region
    QList<Element*> * backgroundList = new QList<Element*>();

    TestBackground * testBackground = new TestBackground();
    backgroundList->append(testBackground);

    // unit region
    QList<Element*> * unitList = new QList<Element*>();

    Testator * testator = new Testator();
    unitList->append(testator);

    // global list off all list of elements
    elementList = new QList<QList<Element*>*>();
    elementList->append(backgroundList);
    elementList->append(blockList);
    elementList->append(playerList);
    elementList->append(unitList);

    initNewList();
}

void LevelCreatorScene::initNewList()
{
    //init the first selected element list
    elementListSelected = elementList->at(elementListIndex);

    //check if list in not empty
    lengthList = elementListSelected->length();
    if (lengthList > 0)
    {
        //init the first selected element
        elementSelected = elementList->at(elementListIndex)->at(elementIndex);
        addItem(elementSelected);
    }

}

#include <QDebug>
void LevelCreatorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    int posX = event->scenePos().x();
    int posY = event->scenePos().y();

    switch (elementSelected->getType()) {
    case BLOCK:
        posX -= (posX % BLOCK_SIZE);
        posY -= (posY % BLOCK_SIZE);
        break;
    case BACKGROUND:
        posX = 0;
        posY = 0;
    }

    elementSelected->setPos(posX, posY);
}

void LevelCreatorScene::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Space:
        elementListIndex++;
        elementListIndex %= elementList->length();

        removeItem(elementSelected);
        initNewList();
        break;

    case Qt::Key_Enter:
        break;

    }

}

void LevelCreatorScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    lengthList = elementListSelected->length();

    if (lengthList > 0)
    {
        if (event->delta() > 0)
        {
        elementIndex++;
        } else if (event->delta() < 0 && elementIndex > 0)
        {
        elementIndex--;
        } else if (elementIndex <= 0)
        {
        elementIndex = lengthList - 1;
        }
        elementIndex %= lengthList;

        removeItem(elementSelected);
        elementSelected = elementListSelected->at(elementIndex);
        addItem(elementSelected);
    }
}

