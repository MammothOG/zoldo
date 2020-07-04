#include "projectile.h"


Projectile::Projectile()
{
    type = PROJECTILE;

    movementSpeed = 0;

    damage = 0;
}

Projectile::Projectile(Projectile * projectile)
{
    this->movementSpeed = projectile->movementSpeed;

    this->damage = projectile->damage;

    this->setPixmap(projectile->pixmap());

    setCenterAsReferencial();
}

void Projectile::projectileTest()
{
    setHeight(25);
    setWidth(25);

    setSprite(":/ressources/images/shurikenb1moch.png");

    damage = 10;

    movementSpeed = 3;

    setCenterAsReferencial();
}

int Projectile::getDamage() const
{
    return damage;
}

void Projectile::setDamage(int value)
{
    damage = value;
}
