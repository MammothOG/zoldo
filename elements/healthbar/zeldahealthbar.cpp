#include "zeldahealthbar.h"


ZeldaHealthBar::ZeldaHealthBar(int heartNumber)
{
    setFollowingUnit(false);

    height = 70;
    width = 3 * height;

    heartList = new QList<QGraphicsPixmapItem*>();

    heartFullPixmap = QPixmap(":/ressources/images/players/heart_full.png");
    heartHalfPixmap = QPixmap(":/ressources/images/players/heart_half.png");
    heartEmptyPixmap = QPixmap(":/ressources/images/players/heart_empty.png");

    heartFullPixmap.scaled(height, height);
    heartHalfPixmap.scaled(height, height);
    heartEmptyPixmap.scaled(height, height);

    for(int i=0; i<heartNumber; i++){
        QGraphicsPixmapItem * heart = new QGraphicsPixmapItem(heartFullPixmap);

        heart->setPos(i*height, 0);
        addToGroup(heart);

        heartList->append(heart);
    }

}

#include <QDebug>
void ZeldaHealthBar::onNewHealth(float health)
{
    float limitHealth = totalHealth/heartList->length();
    float cursor = limitHealth;
    for(QGraphicsPixmapItem * heart : *heartList)
    {
        removeFromGroup(heart);
        if (health < cursor) {
            if (health > cursor - limitHealth/2) {
                qDebug() << "half";
                heart->setPixmap(heartHalfPixmap);
            }
            else {
                qDebug() << "empty";
                heart->setPixmap(heartEmptyPixmap);
            }
        }
        else {
            qDebug() << "full";
            heart->setPixmap(heartFullPixmap);
        }
        addToGroup(heart);
        cursor += limitHealth;
    }

    qDebug() << "hit player";
}
