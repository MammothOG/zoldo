#ifndef DESPICABLEBOSS_H
#define DESPICABLEBOSS_H

#include "core/enemy.h"

class DespicableBoss : public Enemy
{
public:
    DespicableBoss();

    void move() override;
};

#endif // DESPICABLEBOSS_H
