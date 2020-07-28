#include "stone.h"

Stone::Stone()
{
    setType(STONE);

    setHeight(0.5);
    setWidth(0.5);

    setSprite(":/ressources/images/projectiles/slingshot_stone.png");

    setDamage(10);

    setMovementSpeed(2);

    setCenterAsReferencial();
}
