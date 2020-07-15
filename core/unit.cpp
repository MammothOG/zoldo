#include "unit.h"


#include "healthbar.h"


#include <QDebug>
Unit::Unit()
{
    //referencial point for Unit are center
    setType(UNIT);

    health = 0;

    dead = false;

    healthBar = nullptr;

    movementSpeed = 0;

    horizontalMov = 0.;
    verticalMov = 0.;
}

Unit::~Unit()
{
    if (healthBar != nullptr)
    {
        delete healthBar;
    }
}

void Unit::addHealthBar(HealthBar * healthBar)
{
    this->healthBar = healthBar;

    this->healthBar->setTotalHealth(health);
    this->healthBar->setOffsetHeight(-getHeight()/2);
}

void Unit::stoneUnit()
{
    int stonePosX = this->x() - horizontalMov;
    int stonePosY = this->y() - verticalMov;

    this->setX(stonePosX);
    this->setY(stonePosY);

    if (healthBar != nullptr)
    {
        healthBar->setX(stonePosX);
        healthBar->setY(stonePosY);
    }
}

void Unit::moveUnit()
{
    int newPosX = this->x() + horizontalMov;
    int newPosY = this->y() + verticalMov;

    if (healthBar != nullptr)
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

#include <QDebug>
void Unit::giveDamage(float damage)
{
    this->health -= damage;

    if (this->health <= 0) {
        setDead(true);
    }

    if (healthBar != nullptr)
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
}

float Unit::getMovementSpeed() const
{
    return movementSpeed;
}

void Unit::setMovementSpeed(float value)
{
    movementSpeed = value;
}

bool Unit::isDead() const
{
    return dead;
}

void Unit::setDead(bool value)
{
    dead = value;
}
