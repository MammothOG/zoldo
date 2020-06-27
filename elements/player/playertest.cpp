#include "playertest.h"

PlayerTest::PlayerTest()
{
    element_name = PLAYER_TEST;

    setHeight(75);
    setWidth(75);

    setSprite(":/ressources/images/test/player_test.png");

    movementSpeed = 5;

    crit=0.3;
    critdmg = 0.4;
}
