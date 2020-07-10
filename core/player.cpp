#include "player.h"

#include "projectile.h"
#include "config.h"
#include "elements/blocks/door.h"


Player::Player()
{
    won = false;

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
    if (element->isType(DOOR) && hasWon()) {
        Door * door = dynamic_cast<Door*>(element);
        door->openDoor();
    }
}

bool Player::hasWon() const
{
    return won;
}

void Player::setWon(bool value)
{
    won = value;
}
