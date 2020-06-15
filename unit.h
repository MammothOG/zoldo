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

    int rotAngle;

protected:
    // unit type
    QString type;

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

    float getVerticalMov() const;

    void setHorizontalMov(float hMov);

    float getHorizontalMov() const;

    void setType(QString t);

    QString getType() const;

    void lockTarget(const Unit * const target);

};

#endif // UNIT_H
