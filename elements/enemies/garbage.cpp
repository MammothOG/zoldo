#include "garbage.h"

Garbage::Garbage()
{
    setType(GARBAGE_ENEMY);

    setMoveRate(10);

    setShootRate(3000);

    setProjectile(STONE);

    setMovementSpeed(0);
    setHealth(100);

    // setup graphics
    setHeight(0.5);
    setWidth(0.72);

    setSprite(":/ressources/images/enemies/garbage_down.png");

    insertDirectionSprite("D", ":/ressources/images/enemies/garbage_down.png");
    insertDirectionSprite("R", ":/ressources/images/enemies/garbage_right.png");
    insertDirectionSprite("U", ":/ressources/images/enemies/garbage_up.png");
    insertDirectionSprite("L", ":/ressources/images/enemies/garbage_left.png");
}

void Garbage::move()
{

}
