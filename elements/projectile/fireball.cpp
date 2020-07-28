#include "fireball.h"


FireBall::FireBall()
{
    setType(FIREBALL);

    setWidth(0.28);
    setHeight(0.60);

    setSprite(":/ressources/images/projectiles/fire_ball.png");

    setDamage(10);

    setMovementSpeed(2);

    setCenterAsReferencial();
}
