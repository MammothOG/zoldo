#include "testprojectile.h"


TestProjectile::TestProjectile()
{
    setElementName(TEST_PROJECTILE);

    setHeight(25);
    setWidth(25);

    setSprite(":/ressources/images/shurikenb1moch.png");

    setDamage(10);

    setMovementSpeed(3);

    setCenterAsReferencial();
}
