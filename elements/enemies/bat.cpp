#include "bat.h"

Bat::Bat()
{
    setType(BAT_ENEMY);

    setMoveRate(10);

    setShootRate(1);

    setProjectile(DIRTY_BALL);

    setMovementSpeed(0);
    setHealth(100);

    // setup graphics
    setHeight(0.67);
    setWidth(0.5);
    setSprite(":/ressources/images/enemies/bat.png");
}
