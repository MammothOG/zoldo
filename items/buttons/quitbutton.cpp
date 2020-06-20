#include "quitbutton.h"

#include <QApplication>

#include "config.h"

QuitButton::QuitButton()
{
    setHeight(BLOCK_SIZE);
    setWidth(BLOCK_SIZE);

    setIdleImage(":/ressources/images/buttons/quit-frame-0.png");
    setClickImage(":/ressources/images/buttons/quit-frame-1.png");

    setCenterAsReferencial();

}

void QuitButton::onClick()
{
    QApplication::quit();
}
