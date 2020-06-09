#include "adventure.h"
#include "level.h"


Adventure::Adventure()
{
    levelList = new QList<Level*>();
    player = new Player();
}
