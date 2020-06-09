#ifndef MAP_H
#define MAP_H

#include <QList>

#include "level.h"
#include "player.h"


class Adventure
{
private:
    QList<Level*> * levelList;

    Player * player;

    int currentLevel;

public:
    Adventure();

};

#endif // MAP_H
