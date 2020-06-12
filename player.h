#ifndef PLAYER_H
#define PLAYER_H

#include "unit.h"


class Player : public Unit
{
protected:
    //chance of crit
    float crit;

    //dmg deal by crit
    float critdmg;
public:
    Player();

    void attack(float crit, float critdmg);
};

#endif // PLAYER_H
