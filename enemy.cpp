#include "enemy.h"

Enemy::Enemy()
{

    setHeight(50);
    setWidth(50);

    movementSpeed = 5;

    movementFrequency = 0;
    movementFrequencyCounter = 0;

    health = 100;

    setSprite(":/ressources/images/enemy_test.png");

}

void Enemy::move()
{
    setVerticalMov(1);
    setHorizontalMov(1);
}

void Enemy::setMovementFrequency(int frequency)
{
    movementFrequency = frequency;
}
