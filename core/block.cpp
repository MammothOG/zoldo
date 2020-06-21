#include "block.h"
#include "config.h"


Block::Block()
{
    type = BLOCK;

    setHeight(BLOCK_SIZE);
    setWidth(BLOCK_SIZE);
}
