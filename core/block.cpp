#include "block.h"
#include "config.h"


Block::Block()
{
    setType(BLOCK);

    setCollider(true);

    setHeight(BLOCK_SIZE);
    setWidth(BLOCK_SIZE);
}
