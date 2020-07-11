#include "adventure.h"
#include "level.h"

#include <QTextStream>

#include "elements/player/playertest.h"
#include "elements/player/link.h"


Adventure::Adventure()
{
    levelList = new QList<Level*>();
    currentLevel = 1;

    player = new Link();
    player->setCenterAsReferencial();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
}

bool Adventure::nextLevel()
{
    if (currentLevel < levelList->length() - 1) {
        currentLevel++;
        return true;
    }
    else {
        return false;
    }


}

#include <QDebug>
bool Adventure::load(QString name)
{
    QFile adventureFile("adventures/" + name + ".adv");
    if(!adventureFile.exists())
    {
        qWarning("Cannot be open : File does not exist!");
        return false;
    }

    // Open file and create it if not exists
    if (!adventureFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        return false;
    }

    QTextStream reader(&adventureFile);

    // reading adventure levels
    QString line;
    while(!reader.atEnd())
    {
        line = reader.readLine();
        line = line.trimmed();

        Level * level;
        //check if line is empty
        if (!line.isEmpty())
        {
            level = new Level;
            if (level->load(line)) {
                levelList->prepend(level);
            }
            qDebug() << "Load : " << level->getName();
        }
    }
    return true;
}

void Adventure::generateTestAdventure()
{
    Level * level = new Level();
    //level->generateTestLevel();
    level->load("test1");

    levelList->append(level);
}

Level * Adventure::getCurrentLevel() const
{
    return levelList->at(currentLevel);
}

Player * Adventure::getPlayer() const
{
    return player;
}

