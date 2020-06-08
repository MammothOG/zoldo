#ifndef MAP_H
#define MAP_H

#include <QList>

#include "level.h"
#include "player.h"


class Map
{
private:
    QList<Level*> * levelList;

    Player * player;

public:
    Map();

};

#endif // MAP_H
