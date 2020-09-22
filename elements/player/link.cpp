#include "link.h"

#include "config.h"

Link::Link()
{
    setType(LINK);

    setHeight(0.8);
    setWidth(0.96);

    setSprite(":/ressources/images/players/zelda1.png");

    setMovementSpeed(8);

    setShootRate(700);
    setProjectile(ARROW);

    setHealth(10000);

    //setDefaultRotation(180);
}
