#include "levelcreatorscene.h"
#include "levelcreatorscene.h"

#include <QGraphicsSceneMouseEvent>
#include <QKeyEvent>
#include <QDir>
#include <QFileDialog>

#include "config.h"
#include "tools/elementfactory.h"
#include "core/element.h"
#include "core/player.h"
#include "core/level.h"

#include "elements/player/playertest.h"
#include "elements/blocks/wall.h"
#include "elements/blocks/water.h"
#include "elements/blocks/door.h"
#include "elements/background/testbackground.h"
#include "elements/enemies/testator.h"


LevelCreatorScene::LevelCreatorScene(QMainWindow * parent)
{
    posX = 0;
    posY = 0;

    sceneHeight = VERTICAL_BLOCK * BLOCKSIZE;
    sceneWidth = HORIZONTAL_BLOCK * BLOCKSIZE;

    setSceneRect(0, 0, sceneWidth, sceneHeight);
    setBackgroundBrush(Qt::black);

    gridEnabled = false;
    elementCentered = false;

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
    fileMenu = new QMenu("File");
    toolsMenu = new QMenu("Tools");

    playerMenu = new QMenu("Player");
    blockMenu = new QMenu("Block");
    unitMenu = new QMenu("Unit");
    backgroundMenu = new QMenu("Background");

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(toolsMenu);
    menuBar->addMenu(backgroundMenu);
    menuBar->addMenu(blockMenu);
    menuBar->addMenu(unitMenu);
    menuBar->addMenu(playerMenu);

    // Action for saving level
    QAction * saveLevel = new QAction("Save level");
    connect(saveLevel, SIGNAL(triggered()), this, SLOT(createLevel()));
    fileMenu->addAction(saveLevel);

    QAction * backMenu = new QAction("Back menu");
    connect(backMenu, SIGNAL(triggered()), this, SLOT(createLevel()));
    fileMenu->addAction(saveLevel);

    QAction * resetMenu = new QAction("Back menu");
    connect(resetMenu, SIGNAL(triggered()), this, SLOT(reset()));
    fileMenu->addAction(resetMenu);

    loadToolMenu(toolsMenu);

    createAction();

}

void LevelCreatorScene::createAction()
{
    // add to the menu bar all element
    playerMenu->addAction(addNewElement("default player", new PlayerTest()));

    blockMenu->addAction(addNewElement("wall", new Wall()));
    blockMenu->addAction(addNewElement("water", new Water()));
    blockMenu->addAction(addNewElement("door", new Door()));

    backgroundMenu->addAction(addNewElement("test background", new TestBackground()));

    unitMenu->addAction(addNewElement("testator", new Testator()));
}

QAction * LevelCreatorScene::addNewElement(QString name, Element *newElement)
{
    QAction * newAction = new QAction(name);
    connect(newAction, &QAction::triggered, [=](){
        removeItem(elementSelected);
        addItem(newElement);

        // save element
        elementSelected = newElement;

        grabStyleElement(newElement);

        posX = 0;
        posY = 0;
    });
    return newAction;
}

void LevelCreatorScene::grabStyleElement(Element * element)
{
    styleList.clear();
    indexStyle = 0;

    if(!element->getStyleDir().isEmpty()) {
        QDir styleDir(":/ressources/images/" + elementSelected->getStyleDir());
        styleList = styleDir.entryList(QStringList() << "*.png", QDir::Files);
        styleList.replaceInStrings(".png", "");
    }

    qDebug() << styleList;
}

void LevelCreatorScene::loadToolMenu(QMenu *menu)
{
    QAction * gridAction = new QAction("Grid");
    gridAction->setCheckable(true);
    gridAction->setChecked(false);
    connect(gridAction, &QAction::triggered, [=](){
        if (gridAction->isChecked())
            gridEnabled = true;
        else
            gridEnabled = false;
    });
    menu->addAction(gridAction);

    QAction * itemCenterAction = new QAction("Center element");
    itemCenterAction->setCheckable(true);
    itemCenterAction->setChecked(false);
    connect(itemCenterAction, &QAction::triggered, [=](){
        if (itemCenterAction->isChecked()) {
            elementSelected->setCenterAsReferencial();
            elementCentered = true;
        }
        else {
            elementSelected->setOffset(0, 0);
            elementCentered = false;
        }
    });
    menu->addAction(itemCenterAction);
}

void LevelCreatorScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    posX = event->scenePos().x();
    posY = event->scenePos().y();

    if (elementSelected->isInside()) {
        if (gridEnabled)
        {
            if(posX > 0 && posY > 0)
            {
                posX -= (posX % BLOCKSIZE);
                posY -= (posY % BLOCKSIZE);
            }
        }
        if (elementSelected->isType(BACKGROUND))
        {
            posX = 0;
            posY = 0;
        }
    }
    else {
        posX = -elementSelected->offset().rx();
        posY = -elementSelected->offset().ry();
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
        if (elementSelected->isInside()) {
            Element * instance = ElementFactory::create(elementSelected->types().last());
            itemGroupSelected->addToGroup(instance);
            instance->setPos(posX, posY);

            if (styleList.length() > 0)
                instance->setStyle(styleList.at(indexStyle));

            if (elementCentered)
                instance->setCenterAsReferencial();

            level->appendLevelElement(instance);
            break;
        }
        else {
            qDebug() << "Cannot add item outside the scene !";
        }
    }
}

void LevelCreatorScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (styleList.length() > 0) {
        if(event->delta() > 0) {
            indexStyle = (indexStyle + 1) % styleList.length();
        }
        else {
            indexStyle = (indexStyle - 1) % styleList.length();
            if(indexStyle < 0)
                indexStyle += styleList.length();

        }
        elementSelected->setStyle(styleList.at(indexStyle));
    }
}



bool LevelCreatorScene::createLevel()
{
    QString name = QFileDialog::getSaveFileName(0, tr("Save Level"), "",
                                                tr("Level (*.lvl)"));

    if (!name.isEmpty()) {
        level->setName(name);
        level->save();
        return true;
    }
    else {
        return false;
    }

}

void LevelCreatorScene::reset()
{
    delete elementSelected;
    delete level;

    level = new Level();

    clear();
}
