#include "unit.h"

#include <math.h>


Unit::Unit()
{
    //referencial point for Unit are center
    type = "GenericUnit";

    immune = false;

    fixed = false;

    health = 0;

    movementSpeed = 0;

    horizontalMov = 0.;
    verticalMov = 0.;

    rotAngle = 0;
}

void Unit::setVerticalMov(float vMov)
{
    verticalMov = vMov * movementSpeed;
}

float Unit::getVerticalMov() const
{
    return verticalMov;
}

void Unit::setHorizontalMov(float hMov)
{
    horizontalMov = hMov * movementSpeed;
}

float Unit::getHorizontalMov() const
{
    return horizontalMov;
}

void Unit::lockTarget(const Unit * const target)
{
    int newDirX = target->x() - this->x();
    int newDirY = target->y() - this->y();

    float normNewDir = sqrt(newDirX * newDirX + newDirY * newDirY);

    rotAngle = acos( -newDirY /  normNewDir) * 180/3.14;

    if(newDirX < 0)
        rotAngle *= -1;

    setRotation(rotAngle);
}
