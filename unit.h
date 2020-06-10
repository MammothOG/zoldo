#ifndef UNIT_H
#define UNIT_H

#include "element.h"

class Unit : public Element
{
private:
    bool movingUp;

    bool movingDown;

    bool movingLeft;

    bool movingRight;

    //unit vertical movement in range [-1, 1]
    float verticalMov;

    //unit horizontal movement in range [-1, 1]
    float horizontalMov;

protected:
    //health of the unit
    int health;

    // true if the unit is imune against damage
    bool immune;

    // true if the unit can't move
    bool fixed;

    // speed movement of the unit
    float movementSpeed;

public:
    Unit();

    void setVerticalMov(float vMov);

    void setHorizontalMov(float hMov);

    float getVerticalMov() const;

    float getHorizontalMov() const;
};

#endif // UNIT_H
