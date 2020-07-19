#ifndef UNITANIMATE_H
#define UNITANIMATE_H

#include <QTimer>

#include "unit.h"

class Projectile;

class UnitAnimate : public Unit
{
    Q_OBJECT
private:
    int currentRotation;

    float directionVector [2];

    float targetDistance;

    QList<Projectile*> * projectileList;

    int shootRate;

    QTimer * shootTimer;

    int projectileName;

public slots:

    virtual void shoot();

public:
    UnitAnimate();

    ~UnitAnimate();

    void lockTarget(const Unit * const target);

    float getTargetDistance() const;

    const float* getDirectionVector() const;

    QList<Projectile*> * getProjectileList() const;

    void fire();

    int getShootRate() const;

    void setShootRate(int value);

    int getCurrentRotation() const;
};

#endif // UNITANIMATE_H
