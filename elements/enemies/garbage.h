#ifndef GARBAGE_H
#define GARBAGE_H

#include "core/enemy.h"


class Garbage : public Enemy
{
    Q_OBJECT
public:
    Garbage();

    void move() override;
};

#endif // GARBAGE_H
