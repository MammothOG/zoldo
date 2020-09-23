#include "stone.h"

Stone::Stone()
{
    setType(STONE);

    setHeight(0.5);
    setWidth(0.5);

    setSprite(":/ressources/images/projectiles/slingshot_stone.png");

    setSound(":/ressources/sounds/stone.wav");

    setDamage(10);

    setMovementSpeed(3);

    setCenterAsReferencial();
}
