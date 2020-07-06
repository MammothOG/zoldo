#include "playertest.h"

PlayerTest::PlayerTest()
{
    setElementName(PLAYER_TEST);

    setHeight(75);
    setWidth(75);

    setSprite(":/ressources/images/test/player_test.png");

    setMovementSpeed(5);
    setShootRate(10);

    crit=0.3;
    critdmg = 0.4;

    setHealth(100);
}
