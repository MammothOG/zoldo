#include "healthbar.h"

#include <QGraphicsRectItem>

#include "unit.h"


HealthBar::HealthBar()
{
    height = 0;
    width = 0;

    totalHealth = 0;

    setZValue(2);

    setPos(0, 0);

    followingUnit = false;

}

bool HealthBar::setHealth(float health)
{
    if (health > 0)
    {
        onNewHealth(health);
        return true;
    }
    else
    {
        onNewHealth(0);
        return false;
    }
}

int HealthBar::getTotalHealth() const {
    return totalHealth;
}

void HealthBar::setTotalHealth(int value)
{
    totalHealth = value;
}

bool HealthBar::isFollowingUnit() const
{
    return followingUnit;
}

void HealthBar::setFollowingUnit(bool value)
{
    followingUnit = value;
}
