#ifndef UNIT_H
#define UNIT_H

#include "element.h"

class Unit : public Element
{
private:
    bool movingUp;

    bool movingDown;

    bool movingLeft;

    bool movingRight;

    bool immune;

    bool fixed;

public:
    Unit();

};

#endif // UNIT_H
