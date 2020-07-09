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

    Unit * unit;
public:
    HealthBar();

    ~HealthBar();

    bool setHealth(float health);

    QGraphicsRectItem * healthNew;

    QGraphicsRectItem * healthOld;

    int getOffsetHeight() const;

    void setOffsetHeight(int value);

    int getOffsetWidth() const;

    void setOffsetWidth(int value);

    int getTotalHealth() const;

    void setTotalHealth(int value);
};

#endif // HEALTHBAR_H
