#include "background.h"
#include "config.h"


Background::Background()
{
    setType(BACKGROUND);

    setHeight(BLOCKSIZE * VERTICAL_BLOCK);
    setWidth(BLOCKSIZE * HORIZONTAL_BLOCK);


    setZValue(-1);

    //mirroringX();
}
