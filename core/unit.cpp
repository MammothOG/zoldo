#include "unit.h"

#include <math.h>


Unit::Unit()
{
    //referencial point for Unit are center
    type = UNIT;

    health = 0;

    movementSpeed = 0;

    horizontalMov = 0.;
    verticalMov = 0.;
}

bool Unit::isUnitColliding(Element *element)
{
    if (this->isColliding(element))
    {
        this->setX(this->x() - horizontalMov);
        this->setY(this->y() - verticalMov);

        return true;
    }
    return false;

}

bool Unit::isColliding(Element *element)
{
    if (element->getCollider()) {
        if (this->getBottom() + verticalMov > element->getTop() &&
                this->getTop() + verticalMov < element->getBottom() &&
                this->getLeft() + horizontalMov < element->getRight() &&
                this->getRight() + horizontalMov > element->getLeft()) {
            onCollision(element);
            return true;
        }
    }
    return false;
}

void Unit::moveUnit()
{
    this->setPos(this->x() + horizontalMov, this->y() + verticalMov);
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
