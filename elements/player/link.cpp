#include "link.h"

#include "config.h"

Link::Link()
{
    setElementName(PLAYER_TEST);

    setHeight(BLOCKSIZE * 1);
    setWidth(BLOCKSIZE * 1.2);

    setSprite(":/ressources/images/zelda1.png");

    setMovementSpeed(5);
    setShootRate(10);

    setHealth(100);

}
