#include "adventure.h"
#include "level.h"

#include "elements/player/playertest.h"


Adventure::Adventure()
{
    levelList = new QList<Level*>();
    currentLevel = 0;

    player = new PlayerTest();
    player->setCenterAsReferencial();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
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

Player * Adventure::getPlayer() const
{
    return player;
}
