#include "pausebutton.h"

#include "config.h"


PauseButton::PauseButton()
{
    setHoldPressed(true);

    setHeight(1);
    setWidth(1);

    setIdleImage(":/ressources/images/buttons/pause-frame-0.png");
    setClickImage(":/ressources/images/buttons/pause-frame-1.png");
}
