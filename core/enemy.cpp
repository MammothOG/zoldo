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

Enemy::~Enemy()
{
    stopMovement();
}

void Enemy::move()
{
    qDebug() << "move method to be override";
}

void Enemy::shoot()
{
    fire();
}

void Enemy::stopMovement()
{
    moveTimer->stop();
    delete moveTimer;
}

void Enemy::stop()
{
    stopShooting();
    stopMovement();
}

void Enemy::setMoveRate(int rate)
{
    moveRate = rate;
    moveTimer->setInterval(moveRate);
}

int Enemy::getMoveRate() const
{
    return moveRate;
}
