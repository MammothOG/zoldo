#include "healthbar.h"

#include <QGraphicsRectItem>
#include <QBrush>

#include "unit.h"


#include <QDebug>
HealthBar::HealthBar(Unit * unit)
{
    totalHealth = unit->getHealth();

    height = 10;
    width = 60;

    offsetWidth = -width/2;
    offsetHeight = -height;

    QRectF healthNewShape(offsetWidth, offsetHeight, width, height);
    QRectF healthOldShape(offsetWidth, offsetHeight, width, height);

    QBrush healthNewBrush(Qt::blue);
    QBrush healthOldBrush(Qt::red);

    healthNew = new QGraphicsRectItem();
    healthOld = new QGraphicsRectItem();

    healthNew->setBrush(healthNewBrush);
    healthOld->setBrush(healthOldBrush);

    healthNew->setRect(healthNewShape);
    healthOld->setRect(healthOldShape);

    addToGroup(healthNew);
    addToGroup(healthOld);
}

bool HealthBar::setHealth(float health)
{
    if (health > 0)
    {
        healthOld->setRect(offsetWidth, offsetHeight, width, height);

        width = health / totalHealth * width;
        healthNew->setRect(offsetWidth, offsetHeight, width, height);

        return true;
    }
    else
    {
        return false;
    }
}
