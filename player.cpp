#include "player.h"
#include "projectile.h"

Player::Player()
{

    setHeight(75);
    setWidth(75);

    movementSpeed = 5;

    crit=0.3;
    critdmg = 0.4;

    shootRate = 200;

    projectileList = new QList<Projectile*>();

    shootTimer = new QTimer(this);
    connect(shootTimer, SIGNAL(timeout()), this, SLOT(attack()));
    shootTimer->start(shootRate);

    setSprite(":/ressources/images/player_test.png");

}
void Player::attack()
{

    if (getHorizontalMov() == 0 && getVerticalMov() == 0)
    {
        Projectile * projectile = new Projectile();
        projectile->setPos(this->x(), this->y());

        projectile->setVerticalMov(directionVector[1]);
        projectile->setHorizontalMov(directionVector[0]);
        projectileList->append(projectile);
    }
}

QList<Projectile*> * Player::getProjectileList() const
{
    return projectileList;
}
