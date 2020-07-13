#ifndef PLAYER_H
#define PLAYER_H

#include <QTimer>

#include "unitanimate.h"


class Projectile;

class Player : public UnitAnimate
{

protected:
    bool won;

    bool leavingLevel;

    //chance of crit
    float crit;

    //dmg deal by crit
    float critdmg;

public:
    Player();

    void shoot() override;

    void onCollision(Element * element) override;

    bool hasWon() const;

    void setWon(bool value);

    bool isLeavingLevel() const;

    void setLeavingLevel(bool value);
};

#endif // PLAYER_H
