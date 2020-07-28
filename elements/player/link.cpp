#include "link.h"

#include "config.h"

Link::Link()
{
    setType(LINK);

    setHeight(1);
    setWidth(1.2);

    setSprite(":/ressources/images/players/zelda1.png");

    setMovementSpeed(5);

    setShootRate(20);
    setProjectile(STONE);

    setHealth(100);

    //setDefaultRotation(180);
}
