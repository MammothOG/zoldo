#include "enemy.h"

Enemy::Enemy()
{

    setHeight(50);
    setWidth(50);

    movementSpeed = 2;

    movementFrequency = 10;
    movementFrequencyCounter = 0;

    health = 100;

    setSprite(":/ressources/images/enemy_test.png");

}

void Enemy::move()
{
    movementFrequencyCounter++;

    if(movementFrequencyCounter == movementFrequency)
    {
        setVerticalMov((rand() % 3) - 1);
        setHorizontalMov((rand() % 3) - 1);

        movementFrequencyCounter = 0;
    }
}

void Enemy::setMovementFrequency(int frequency)
{
    movementFrequency = frequency;
}
