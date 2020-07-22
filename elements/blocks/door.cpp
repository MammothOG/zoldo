#include "door.h"

#include "core/player.h"

Door::Door()
{
    setType(DOOR);

    setExit(true);

    setStyleDir("exits");

    setSprite(":/ressources/images/test/door_test.png");
}

void Door::onActivate()
{
    setSprite(":/ressources/images/test/door_open_test.png");
}
