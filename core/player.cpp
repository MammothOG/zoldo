#include "player.h"

#include "projectile.h"
#include "config.h"
#include "elements/blocks/door.h"


Player::Player()
{
    setType(PLAYER);

    setZValue(1);
}

void Player::shoot()
{
    if (this->getHorizontalMov() == 0 && this->getVerticalMov() == 0)
    {
        fire();
    }
}

void Player::onCollision(Element *element)
{
    //if (element->isExit() && element->isActivated()) {
    //    qDebug() << "player changing level";
    //}
}
