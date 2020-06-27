#ifndef MAP_H
#define MAP_H

#include <QList>


class Level;

class Player;

class Adventure
{
private:
    QList<Level*> * levelList;

    Player * player;

    int currentLevel;

public:
    Adventure();

    void generateTestAdventure();

    Level * getCurrentLevel() const;

    Player * getPlayer() const;
};

#endif // MAP_H
