#ifndef ZELDAHEALTHBAR_H
#define ZELDAHEALTHBAR_H

#include "core/healthbar.h"

#include <QGraphicsPixmapItem>
#include <QList>


class ZeldaHealthBar : public HealthBar
{
private:
    int spaceSize;

    float firstHealthLimit;

    float secondHealtLimit;

    QPixmap heartFullPixmap;

    QPixmap heartHalfPixmap;

    QPixmap heartEmptyPixmap;

    QList<QGraphicsPixmapItem*> * heartList;

    virtual void onNewHealth(float health) override;

public:
    ZeldaHealthBar(int heartNumber);
};

#endif // ZELDAHEALTHBAR_H
