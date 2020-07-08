#include "menubutton.h"

#include "config.h"


MenuButton::MenuButton()
{
    setHeight(BLOCKSIZE);
    setWidth(BLOCKSIZE);

    setIdleImage(":/ressources/images/buttons/menu-frame-0.png");
    setClickImage(":/ressources/images/buttons/menu-frame-1.png");

    setCenterAsReferencial();
}
