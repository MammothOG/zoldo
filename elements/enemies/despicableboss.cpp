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

    setSprite(":/ressources/images/enemies/despicable_boss_down.png");

    insertDirectionSprite("D", ":/ressources/images/enemies/despicable_boss_down.png");
    insertDirectionSprite("R", ":/ressources/images/enemies/despicable_boss_right.png");
    insertDirectionSprite("U", ":/ressources/images/enemies/despicable_boss_up.png");
    insertDirectionSprite("L", ":/ressources/images/enemies/despicable_boss_left.png");
}

void DespicableBoss::move()
{

}
