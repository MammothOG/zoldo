#ifndef ENDGAMEVISUAL_H
#define ENDGAMEVISUAL_H

#include <QGraphicsItemGroup>

class QuitButton;

class EndGameVisual : public QGraphicsItemGroup
{
private:
    QuitButton * quitButton;

public:
    EndGameVisual(bool win);
};

#endif // ENDGAMEVISUAL_H
