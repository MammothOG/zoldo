#include "player.h"

#include "projectile.h"

Player::Player()
{

    setHeight(75);
    setWidth(75);

    setSprite(":/ressources/images/test/player_test.png");

    movementSpeed = 5;

    crit=0.3;
    critdmg = 0.4;

}

void Player::shoot()
{
    if (this->getHorizontalMov() == 0 && this->getVerticalMov() == 0)
    {
        fire();
    }
}
