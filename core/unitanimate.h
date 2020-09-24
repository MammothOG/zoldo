#ifndef UNITANIMATE_H
#define UNITANIMATE_H

#include <QTimer>
#include <QVector2D>
#include <QSoundEffect>

#include "unit.h"

class Projectile;

class UnitAnimate : public Unit
{
    Q_OBJECT
private:
    int currentRotation;

    QList<Projectile*> * projectileList;

    float shootRate;

    QTimer * shootTimer;

    int projectile;

    QMap<QString, QPixmap> * directionSprites;

    bool directionSpritesExist;

    QSoundEffect * shootEffect;

protected:
    void setProjectile(int value);

    void insertDirectionSprite(QString key, QString sprite);

    float targetDistance;

    QVector2D direction;

public slots:
    virtual void shoot();

public:
    UnitAnimate();

    ~UnitAnimate();

    void lockTarget(const Unit * const target);

    float getTargetDistance() const;

    QList<Projectile*> * getProjectileList() const;

    void fire();

    int getShootRate() const;

    void setShootRate(int value);

    int getCurrentRotation() const;

    int getProjectile() const;

    void stopShooting();

    void startShooting();
};

#endif // UNITANIMATE_H
