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
    int health;

protected:

    // speed movement of the unit
    float movementSpeed;

    virtual void onCollision(Element * element){};

public:
    Unit();

    bool isUnitColliding(Element * element);

    void moveUnit();

    bool isColliding(Element * element);

    void setVerticalMov(float vMov);

    float getVerticalMov() const;

    void setHorizontalMov(float hMov);

    float getHorizontalMov() const;

    HealthBar * getHealthBar() const;

    int getHealth() const;

    void setHealth(int value);
};

#endif // UNIT_H
