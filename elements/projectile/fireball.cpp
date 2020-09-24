#include "fireball.h"


FireBall::FireBall()
{
    setType(FIREBALL);

    setWidth(0.56);
    setHeight(1.20);

    setSprite(":/ressources/images/projectiles/fire_ball.png");

    setSound(":/ressources/sounds/fireball.wav");

    setDamage(20);

    setMovementSpeed(10);

    setCenterAsReferencial();
}
