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

    bool win;

public:
    Adventure();

    bool nextLevel();

    bool load(QString name);

    void generateTestAdventure();

    Level * getCurrentLevel() const;

    Player * getPlayer() const;

    bool isWin() const;

    void setWin(bool value);
};

#endif // MAP_H
