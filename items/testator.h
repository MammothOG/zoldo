#ifndef TESTATOR_H
#define TESTATOR_H

#include "core/enemy.h"


class Testator : public Enemy
{
    Q_OBJECT
private:

    //set time of enemy pause beafore starting a new movement
    int pauseTime;

public:
    Testator();

    void move() override;

};

#endif // TESTATOR_H
