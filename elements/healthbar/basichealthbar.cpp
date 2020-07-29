#include "basichealthbar.h"

#include <QBrush>

#include "config.h"


BasicHealthBar::BasicHealthBar(int offWidth, int offHeight)
{
    setFollowingUnit(true);

    height = 0.1 * BLOCKSIZE;
    width = 1 * BLOCKSIZE;

    newWidth = width;

    offsetWidth = offWidth-width/2;
    offsetHeight = -offHeight-height/2;

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

BasicHealthBar::~BasicHealthBar()
{
    delete healthNew;
    delete healthOld;
}

void BasicHealthBar::setOffsetHeight(int value)
{
    offsetHeight = value;
    healthNew->setRect(offsetWidth, offsetHeight, newWidth, height);
    healthOld->setRect(offsetWidth, offsetHeight, newWidth, height);
}

void BasicHealthBar::onNewHealth(float health)
{
    newWidth = width * health / totalHealth;
    healthNew->setRect(offsetWidth, offsetHeight, newWidth, height);
}
