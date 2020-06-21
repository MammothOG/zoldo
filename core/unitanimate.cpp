#include "unitanimate.h"

#include <math.h>

#include "projectile.h"


UnitAnimate::UnitAnimate()
{

    type = UNIT_ANIMATE;

    // angle de rotation of the image
    rotAngle = 0;

    // direction where the unit look
    directionVector[0] = 0;
    directionVector[1] = -1;

    // distance
    targetDistance = 0;

    // interval between each shoot
    shootRate = 500;
    shootTimer = new QTimer(this);
    connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
    shootTimer->start(shootRate);

    // projectile shooted
    projectileList = new QList<Projectile*>();

    // projectile shooted
    projectile = new Projectile();
    projectile->projectileTest();

}

void UnitAnimate::lockTarget(const Unit * const target)
{
    int newDirX = target->x() - this->x();
    int newDirY = target->y() - this->y();

    targetDistance = sqrt(newDirX * newDirX + newDirY * newDirY);

    directionVector[0] = newDirX / targetDistance;
    directionVector[1] = newDirY / targetDistance;

    rotAngle = acos( -newDirY /  targetDistance) * 180/3.14;

    if(newDirX < 0)
        rotAngle *= -1;

    setRotation(rotAngle);
}

void UnitAnimate::shoot()
{
    // seting a default projectile
    fire();
}

void UnitAnimate::fire()
{
    Projectile * proj = new Projectile(projectile);

    proj->setPos(this->x(), this->y());

    proj->setHorizontalMov(directionVector[0]);
    proj->setVerticalMov(directionVector[1]);

    projectileList->append(proj);
}

float UnitAnimate::getTargetDistance() const
{
    return targetDistance;
}

const float* UnitAnimate::getDirectionVector() const
{
    return directionVector;
}

QList<Projectile*> * UnitAnimate::getProjectileList() const
{
    return projectileList;
}

int UnitAnimate::getShootRate() const
{
    return shootRate;
}

void UnitAnimate::setShootRate(int value)
{
    shootRate = value;
}
