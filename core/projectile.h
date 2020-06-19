#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "unit.h"


class Projectile : public Unit
{
private:
    int damage;

public:
    Projectile();

    Projectile(Projectile * projectile);

    void projectileTest();

    int getDamage() const;

    void setDamage(int value);
};

#endif // PROJECTILE_H
