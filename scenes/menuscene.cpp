#include "menuscene.h"

#include "config.h"
#include "elements/buttons/playbutton.h"
#include "elements/buttons/settingbutton.h"
#include "elements/buttons/quitbutton.h"
#include "elements/visual/menutitle.h"


MenuScene::MenuScene()
{
    setSceneRect(0, 0, WIN_WIDTH, WIN_HEIGHT);
    setBackgroundBrush(Qt::white);

    playButton = new PlayButton();
    playButton->setPos(WIN_WIDTH/2, WIN_HEIGHT/2);
    addItem(playButton);

    quitButton = new QuitButton();
    quitButton->setPos(WIN_WIDTH - 45, WIN_HEIGHT - 45);
    addItem(quitButton);

    settingButton = new SettingButton();
    settingButton->setPos(WIN_WIDTH - 75, 20);
    addItem(settingButton);

    title = new MenuTitle();
    title->setPos(WIN_WIDTH/2, 200);
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
