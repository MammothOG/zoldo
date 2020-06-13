#include "unit.h"

#include <math.h>


Unit::Unit()
{

    type = "GenericUnit";

    immune = false;

    fixed = false;

    health = 0;

    movementSpeed = 0;

    horizontalMov = 0.;
    verticalMov = 0.;

    direction[0] = 0;
    direction[1] = -1;
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

#include <QtDebug>
void Unit::lockTarget(Unit * t)
{
    int newDirX = t->x() - this->x();
    int newDirY = t->y() - this->y();

    float normNewDir = sqrt(newDirX * newDirX + newDirY * newDirY);
    float normDir = sqrt(direction[0] * direction[0] + direction[1] * direction[1]);
    //qDebug() << normNewDir << " " << normDir;

    float scalar = newDirX * direction[0] + newDirY * direction[1];

    float rotAngle = scalar / (normDir * normNewDir);
    qDebug() << rotAngle;

    setRotation(rotAngle);
}
