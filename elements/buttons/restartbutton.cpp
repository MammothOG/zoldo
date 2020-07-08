#include "restartbutton.h"

#include "config.h"

RestartButton::RestartButton()
{
    setHeight(BLOCKSIZE);
    setWidth(BLOCKSIZE);

    setIdleImage(":/ressources/images/buttons/restart-frame-0.png");
    setClickImage(":/ressources/images/buttons/restart-frame-1.png");

    setCenterAsReferencial();
}
