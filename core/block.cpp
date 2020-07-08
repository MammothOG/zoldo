#include "block.h"
#include "config.h"


Block::Block()
{
    setType(BLOCK);


    setHeight(BLOCKSIZE);
    setWidth(BLOCKSIZE);
}
