#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QGraphicsItemGroup>


class Unit;

class HealthBar : public QGraphicsItemGroup
{
private:
    int height;

    int width;

    int offsetHeight;

    int offsetWidth;

    int totalHealth;
public:
    HealthBar(Unit * unit);

    bool setHealth(float health);

    QGraphicsRectItem * healthNew;

    QGraphicsRectItem * healthOld;
};

#endif // HEALTHBAR_H
