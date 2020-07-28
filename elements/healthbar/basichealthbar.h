#ifndef BASICHEALTHBAR_H
#define BASICHEALTHBAR_H

#include "core/healthbar.h"


class BasicHealthBar : public HealthBar
{
private:
    int offsetHeight;

    int offsetWidth;

    int newWidth;

public:
    BasicHealthBar();

    ~BasicHealthBar();

    QGraphicsRectItem * healthNew;

    QGraphicsRectItem * healthOld;

    void setOffsetHeight(int value);

    void onNewHealth(float health) override;

};

#endif // BASICHEALTHBAR_H
