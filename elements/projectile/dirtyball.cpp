#include "dirtyball.h"

DirtyBall::DirtyBall()
{
    setType(DIRTY_BALL);

    setWidth(0.28);
    setHeight(0.60);

    setSprite(":/ressources/images/projectiles/dirty_ball.png");

    setSound(":/ressources/sounds/dirtyball.wav");

    setDamage(10);

    setMovementSpeed(5);

    setDefaultRotation(180);

    setCenterAsReferencial();
}
