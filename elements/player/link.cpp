#include "link.h"

#include "config.h"

Link::Link()
{
    setType(LINK);

    setHeight(BLOCKSIZE * 1);
    setWidth(BLOCKSIZE * 1.2);

    setSprite(":/ressources/images/players/zelda1.png");

    setMovementSpeed(5);
    setShootRate(20);

    setHealth(1000);

    setDefaultRotation(180);
}
