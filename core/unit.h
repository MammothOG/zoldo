#ifndef UNIT_H
#define UNIT_H

#include "element.h"


class HealthBar;

class Unit : public Element
{
private:
    //unit vertical movement in range [-1, 1]
    float verticalMov;

    //unit horizontal movement in range [-1, 1]
    float horizontalMov;

    HealthBar * healthBar;

    //health of the unit
    float health;

    // speed movement of the unit
    float movementSpeed;

    bool dead;

public:
    Unit();

    ~Unit();

    void stoneUnit();

    void moveUnit();

    void setVerticalMov(float vMov);

    float getVerticalMov() const;

    void setHorizontalMov(float hMov);

    float getHorizontalMov() const;

    HealthBar * getHealthBar() const;

    int getHealth() const;

    void setHealth(float value);

    void fitHealthBar();

    void giveDamage(float damage);

    float getMovementSpeed() const;

    void setMovementSpeed(float value);

    void addHealthBar(HealthBar * healthBar);

    bool isDead() const;

    void setDead(bool value);

};

#endif // UNIT_H
