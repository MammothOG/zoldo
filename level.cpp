#include "level.h"


Level::Level()
{
    // listing the level item
    elementList = new QList<Element*>();
    unitList = new QList<Unit*>();

    // set info level
    difficulty = 0;
    name = "noNamedLevel";

    // set level dimension
    height = BLOCK_SIZE * VERTICAL_BLOCK;
    width = BLOCK_SIZE * HORIZONTAL_BLOCK;

}

void Level::generateTestLevel()
{
    name = "Test level";
    difficulty = 0;

    backgroundPath = ":/ressources/images/level_bg_test.png";
    background = QImage(backgroundPath);
    background = background.scaled(width, height);

    spawnX = 300;
    spawnY = 300;

    // set block wall around the level
    for (int w = 0; w < HORIZONTAL_BLOCK; w++){
        for (int h = 0; h < VERTICAL_BLOCK; h++){
            int posx = w * BLOCK_SIZE;
            int posy = h * BLOCK_SIZE;

            if(posx == 0 || posy == 0 ||
                    posx == (HORIZONTAL_BLOCK-1)*BLOCK_SIZE ||
                    posy == (VERTICAL_BLOCK-1)*BLOCK_SIZE)
            {
                Wall * wall = new Wall();

                wall->setPos(posx, posy);

                elementList->append(wall);
            }
        }
    }

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
