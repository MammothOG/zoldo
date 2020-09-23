#include "bat.h"

Bat::Bat()
{
    setType(BAT_ENEMY);

    setMoveRate(10);

    setShootRate(2500);

    setProjectile(DIRTY_BALL);

    setMovementSpeed(0);
    setHealth(100);

    // setup graphics
    setHeight(0.67);
    setWidth(0.5);
    setSprite(":/ressources/images/enemies/bat_down.png");

    insertDirectionSprite("D", ":/ressources/images/enemies/bat_down.png");
    insertDirectionSprite("R", ":/ressources/images/enemies/bat_right.png");
    insertDirectionSprite("U", ":/ressources/images/enemies/bat_up.png");
    insertDirectionSprite("L", ":/ressources/images/enemies/bat_left.png");
}

void Bat::move()
{

}
