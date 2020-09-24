#include "arrow.h"

Arrow::Arrow()
{
    setType(ARROW);

    setWidth(0.75);
    setHeight(0.25);

    setSprite(":/ressources/images/projectiles/arrow.png");

    setSound(":/ressources/sounds/arrow.wav");

    setDamage(10);

    setMovementSpeed(10);

    setDefaultRotation(-90);

    setCenterAsReferencial();
}
