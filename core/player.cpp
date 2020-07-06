#include "player.h"

#include "projectile.h"

Player::Player()
{
    setType(PLAYER);
}

void Player::shoot()
{
    if (this->getHorizontalMov() == 0 && this->getVerticalMov() == 0)
    {
        fire();
    }
}
