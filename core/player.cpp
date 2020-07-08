#include "player.h"

#include "projectile.h"
#include "config.h"

Player::Player()
{
    setType(PLAYER);

    setHeight(BLOCKSIZE * 1.5);
    setWidth(BLOCKSIZE * 1.5);
}

void Player::shoot()
{
    if (this->getHorizontalMov() == 0 && this->getVerticalMov() == 0)
    {
        fire();
    }
}
