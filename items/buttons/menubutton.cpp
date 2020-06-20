#include "menubutton.h"

#include "config.h"


MenuButton::MenuButton()
{
    setHeight(BLOCK_SIZE);
    setWidth(BLOCK_SIZE);

    setIdleImage(":/ressources/images/buttons/menu-frame-0.png");
    setClickImage(":/ressources/images/buttons/menu-frame-1.png");

    setCenterAsReferencial();

}
