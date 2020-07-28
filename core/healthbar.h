#ifndef HEALTHBAR_H
#define HEALTHBAR_H

#include <QGraphicsItemGroup>


class Unit;

class HealthBar : public QGraphicsItemGroup
{
private:
    bool followingUnit;

protected:
    int height;

    int width;

    virtual void onNewHealth(float health) {}

    float totalHealth;

    void setFollowingUnit(bool value);

public:
    HealthBar();

    bool setHealth(float health);

    int getTotalHealth() const;

    void setTotalHealth(int value);

    bool isFollowingUnit() const;
};

#endif // HEALTHBAR_H
