#include "background.h"
#include "config.h"


Background::Background()
{
    setType(BACKGROUND);

    setHeight(VERTICAL_BLOCK);
    setWidth(HORIZONTAL_BLOCK);


    setStyleDir("backgrounds");
    setZValue(-1);
}
