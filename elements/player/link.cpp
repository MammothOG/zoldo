#include "link.h"

#include "config.h"

Link::Link()
{
    setType(PLAYER_TEST);

    setHeight(BLOCKSIZE * 1);
    setWidth(BLOCKSIZE * 1.2);

    setSprite(":/ressources/images/zelda1.png");

    setMovementSpeed(5);
    setShootRate(20);

    setHealth(100);

}
