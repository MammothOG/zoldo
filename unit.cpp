#include "unit.h"

Unit::Unit()
{

    movingUp = false;
    movingDown = false;
    movingLeft = false;
    movingDown = false;

    immune = false;

    fixed = false;

    health = 0;

    movementSpeed = 0;

    horizontalMov = 0.;
    verticalMov = 0.;
}

void Unit::setVerticalMov(float vMov)
{
    verticalMov = vMov;
}

void Unit::setHorizontalMov(float hMov)
{
    horizontalMov = hMov;
}
