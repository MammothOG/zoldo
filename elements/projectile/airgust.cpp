#include "airgust.h"

AirGust::AirGust()
{
    setType(AIR_GUST);

    setWidth(0.80);
    setHeight(1.06);

    setSprite(":/ressources/images/projectiles/air_gust.png");

    setDamage(10);

    setMovementSpeed(2);

    setDefaultRotation(-90);

    setCenterAsReferencial();
}
