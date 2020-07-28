#ifndef PLAYER_H
#define PLAYER_H

#include <QTimer>

#include "unitanimate.h"


class Projectile;

class Player : public UnitAnimate
{

protected:
    //chance of crit
    float crit;

    //dmg deal by crit
    float critdmg;

public:
    Player();

    void shoot() override;

    void onCollision(Element * element) override;

};

#endif // PLAYER_H
