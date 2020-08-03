#include "despicableboss.h"

DespicableBoss::DespicableBoss()
{
    setType(DESPICABLE_BOSS);

    setMoveRate(10);

    setShootRate(1000);

    setProjectile(FIREBALL);

    setMovementSpeed(0);
    setHealth(500);

    // setup graphics
    setHeight(2.27);
    setWidth(1);

    setSprite(":/ressources/images/enemies/despicable_boss.png");
}
