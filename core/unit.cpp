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
    //this->healthBar->setOffsetHeight(-getHeight()/2);
}

void Unit::stoneUnit()
{
    float stonePosX = this->x() - horizontalMov * movementSpeed;
    float stonePosY = this->y() - verticalMov * movementSpeed;

    this->setX(stonePosX);
    this->setY(stonePosY);

    if (healthBar != nullptr && healthBar->isFollowingUnit())
    {
        healthBar->setX(stonePosX);
        healthBar->setY(stonePosY);
    }
}

void Unit::moveUnit()
{
    float newPosX = this->x() + horizontalMov * movementSpeed;
    float newPosY = this->y() + verticalMov * movementSpeed;

    if (healthBar != nullptr && healthBar->isFollowingUnit())
        healthBar->setPos(newPosX, newPosY);

    this->setPos(newPosX, newPosY);
}

void Unit::setVerticalMov(float vMov)
{
    verticalMov = vMov;
}

float Unit::getVerticalMov() const
{
    return verticalMov;
}

void Unit::setHorizontalMov(float hMov)
{
    horizontalMov = hMov;
}

float Unit::getHorizontalMov() const
{
    return horizontalMov;
}

void Unit::giveDamage(float damage)
{
    this->health -= damage;

    if (this->health <= 0)
        setDead(true);

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
