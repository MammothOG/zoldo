#include "background.h"
#include "config.h"


Background::Background()
{
    setType(BACKGROUND);

    setHeight(BLOCKSIZE * VERTICAL_BLOCK);
    setWidth(BLOCKSIZE * HORIZONTAL_BLOCK);


    setStyleDir("backgrounds");
    setZValue(-1);
}
