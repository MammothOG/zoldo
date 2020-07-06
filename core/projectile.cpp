#include "projectile.h"

#include "unitanimate.h"


Projectile::Projectile()
{
    this->owner = nullptr;

    setType(PROJECTILE);

    setMovementSpeed(0);

    damage = 0;
}

int Projectile::getDamage() const
{
    return damage;
}

void Projectile::setDamage(int value)
{
    damage = value;
}

#include <QDebug>
void Projectile::onCollision(Element *element)
{
    if (element->getType() != owner->getType()) {
        if (element->getType() == PLAYER ||
                element->getType() == ENEMY)
        {
            Unit * unit = dynamic_cast<Unit*>(element);
            unit->giveDamage(damage);
        }
    }
}

UnitAnimate *Projectile::getOwner() const
{
    return owner;
}

void Projectile::setOwner(UnitAnimate *value)
{
    owner = value;
}
