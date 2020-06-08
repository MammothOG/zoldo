#include "level.h"


Level::Level()
{
    elementList = new QList<Element*>();
    unitList = new QList<Unit*>();

    difficulty = 0;
    name = "noNamedLevel";

    height = BLOCK_SIZE * VERTICAL_BLOCK;
    width = BLOCK_SIZE * HORIZONTAL_BLOCK;

}

void Level::generateTestLevel()
{
    name = "Test level";
    difficulty = 0;

    backgroundPath = ":/ressources/images/level_bg_test.png";
    background = QImage(backgroundPath);
    background = background.scaledToHeight(height);

    Wall * wall1 = new Wall();
    wall1->setPos(0, 0);
    Wall * wall2 = new Wall();
    wall2->setPos(75, 75);

    elementList->append(wall1);
    elementList->append(wall2);
}

void Level::clearLevel()
{
    for(Element * elem : *elementList){
        delete elem;
    }
    elementList->clear();

    for(Unit * unit: *unitList){
        delete unit;
    }
    unitList->clear();
}

QList<Element*> * Level::getElementList() const
{
    return elementList;
}

QImage Level::getBackground() const
{
    return background;
}
