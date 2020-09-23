#ifndef MAP_H
#define MAP_H

#include <QList>


class Level;

class Player;

class Adventure
{
private:
    QList<QString> * levelList;

    Level * currentLevel;

    int levelIndex;

    Player * player;

    bool win;

    QString music;

public:
    Adventure();

    bool nextLevel();

    bool load(QString name);

    void generateTestAdventure();

    Level * getCurrentLevel() const;

    Player * getPlayer() const;

    bool isWin() const;

    void setWin(bool value);

    QString getMusic() const;
};

#endif // MAP_H
