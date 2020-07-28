#include "testprojectile.h"


TestProjectile::TestProjectile()
{
    setType(TEST_PROJECTILE);

    setHeight(0.5);
    setWidth(0.5);

    setSprite(":/ressources/images/test/shurikenb1moch.png");

    setDamage(10);

    setMovementSpeed(1);

    setCenterAsReferencial();
}
