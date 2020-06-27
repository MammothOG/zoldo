#include "levelcreatorscene.h"
#include "levelcreatorscene.h"

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>

#include "config.h"
#include "tools/elementfactory.h"
#include "core/element.h"
#include "core/player.h"
#include "core/level.h"

#include "elements/player/playertest.h"
#include "elements/blocks/wall.h"
#include "elements/blocks/water.h"
#include "elements/background/testbackground.h"
#include "elements/enemies/testator.h"


LevelCreatorScene::LevelCreatorScene(QMainWindow * parent)
{
    setSceneRect(0, 0, WIN_WIDTH, WIN_HEIGHT);
    setBackgroundBrush(Qt::black);

    itemGroupSelected = new QGraphicsItemGroup();
    addItem(itemGroupSelected);

    level = new Level();
    unitList = new QList<Unit*>();
    elementList = new QList<Element*>();

    // Action for saving level

    // initialisation item selected
    elementSelected = new Element();
    addItem(elementSelected);

    // menu bar used to select element
    menuBar = new QMenuBar();
    parent->setMenuBar(menuBar);

    // create menu with all category of element
    menu = new QMenu("Menu");
    playerMenu = new QMenu("Player");
    blockMenu = new QMenu("Block");
    unitMenu = new QMenu("Unit");
    backgroundMenu = new QMenu("Background");

    menuBar->addMenu(menu);
    menuBar->addMenu(backgroundMenu);
    menuBar->addMenu(blockMenu);
    menuBar->addMenu(unitMenu);
    menuBar->addMenu(playerMenu);

    QAction * saveLevel = new QAction("save level");
    //connect(saveLevel, &QAction::triggered, this, SLOT(createLevel()));
    menu->addAction(saveLevel);

    createAction();

}

void LevelCreatorScene::createAction()
{
    // add to the menu bar all element
    playerMenu->addAction(addNewElement("default player", new PlayerTest()));

    blockMenu->addAction(addNewElement("wall", new Wall()));
    blockMenu->addAction(addNewElement("water", new Water()));

    backgroundMenu->addAction(addNewElement("test background", new TestBackground()));

    unitMenu->addAction(addNewElement("testator", new Testator()));
}

QAction * LevelCreatorScene::addNewElement(QString name, Element *newElement)
{
    QAction * newAction = new QAction(name);
    connect(newAction, &QAction::triggered, [=](){
        removeItem(elementSelected);
        elementSelected = newElement;
        addItem(newElement);
    });
    return newAction;
}

void LevelCreatorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    posX = event->scenePos().x();
    posY = event->scenePos().y();

    if(posX > 0 && posY > 0)
    {
        switch (elementSelected->getType()) {
        case BLOCK:
            posX -= (posX % BLOCK_SIZE);
            posY -= (posY % BLOCK_SIZE);
            break;

        case BACKGROUND:
            posX = 0;
            posY = 0;
        }
    }

    elementSelected->setPos(posX, posY);
}

void LevelCreatorScene::keyPressEvent(QKeyEvent *keyEvent)
{
    switch (keyEvent->key()) {
    case Qt::Key_Escape:
        emit backToMenu();
        break;

    case Qt::Key_Space:
        Element * instance = ElementFactory::create(elementSelected->getElement_name());
        instance->setPos(posX, posY);
        itemGroupSelected->addToGroup(instance);

        appendLevelElement(elementSelected);
        break;

    }
}

void LevelCreatorScene::appendLevelElement(Element * element)
{
    switch (element->getType()) {
    case BLOCK:
        elementList->append(element);
        break;

    case BACKGROUND:
        background = dynamic_cast<Background*>(element);
        break;

    case ENEMY:
        unitList->append(dynamic_cast<Unit*>(element));
        break;

    case PLAYER:
        player = dynamic_cast<Player*>(element);
        break;
    }
}

void LevelCreatorScene::createLevel()
{
    level->setSpawn(player->x(), player->y());
    level->setUnitList(unitList);
    level->setBackground(background);
    level->setElementList(elementList);

    // TODO save level here
}


