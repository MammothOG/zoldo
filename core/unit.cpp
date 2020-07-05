#include "unit.h"

#include <math.h>

#include "healthbar.h"


Unit::Unit()
{
    //referencial point for Unit are center
    type = UNIT;

    health = 0;

    healthBar = new HealthBar(this);

    movementSpeed = 0;

    horizontalMov = 0.;
    verticalMov = 0.;
}

bool Unit::isUnitColliding(Element *element)
{
    if (element->getCollider()) {
        if (this->isColliding(element))
        {
            this->setX(this->x() - horizontalMov);
            this->setY(this->y() - verticalMov);

            return true;
        }
    }
    return false;

}

bool Unit::isColliding(Element *element)
{
    if (this->getBottom() + verticalMov > element->getTop() &&
            this->getTop() + verticalMov < element->getBottom() &&
            this->getLeft() + horizontalMov < element->getRight() &&
            this->getRight() + horizontalMov > element->getLeft()) {
        onCollision(element);
        return true;
    }
    return false;
}

void Unit::moveUnit()
{
    int newPosX = this->x() + horizontalMov;
    int newPosY = this->y() + verticalMov;

    healthBar->setPos(newPosX, newPosY);
    this->setPos(newPosX, newPosY);
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

HealthBar * Unit::getHealthBar() const
{
    return healthBar;
}

int Unit::getHealth() const
{
    return health;
}

void Unit::setHealth(int value)
{
    health = value;
}
