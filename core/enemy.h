#ifndef ENNEMY_H
#define ENNEMY_H

#include <QTimer>

#include "unitanimate.h"

class Enemy : public UnitAnimate
{
    Q_OBJECT
private:
    //set the interval before starting new movement
    int moveRate;

    QTimer * moveTimer;

public:
    Enemy();

    void setMoveRate(int rate);

    int getMoveRate() const;

    void shoot() override;

public slots:
    //refresh the direction movement
    virtual void move();
};

#endif // ENNEMY_H
