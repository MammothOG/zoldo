#include "elementfactory.h"

#include "core/element.h"

#include "elements/blocks/wall.h"
#include "elements/blocks/water.h"
#include "elements/background/testbackground.h"
#include "elements/enemies/testator.h"
#include "elements/enemies/bat.h"
#include "elements/enemies/ghost.h"
#include "elements/enemies/garbage.h"
#include "elements/enemies/despicableboss.h"
#include "elements/player/playertest.h"
#include "elements/projectile/testprojectile.h"
#include "elements/blocks/door.h"
#include "elements/projectile/stone.h"
#include "elements/projectile/fireball.h"
#include "elements/projectile/arrow.h"
#include "elements/projectile/dirtyball.h"
#include "elements/projectile/airgust.h"


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
    case DOOR:
        instance = new Door;
        break;
    case STONE:
        instance = new Stone;
        break;
    case FIREBALL:
        instance = new FireBall;
        break;
    case GARBAGE_ENEMY:
        instance = new Garbage;
        break;
    case BAT_ENEMY:
        instance = new Bat;
        break;
    case GHOST_ENEMY:
        instance = new Ghost;
        break;
    case DIRTY_BALL:
        instance = new DirtyBall;
        break;
    case ARROW:
        instance = new Arrow;
        break;
    case AIR_GUST:
        instance = new AirGust;
        break;
    case DESPICABLE_BOSS:
        instance = new DespicableBoss;
        break;
    default:
        qWarning("Unknown instance by factory.");
        instance = nullptr;
        break;
    }
    return instance;
}
