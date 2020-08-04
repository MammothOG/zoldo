#ifndef BAT_H
#define BAT_H

#include "core/enemy.h"


class Bat : public Enemy
{
    Q_OBJECT
public:
    Bat();

    void move() override;
};

#endif // BAT_H
