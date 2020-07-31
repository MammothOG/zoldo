#include "ghost.h"

Ghost::Ghost()
{
    setType(GHOST_ENEMY);

    setMoveRate(10);

    setShootRate(1);

    setProjectile(AIR_GUST);

    setMovementSpeed(0);
    setHealth(100);

    // setup graphics
    setHeight(1.06);
    setWidth(0.80);
    setSprite(":/ressources/images/enemies/ghost.png");
}
