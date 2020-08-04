#include "endgamevisual.h"

#include <QDebug>
EndGameVisual::EndGameVisual(bool win)
{
    if(win) {
        setWidth(6.29);
        setHeight(2.38);
        setSprite(":/ressources/images/visuals/you_win.png");
    }
    else {
        setWidth(7.78);
        setHeight(2.34);
        setSprite(":/ressources/images/visuals/you_lose.png");
    }

    setCenterAsReferencial();
}
