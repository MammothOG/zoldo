#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "unit.h"

class UnitAnimate;

class Projectile : public Unit
{
private:
    UnitAnimate * owner;

    int damage;

public:
    Projectile();

    ~Projectile();

    Projectile(Projectile * projectile);

    void projectileTest();

    int getDamage() const;

    void setDamage(int value);

    void onCollision(Element * element) override;

    UnitAnimate *getOwner() const;

    void setOwner(UnitAnimate *value);

    void onOutside() override;
};

#endif // PROJECTILE_H
