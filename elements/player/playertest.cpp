#include "playertest.h"

#include "config.h"

PlayerTest::PlayerTest()
{
    setType(PLAYER_TEST);

    setHeight(BLOCKSIZE * 1.5);
    setWidth(BLOCKSIZE * 1.5);

    setSprite(":/ressources/images/test/player_test.png");

    setMovementSpeed(5);
    setShootRate(20);

    crit=0.3;
    critdmg = 0.4;

    setHealth(100);
}
