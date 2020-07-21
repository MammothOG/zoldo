#include "testprojectile.h"


TestProjectile::TestProjectile()
{
    setType(TEST_PROJECTILE);

    setHeight(25);
    setWidth(25);

    setSprite(":/ressources/images/test/shurikenb1moch.png");

    setDamage(10);

    setMovementSpeed(2);

    setCenterAsReferencial();
}
