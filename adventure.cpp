#include "adventure.h"
#include "player.h"
#include "level.h"


Adventure::Adventure()
{
    levelList = new QList<Level*>();
    player = new Player();

    currentLevel = 0;
}

void Adventure::generateTestAdventure()
{
    Level * level = new Level();
    level->generateTestLevel();

    levelList->append(level);
}

Level * Adventure::getCurrentLevel() const
{
    return levelList->at(currentLevel);
}

Player * Adventure::getPlayer()
{
    return player;
}
