#include <QtDebug>

#include "enemy.h"


Enemy::Enemy()
{
    moveRate = 1000;
    shootRate = 100;

    type = "Enemy";

    moveTimer  = new QTimer(this);
    shootTimer = new QTimer(this);

    connect(moveTimer, SIGNAL(timeout()), this, SLOT(move()));
    connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));

    moveTimer->start(moveRate);
}

void Enemy::move()
{
    qDebug() << "move method to be override";
}

void Enemy::shoot()
{
    qDebug() << "shoot method has to be override";
}

void Enemy::setShootRate(int rate)
{
    shootRate = rate;
}

int Enemy::getShootRate() const
{
    return shootRate;
}

void Enemy::setMoveRate(int rate)
{
    moveRate = rate;
}

int Enemy::getMoveRate() const
{
    return moveRate;
}
