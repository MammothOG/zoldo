#include "background.h"
#include "config.h"


Background::Background()
{

    setHeight(BLOCK_SIZE * VERTICAL_BLOCK);
    setWidth(BLOCK_SIZE * HORIZONTAL_BLOCK);

    setSprite(":/ressources/images/level_bg_test.png");

    setZValue(-1);
}
