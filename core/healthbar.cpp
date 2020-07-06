#include "healthbar.h"

#include <QGraphicsRectItem>
#include <QBrush>

#include "unit.h"


#include <QDebug>
HealthBar::HealthBar()
{
    totalHealth = 0;

    height = 4;
    width = 60;

    offsetWidth = -width/2;
    offsetHeight = -height/2;

    QRectF healthNewShape(offsetWidth, offsetHeight, width, height);
    QRectF healthOldShape(offsetWidth, offsetHeight, width, height);

    QBrush healthOldBrush(Qt::red);
    QBrush healthNewBrush(Qt::green);

    healthOld = new QGraphicsRectItem();
    healthNew = new QGraphicsRectItem();

    healthOld->setBrush(healthOldBrush);
    healthNew->setBrush(healthNewBrush);

    healthOld->setRect(healthOldShape);
    healthNew->setRect(healthNewShape);

    addToGroup(healthOld);
    addToGroup(healthNew);
}

bool HealthBar::setHealth(float health)
{
    if (health > 0)
    {
        width = width * health / totalHealth;
        qDebug() << width << totalHealth << health;
        healthNew->setRect(offsetWidth, offsetHeight, width, height);

        return true;
    }
    else
    {
        return false;
    }
}

int HealthBar::getOffsetHeight() const
{
    return offsetHeight;
}

void HealthBar::setOffsetHeight(int value)
{
    offsetHeight = value;
}

int HealthBar::getOffsetWidth() const
{
    return offsetWidth;
}

void HealthBar::setOffsetWidth(int value)
{
    offsetWidth = value;
}

int HealthBar::getTotalHealth() const {
    return totalHealth;
}

void HealthBar::setTotalHealth(int value)
{
    totalHealth = value;
}
