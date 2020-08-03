#include "playbutton.h"

PlayButton::PlayButton()
{
    setHeight(1);
    setWidth(3);

    setIdleImage(":/ressources/images/buttons/play-frame-0.png");
    setClickImage(":/ressources/images/buttons/play-frame-1.png");

    setCenterAsReferencial();
}
