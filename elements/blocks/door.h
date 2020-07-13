#ifndef DOOR_H
#define DOOR_H

#include "core/block.h"

class Door : public Block
{
public:
    Door();

    void onActivate() override;
};

#endif // DOOR_H
