#include "zeldahealthbar.h"

#include "config.h"


ZeldaHealthBar::ZeldaHealthBar(int heartNumber)
{
    setFollowingUnit(false);

    height =  0.90 * BLOCKSIZE;
    spaceSize = 0.15 * BLOCKSIZE;
    width = 3 * (height + spaceSize);

    heartList = new QList<QGraphicsPixmapItem*>();

    heartFullPixmap = QPixmap(":/ressources/images/players/heart_full.png");
    heartHalfPixmap = QPixmap(":/ressources/images/players/heart_half.png");
    heartEmptyPixmap = QPixmap(":/ressources/images/players/heart_empty.png");

    heartFullPixmap = heartFullPixmap.scaled(height, height);
    heartHalfPixmap = heartHalfPixmap.scaled(height, height);
    heartEmptyPixmap = heartEmptyPixmap.scaled(height, height);

    for(int i=0; i<heartNumber; i++){
        QGraphicsPixmapItem * heart = new QGraphicsPixmapItem(heartFullPixmap);

        heart->setPos(i*(height + spaceSize), 0);
        addToGroup(heart);

        heartList->append(heart);
    }

}

void ZeldaHealthBar::onNewHealth(float health)
{
    float limitHealth = totalHealth/heartList->length();
    float cursor = limitHealth;

    for(QGraphicsPixmapItem * heart : *heartList)
    {
        removeFromGroup(heart);
        if (health < cursor) {
            if (health > cursor - limitHealth/2) {
                heart->setPixmap(heartHalfPixmap);
            }
            else {
                heart->setPixmap(heartEmptyPixmap);
            }
        }
        else {
            heart->setPixmap(heartFullPixmap);
        }
        addToGroup(heart);
        cursor += limitHealth;
    }
}
