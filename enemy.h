#ifndef ENNEMY_H
#define ENNEMY_H

#include <QTimer>

#include "unit.h"


class Enemy : public Unit
{
    Q_OBJECT
private:
    //set the interval before starting new movement
    int moveRate;

    //set the shooting rate of the enemy
    int shootRate;

    QTimer * moveTimer;

    QTimer * shootTimer;

public:
    Enemy();

    void setShootRate(int rate);

    int getShootRate() const;

    void setMoveRate(int rate);

    int getMoveRate() const;

public slots:
    //refresh the direction movement
    virtual void move();

    virtual void shoot();
};

#endif // ENNEMY_H
