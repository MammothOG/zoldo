#include "endgamevisual.h"
#include "core/element.h"
#include "config.h"

EndGameVisual::EndGameVisual(bool win)
{
    setHandlesChildEvents(false);

    QPixmap finalMessage;
    if(win) {
        finalMessage = QPixmap(":/ressources/images/visuals/you_win.png");
        finalMessage = finalMessage.scaled(BLOCKSIZE*6.29, BLOCKSIZE*2.38);

        QPixmap zelda = QPixmap(":/ressources/images/visuals/zelda.png");
        zelda = zelda.scaled(BLOCKSIZE*4.92, BLOCKSIZE*6);
        QGraphicsPixmapItem * zeldaPxm = new QGraphicsPixmapItem(zelda);
        zeldaPxm->setOffset(-zelda.width()/2, -zelda.height()/2);
        zeldaPxm->setPos(0, BLOCKSIZE*3);
        addToGroup(zeldaPxm);
    }
    else {
        finalMessage = QPixmap(":/ressources/images/visuals/you_lose.png");
        finalMessage = finalMessage.scaled(BLOCKSIZE*7.78, BLOCKSIZE*2.34);
    }
    QGraphicsPixmapItem * finalMessagePxm = new QGraphicsPixmapItem(finalMessage);
    finalMessagePxm->setOffset(-finalMessage.width()/2, -finalMessage.height()/2);
    finalMessagePxm->setPos(0, -BLOCKSIZE*3);
    addToGroup(finalMessagePxm);
}
