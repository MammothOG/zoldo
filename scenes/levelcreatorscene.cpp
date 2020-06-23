#include "levelcreatorscene.h"
#include "levelcreatorscene.h"

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDebug>

#include "config.h"
#include "core/element.h"
#include "core/player.h"
#include "core/level.h"

#include "items/blocks/wall.h"
#include "items/blocks/water.h"
#include "items/background/testbackground.h"
#include "items/enemies/testator.h"


LevelCreatorScene::LevelCreatorScene(QMainWindow * parent)
{
    setSceneRect(0, 0, WIN_WIDTH, WIN_HEIGHT);
    setBackgroundBrush(Qt::black);

    itemGroupSelected = new QGraphicsItemGroup();
    addItem(itemGroupSelected);

    level = new Level();

    elementSelected = new Element();
    addItem(elementSelected);

    menuBar = new QMenuBar();
    parent->setMenuBar(menuBar);

    playerMenu = new QMenu("Player");
    blockMenu = new QMenu("Block");
    unitMenu = new QMenu("Unit");
    backgroundMenu = new QMenu("Background");

    menuBar->addMenu(backgroundMenu);
    menuBar->addMenu(blockMenu);
    menuBar->addMenu(unitMenu);
    menuBar->addMenu(playerMenu);

    createAction();

}

void LevelCreatorScene::createAction()
{
    playerMenu->addAction(addNewElement("default player", new Player()));

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
    int posX = event->scenePos().x();
    int posY = event->scenePos().y();

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
        qDebug() << "space";
        itemGroupSelected->addToGroup(elementSelected);
        break;

    }

}


