#include "stone.h"

Stone::Stone()
{
    setType(STONE);

    setHeight(0.3);
    setWidth(0.3);

    setSprite(":/ressources/images/projectiles/slingshot_stone.png");

    setDamage(10);

    setMovementSpeed(2);

    setCenterAsReferencial();
}
