#include "pausebutton.h"

#include "config.h"


PauseButton::PauseButton()
{
    setHoldPressed(true);

    setHeight(BLOCK_SIZE);
    setWidth(BLOCK_SIZE);

    setIdleImage(":/ressources/images/buttons/pause-frame-0.png");
    setClickImage(":/ressources/images/buttons/pause-frame-1.png");
}
