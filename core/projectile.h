#ifndef PROJECTILE_H
#define PROJECTILE_H

#include "unit.h"
#include <QSound>

class UnitAnimate;

class Projectile : public Unit
{
private:
    UnitAnimate * owner;

    int damage;

    QString sound;

protected:
    void setSound(const QString value);

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

    QString getSound() const;
};

#endif // PROJECTILE_H
