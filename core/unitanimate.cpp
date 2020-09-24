#include "unitanimate.h"

#include <math.h>
#include <QSoundEffect>

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
    shootRate = 1000;
    shootTimer = new QTimer(this);
    connect(shootTimer, SIGNAL(timeout()), this, SLOT(shoot()));
    shootTimer->start(shootRate);

    // projectile shooted
    projectileList = new QList<Projectile*>();

    // projectile shooted
    projectile = TEST_PROJECTILE;

    directionSprites = new QMap<QString, QPixmap>();
    directionSpritesExist = false;

    shootEffect = new QSoundEffect();
    shootEffect->setVolume(3);
}

UnitAnimate::~UnitAnimate()
{
    stopShooting();
}

void UnitAnimate::lockTarget(const Unit * const target)
{
    if (!target->isDead()) {

        direction.setX(target->x() - this->x());
        direction.setY(target->y() - this->y());

        currentRotation = acos( -direction.y() /  direction.length()) * 180/3.14;

        if(direction.x() < 0)
            currentRotation *= -1;

        targetDistance = direction.length();
        //setRotation(currentRotation + getDefaultRotation());

        if (directionSpritesExist) {
            int rot = currentRotation;
            if ((rot > 125 && rot <= 180) || (rot <= -125 && rot > -180)) {
                setPixmap(directionSprites->value("D"));
            }
            else if (rot > 45 && rot <= 125) {
                setPixmap(directionSprites->value("R"));
            }
            else if (rot > -45 && rot <= 45) {
                setPixmap(directionSprites->value("U"));
            }
            else if (rot <= -45 && rot > -125) {
                setPixmap(directionSprites->value("L"));
            }
        }
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
    shootTimer->start(shootRate);
}

void UnitAnimate::defaultDirectionSprite()
{
    if(directionSpritesExist) {
        setPixmap(directionSprites->value("U"));
    }
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

void UnitAnimate::insertDirectionSprite(QString key, QString spritePath)
{
    QPixmap sprite = QPixmap(spritePath);
    sprite = sprite.scaled(this->getWidth(), this->getHeight());
    directionSprites->insert(key, sprite);

    if(directionSprites->contains("D") &&
            directionSprites->contains("U") &&
            directionSprites->contains("R") &&
            directionSprites->contains("L")) {
        directionSpritesExist = true;
    }

}

void UnitAnimate::shoot()
{
    // seting a default projectile
    fire();
}

void UnitAnimate::setShootRate(int value)
{
    shootRate = value;
    shootTimer->setInterval(shootRate);
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

        // play sound
        if (!proj->getSound().isEmpty()) {
            if(shootEffect->source().isEmpty()) {
                shootEffect->setSource(QUrl::fromLocalFile(proj->getSound()));
            }
            shootEffect->play();
        }
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
