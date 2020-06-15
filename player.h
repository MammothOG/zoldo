#ifndef PLAYER_H
#define PLAYER_H

#include <QTimer>

#include "unit.h"

class Projectile;


class Player : public Unit
{

    Q_OBJECT
protected:
    //chance of crit
    float crit;

    //dmg deal by crit
    float critdmg;

    int shootRate;

    QTimer * shootTimer;

    QList<Projectile*> * projectileList;

public:
    Player();

    QList<Projectile*> * getProjectileList() const;

public slots:

    void attack();
};

#endif // PLAYER_H
