#include "garbage.h"

Garbage::Garbage()
{
    setType(GARBAGE_ENEMY);

    setMoveRate(10);

    setShootRate(1500);

    setProjectile(STONE);
    setHealth(30);

    setMovementSpeed(0);

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
