#include "block.h"
#include "config.h"


Block::Block()
{
    setType(BLOCK);

    setCollider(true);

    setHeight(BLOCKSIZE);
    setWidth(BLOCKSIZE);
}
