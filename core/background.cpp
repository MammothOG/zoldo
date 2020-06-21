#include "background.h"
#include "config.h"


Background::Background()
{
    type = BACKGROUND;

    setHeight(BLOCK_SIZE * VERTICAL_BLOCK);
    setWidth(BLOCK_SIZE * HORIZONTAL_BLOCK);


    setZValue(-1);
}
