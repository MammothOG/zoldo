#ifndef DOOR_H
#define DOOR_H

#include "core/block.h"

class Door : public Block
{
public:
    Door();

    void openDoor();
};

#endif // DOOR_H
