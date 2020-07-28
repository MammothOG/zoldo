#include "playbutton.h"

PlayButton::PlayButton()
{
    setHeight(0.5);
    setWidth(2);

    setIdleImage(":/ressources/images/buttons/play-frame-0.png");
    setClickImage(":/ressources/images/buttons/play-frame-1.png");

    setCenterAsReferencial();
}
