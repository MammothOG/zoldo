#include "link.h"

#include "config.h"

Link::Link()
{
    setType(LINK);

    setHeight(1);
    setWidth(0.69);

    setSprite(":/ressources/images/players/link_up.png");

    setMovementSpeed(8);

    setShootRate(700);
    setProjectile(ARROW);

    setHealth(60);

    insertDirectionSprite("D", ":/ressources/images/players/link_down.png");
    insertDirectionSprite("R", ":/ressources/images/players/link_right.png");
    insertDirectionSprite("U", ":/ressources/images/players/link_up.png");
    insertDirectionSprite("L", ":/ressources/images/players/link_left.png");

    //setDefaultRotation(180);
}
