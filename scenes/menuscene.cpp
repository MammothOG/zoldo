#include "menuscene.h"

#include "config.h"
#include "elements/buttons/playbutton.h"
#include "elements/buttons/settingbutton.h"
#include "elements/buttons/quitbutton.h"
#include "elements/visual/menutitle.h"


MenuScene::MenuScene()
{
    setSceneRect(0, 0, WINSIZE.rwidth(), WINSIZE.rheight());
    setBackgroundBrush(Qt::white);

    playButton = new PlayButton();
    playButton->setPos(WINSIZE.rwidth()/2, WINSIZE.rheight()/2);
    addItem(playButton);

    quitButton = new QuitButton();
    quitButton->setPos(WINSIZE.rwidth() - 45, WINSIZE.rheight() - 45);
    addItem(quitButton);

    settingButton = new SettingButton();
    settingButton->setPos(WINSIZE.rwidth() - 75, 20);
    addItem(settingButton);

    title = new MenuTitle();
    title->setPos(WINSIZE.rwidth()/2, 200);
    addItem(title);

}

PlayButton *MenuScene::getPlayButton() const
{
    return playButton;
}

SettingButton *MenuScene::getSettingButton() const
{
    return settingButton;
}
