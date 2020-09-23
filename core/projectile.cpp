#include "projectile.h"

#include "unitanimate.h"


Projectile::Projectile()
{
    this->owner = nullptr;

    setType(PROJECTILE);

    setMovementSpeed(0);

    damage = 0;

    sound = QString("");
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

UnitAnimate *Projectile::getOwner() const
{
    return owner;
}

void Projectile::setOwner(UnitAnimate *value)
{
    owner = value;
}

void Projectile::onCollision(Element *element)
{
    if (element->types().last() != owner->types().last()) {
        Unit * unit = dynamic_cast<Unit*>(element);
        unit->giveDamage(damage);

        setDead(true);
    }
}

void Projectile::onOutside()
{
    setDead(true);
}

QString Projectile::getSound() const
{
    return sound;
}

void Projectile::setSound(QString value)
{
    sound = value;
}
