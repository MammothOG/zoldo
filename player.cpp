#include "player.h"

Player::Player()
{

    setHeight(75);
    setWidth(75);

    movementSpeed = 2;

    crit=0.3;
    critdmg = 0.4;


    setSprite(":/ressources/images/enemy_test.png");

}

void Player::attack(float crit, float critdmg)
{
    //   weapon->sendAttack(float crit, float critdmg);
}
