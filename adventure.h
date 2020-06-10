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

    void generateTestAdventure();

    Level * getCurrentLevel();
};

#endif // MAP_H
