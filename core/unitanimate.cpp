#include "unitanimate.h"

#include <math.h>

#include "tools/elementfactory.h"
#include "core/projectile.h"
#include "elements/projectile/testprojectile.h"


UnitAnimate::UnitAnimate()
{

    setType(UNIT_ANIMATE);

    // angle de rotation of the image
    currentRotation = 0;

    setCenterAsReferencial();

    direction = QVector2D(0, -1);

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
    projectile = TEST_PROJECTILE;
}

UnitAnimate::~UnitAnimate()
{
    delete projectileList;
}

void UnitAnimate::lockTarget(const Unit * const target)
{
    if (!target->isDead()) {

        direction.setX(target->x() - this->x());
        direction.setY(target->y() - this->y());

        currentRotation = acos( -direction.y() /  direction.length()) * 180/3.14;

        if(direction.x() < 0)
            currentRotation *= -1;

        setRotation(currentRotation + getDefaultRotation());
    }
}

int UnitAnimate::getCurrentRotation() const
{
    return currentRotation;
}

int UnitAnimate::getProjectile() const
{
    return projectile;
}

void UnitAnimate::startShooting()
{
    shootTimer->start();
}

void UnitAnimate::stopShooting()
{
    shootTimer->stop();
    resetRotation();
}

void UnitAnimate::setProjectile(int value)
{
    projectile = value;
}

void UnitAnimate::shoot()
{
    // seting a default projectile
    fire();
}

void UnitAnimate::fire()
{
    Element * el = ElementFactory::create(projectile);

    if(el->isType(PROJECTILE)) {
        Projectile * proj = dynamic_cast<Projectile*>(el);
        proj->setOwner(this);

        proj->setPos(this->x(), this->y());

        proj->setDefaultRotation(currentRotation + proj->getDefaultRotation());

        proj->setHorizontalMov(direction.normalized().x());
        proj->setVerticalMov(direction.normalized().y());

        projectileList->append(proj);
    }
    else {
        qWarning("UnitAnimate projectile are not projectile type.");
    }
}

float UnitAnimate::getTargetDistance() const
{
    return targetDistance;
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
