#include "levelcreatorscene.h"
#include "levelcreatorscene.h"

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDir>
#include <QInputDialog>

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


#include <QDebug>
LevelCreatorScene::LevelCreatorScene(QMainWindow * parent)
{
    setSceneRect(0, 0, WIN_WIDTH, WIN_HEIGHT);
    setBackgroundBrush(Qt::black);

    itemGroupSelected = new QGraphicsItemGroup();
    addItem(itemGroupSelected);

    level = new Level();

    // initialisation item selected
    elementSelected = new Element();
    addItem(elementSelected);

    // menu bar used to select element
    menuBar = new QMenuBar();
    parent->setMenuBar(menuBar);

    // create menu with all category of element
    optionMenu = new QMenu("Menu");
    playerMenu = new QMenu("Player");
    blockMenu = new QMenu("Block");
    unitMenu = new QMenu("Unit");
    backgroundMenu = new QMenu("Background");

    menuBar->addMenu(optionMenu);
    menuBar->addMenu(backgroundMenu);
    menuBar->addMenu(blockMenu);
    menuBar->addMenu(unitMenu);
    menuBar->addMenu(playerMenu);

    // Action for saving level
    QAction * saveLevel = new QAction("Save level");
    connect(saveLevel, SIGNAL(triggered()), this, SLOT(createLevel()));
    optionMenu->addAction(saveLevel);

    QAction * backMenu = new QAction("Back menu");
    connect(backMenu, SIGNAL(triggered()), this, SLOT(createLevel()));
    optionMenu->addAction(saveLevel);

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
        Element * instance = ElementFactory::create(elementSelected->getElementName());
        itemGroupSelected->addToGroup(instance);
        instance->setPos(posX, posY);
        level->appendLevelElement(instance);
        break;
    }
}

bool LevelCreatorScene::createLevel()
{
    level->setName("test2");
    level->save();

    return true;
}


