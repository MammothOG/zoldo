#include "menubutton.h"

#include "config.h"


MenuButton::MenuButton()
{
    setHeight(1);
    setWidth(1);

    setIdleImage(":/ressources/images/buttons/menu-frame-0.png");
    setClickImage(":/ressources/images/buttons/menu-frame-1.png");

    setCenterAsReferencial();
}
