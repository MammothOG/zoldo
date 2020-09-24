#include "ghost.h"

Ghost::Ghost()
{
    setType(GHOST_ENEMY);

    setMoveRate(10);


    setProjectile(AIR_GUST);

    setMovementSpeed(0);

    setHealth(20);
    setShootRate(2500);

    // setup graphics
    setHeight(1.06);
    setWidth(0.80);
    setSprite(":/ressources/images/enemies/ghost_down.png");

    insertDirectionSprite("D", ":/ressources/images/enemies/ghost_down.png");
    insertDirectionSprite("R", ":/ressources/images/enemies/ghost_right.png");
    insertDirectionSprite("U", ":/ressources/images/enemies/ghost_up.png");
    insertDirectionSprite("L", ":/ressources/images/enemies/ghost_left.png");

}

void Ghost::move()
{

}
