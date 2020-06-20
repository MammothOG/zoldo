#include "restartbutton.h"

#include "config.h"

RestartButton::RestartButton()
{
    setHeight(BLOCK_SIZE);
    setWidth(BLOCK_SIZE);

    setIdleImage(":/ressources/images/buttons/restart-frame-0.png");
    setClickImage(":/ressources/images/buttons/restart-frame-1.png");

    setCenterAsReferencial();
}
