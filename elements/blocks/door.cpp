#include "door.h"

#include "core/player.h"

Door::Door()
{
    setType(DOOR);

    setSprite(":/ressources/images/test/door_test.png");
}

void Door::openDoor()
{
    setSprite(":/ressources/images/test/door_open_test.png");
}
