#ifndef UNIT_H
#define UNIT_H

#include "element.h"


class Unit : public Element
{
private:

    //unit vertical movement in range [-1, 1]
    float verticalMov;

    //unit horizontal movement in range [-1, 1]
    float horizontalMov;
protected:
    //health of the unit
    int health;

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
};

#endif // UNIT_H
