#include "airgust.h"

AirGust::AirGust()
{
    setType(AIR_GUST);

    setWidth(0.80);
    setHeight(1.06);

    setSprite(":/ressources/images/projectiles/air_gust.png");

    setSound(":/ressources/sounds/airgust.wav");

    setDamage(20);

    setMovementSpeed(1.5);

    setDefaultRotation(-90);

    setCenterAsReferencial();
}
