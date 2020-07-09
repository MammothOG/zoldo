#include "projectile.h"

#include "unitanimate.h"


Projectile::Projectile()
{
    this->owner = nullptr;

    setType(PROJECTILE);

    setMovementSpeed(0);

    damage = 0;
}

Projectile::~Projectile()
{
    if (owner != nullptr)
    {
        owner->getProjectileList()->removeOne(this);
    }
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
        Unit * unit = dynamic_cast<Unit*>(element);
        unit->giveDamage(damage);

        setDead(true);
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

void Projectile::onOutside()
{
    setDead(true);
}
