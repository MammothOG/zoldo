#include "restartbutton.h"

#include "config.h"

RestartButton::RestartButton()
{
    setHeight(1);
    setWidth(1);

    setIdleImage(":/ressources/images/buttons/restart-frame-0.png");
    setClickImage(":/ressources/images/buttons/restart-frame-1.png");

    setCenterAsReferencial();
}
