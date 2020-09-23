#ifndef UNITANIMATE_H
#define UNITANIMATE_H

#include <QTimer>
#include <QVector2D>

#include "unit.h"

class Projectile;

class UnitAnimate : public Unit
{
    Q_OBJECT
private:
    int currentRotation;

    QVector2D direction;

    float targetDistance;

    QList<Projectile*> * projectileList;

    float shootRate;

    QTimer * shootTimer;

    int projectile;

    QMap<QString, QPixmap> * directionSprites;

    bool directionSpritesExist;

protected:
    void setProjectile(int value);

    void insertDirectionSprite(QString key, QString sprite);

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
