#include "playbutton.h"

PlayButton::PlayButton()
{
    setHeight(50);
    setWidth(150);

    setIdleImage(":/ressources/images/buttons/play-frame-0.png");
    setClickImage(":/ressources/images/buttons/play-frame-1.png");

    setCenterAsReferencial();
}
