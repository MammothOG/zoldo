#include <QtDebug>

#include "enemy.h"


Enemy::Enemy()
{

    setType(ENEMY);

    moveRate = 1000;

    moveTimer  = new QTimer(this);

    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));

    moveTimer->start(moveRate);

    setShootRate(100);
}

void Enemy::move()
{
    qDebug() << "move method to be override";
}

void Enemy::shoot()
{
    fire();
}

void Enemy::setMoveRate(int rate)
{
    moveRate = rate;
}

int Enemy::getMoveRate() const
{
    return moveRate;
}
