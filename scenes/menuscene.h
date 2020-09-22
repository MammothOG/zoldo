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

    QGraphicsView * sceneManager;

    QGraphicsPixmapItem * menuBackground;

public:
    MenuScene(QGraphicsView * sceneManager);

    ~MenuScene();

    void keyPressEvent(QKeyEvent *keyEvent) override;
};

#endif // MENUSCENE_H
