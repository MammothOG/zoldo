#include "unit.h"

#include <math.h>


Unit::Unit()
{
    //referencial point for Unit are center
    type = "GenericUnit";

    health = 0;

    movementSpeed = 0;

    horizontalMov = 0.;
    verticalMov = 0.;
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

