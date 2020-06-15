#include "projectile.h"


Projectile::Projectile()
{
    setHeight(25);
    setWidth(25);

    movementSpeed = 10;

    setSprite(":/ressources/images/shurikenb1moch.png");

    setCenterAsReferencial();



}
