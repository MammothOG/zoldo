#include "adventure.h"
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

Level * Adventure::getCurrentLevel()
{
    return levelList->at(currentLevel);
}
