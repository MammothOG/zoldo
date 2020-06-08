#include "map.h"
#include "level.h"


Map::Map()
{
    levelList = new QList<Level*>();
    player = new Player();
}
