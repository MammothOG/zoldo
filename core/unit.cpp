#include "unit.h"

#include <math.h>

#include "healthbar.h"


Unit::Unit()
{
    //referencial point for Unit are center
    setType(UNIT);

    health = 0;

    healthBar = new HealthBar();

    movementSpeed = 0;

    horizontalMov = 0.;
    verticalMov = 0.;
}

#include <QDebug>
void Unit::stoneUnit()
{
    this->setX(this->x() - horizontalMov);
    this->setY(this->y() - verticalMov);

    healthBar->setX(healthBar->x() - horizontalMov);
    healthBar->setY(healthBar->y() - verticalMov);
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

void Unit::giveDamage(float damage)
{
    this->health -= damage;
    healthBar->setHealth(this->health);
}

HealthBar * Unit::getHealthBar() const
{
    return healthBar;
}

int Unit::getHealth() const
{
    return health;
}

void Unit::setHealth(float value)
{
    health = value;
    healthBar->setTotalHealth(value);
    healthBar->setOffsetHeight(-getHeight()/2);
    qDebug() << healthBar->getTotalHealth();
}

float Unit::getMovementSpeed() const
{
    return movementSpeed;
}

void Unit::setMovementSpeed(float value)
{
    movementSpeed = value;
}
