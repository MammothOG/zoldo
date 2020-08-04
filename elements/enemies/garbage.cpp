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

    setSprite(":/ressources/images/enemies/garbage.png");
}

void Garbage::move()
{

}
