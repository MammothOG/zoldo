#include "elementfactory.h"

#include "core/element.h"

#include "elements/blocks/wall.h"
#include "elements/blocks/water.h"
#include "elements/background/testbackground.h"
#include "elements/enemies/testator.h"
#include "elements/player/playertest.h"
#include "elements/projectile/testprojectile.h"

Element * ElementFactory::create(int elementFlag)
{
    Element * instance;

    switch (elementFlag) {
    case WALL:
        instance = new Wall;
        break;
    case WATER:
        instance = new Water;
        break;
    case TEST_BACKGROUND:
        instance = new TestBackground;
        break;
    case TESTATOR:
        instance = new Testator;
        break;
    case PLAYER_TEST:
        instance = new PlayerTest;
        break;
    case TEST_PROJECTILE:
        instance = new TestProjectile;
        break;
    default:
        instance = nullptr;
        break;
    }
    return instance;
}
