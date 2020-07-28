#include "door.h"

#include "core/player.h"

Door::Door()
{
    setType(DOOR);

    setExit(true);

    setStyleDir("doors");

    setSprite(":/ressources/images/test/door_test.png");
}

void Door::onActivate()
{
    setStyle("activate/" + getImageName());
}
