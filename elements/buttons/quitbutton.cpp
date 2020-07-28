#include "quitbutton.h"

#include <QApplication>

#include "config.h"

QuitButton::QuitButton()
{
    setHeight(1);
    setWidth(1);

    setIdleImage(":/ressources/images/buttons/quit-frame-0.png");
    setClickImage(":/ressources/images/buttons/quit-frame-1.png");

    setCenterAsReferencial();

}

void QuitButton::onClick()
{
    QApplication::quit();
}
