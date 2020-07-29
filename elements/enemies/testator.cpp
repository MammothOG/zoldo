#include "testator.h"


Testator::Testator()
{
    setType(TESTATOR);

    //movement parameters
    setMoveRate(10);

    setShootRate(1);
    setProjectile(FIREBALL);

    // setup enemy stats
    setMovementSpeed(0);

    setHealth(100);

    // setup graphics
    setHeight(1);
    setWidth(1);
    setSprite(":/ressources/images/test/enemy_test.png");
}

void Testator::move()
{
    setVerticalMov((rand() % 3) - 1);
    setHorizontalMov((rand() % 3) - 1);
}
