#include "wall.h"


Wall::Wall()
{
    setCollider(true);

    setType(WALL);

    //setSprite(":/ressources/images/walls/wall_blue_1.png");
    setStyleDir("walls");

    setStyle("wall_blue_1");

}
