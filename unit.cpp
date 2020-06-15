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

    targetDistance = 0;

    directionVector[0] = 0;

    directionVector[1] = -1;

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

    targetDistance = sqrt(newDirX * newDirX + newDirY * newDirY);

    directionVector[0] = newDirX / targetDistance;
    directionVector[1] = newDirY / targetDistance;



    rotAngle = acos( -newDirY /  targetDistance) * 180/3.14;

    if(newDirX < 0)
        rotAngle *= -1;

    setRotation(rotAngle);
}

float Unit::getTargetDistance() const
{
    return targetDistance;
}
