#ifndef PAUSEMENU_H
#define PAUSEMENU_H

#include <QGraphicsItemGroup>


class MenuButton;

class QuitButton;

class ResumeButton;

class RestartButton;

class PauseMenu : public QGraphicsItemGroup
{
private:
    MenuButton * menuButton;

    QuitButton * quitButton;

    ResumeButton * resumeButton;

    RestartButton * restartButton;

public:
    PauseMenu();

    MenuButton *getMenuButton() const;

    void setMenuButton(MenuButton *value);

    QuitButton *getQuitButton() const;

    void setQuitButton(QuitButton *value);

    ResumeButton *getResumeButton() const;

    void setResumeButton(ResumeButton *value);

    RestartButton *getRestartButton() const;

    void setRestartButton(RestartButton *value);
};

#endif // PAUSEMENU_H
