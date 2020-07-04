#include "block.h"
#include "config.h"


Block::Block()
{
    type = BLOCK;

    collider = true;

    setHeight(BLOCK_SIZE);
    setWidth(BLOCK_SIZE);
}
