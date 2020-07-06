#include "testator.h"


Testator::Testator()
{
    setElementName(TESTATOR);

    //movement parameters
    setMoveRate(10);

    setShootRate(5);

    // setup enemy stats
    setMovementSpeed(5);

    setHealth(100);

    // setup graphics
    setHeight(50);
    setWidth(50);
    setSprite(":/ressources/images/test/enemy_test.png");
}

void Testator::move()
{
    setVerticalMov((rand() % 3) - 1);
    setHorizontalMov((rand() % 3) - 1);
}
