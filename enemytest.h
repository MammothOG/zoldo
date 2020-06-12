#ifndef ENNEMY_H
#define ENNEMY_H

#include "unit.h"


class Enemy : public Unit
{
private:
    //counter frame before new movement
    int movementFrequencyCounter;

    //set the interval before starting new movement
    int movementFrequency;

    //set time of enemy pause beafore starting a new movement
    int pauseTime;

public:
    Enemy();

    //refresh the direction movement
    void move();

    void setMovementFrequency(int frequency);
};

#endif // ENNEMY_H
