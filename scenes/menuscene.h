#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QGraphicsScene>


class PlayButton;

class QuitButton;

class SettingButton;

class MenuTitle;

class MenuScene : public QGraphicsScene
{
    Q_OBJECT
private:
    MenuTitle * title;

    PlayButton * playButton;

    QuitButton * quitButton;

    SettingButton * settingButton;

public:
    MenuScene();

    PlayButton *getPlayButton() const;

    void setPlayButton(PlayButton *value);
};

#endif // MENUSCENE_H
