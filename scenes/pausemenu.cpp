#include "pausemenu.h"

#include "config.h"
#include "elements/buttons/menubutton.h"
#include "elements/buttons/quitbutton.h"
#include "elements/buttons/resumebutton.h"
#include "elements/buttons/restartbutton.h"


RestartButton *PauseMenu::getRestartButton() const
{
    return restartButton;
}

void PauseMenu::setRestartButton(RestartButton *value)
{
    restartButton = value;
}

PauseMenu::PauseMenu()
{
    setHandlesChildEvents(false);

    menuButton = new MenuButton();
    quitButton = new QuitButton();
    resumeButton = new ResumeButton();
    restartButton = new RestartButton();

    resumeButton->setPos(-50, 0);
    restartButton->setPos(0, 0);
    menuButton->setPos(50, 0);
    quitButton->setPos(100, 0);

    addToGroup(menuButton);
    addToGroup(resumeButton);
    addToGroup(quitButton);
    addToGroup(restartButton);


}

QuitButton *PauseMenu::getQuitButton() const
{
    return quitButton;
}

void PauseMenu::setQuitButton(QuitButton *value)
{
    quitButton = value;
}

MenuButton *PauseMenu::getMenuButton() const
{
    return menuButton;
}

void PauseMenu::setMenuButton(MenuButton *value)
{
    menuButton = value;
}

ResumeButton *PauseMenu::getResumeButton() const
{
    return resumeButton;
}

void PauseMenu::setResumeButton(ResumeButton *value)
{
    resumeButton = value;
}
