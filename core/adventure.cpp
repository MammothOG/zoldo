#include "adventure.h"
#include "level.h"

#include <QTextStream>

#include "elements/player/playertest.h"
#include "elements/player/link.h"


#include <QDebug>
Adventure::Adventure()
{
    levelList = new QList<Level*>();

    currentLevel = 0;

    win = false;

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
        win = true;
        return false;
    }


}

bool Adventure::load(QString name)
{
    QFile adventureFile("adventures/" + name + ".adv");
    if(!adventureFile.exists())
    {
        qWarning().noquote() << QString("Cannot open the file -> %1\nFile does not exist!").arg(adventureFile.fileName());
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

    if(reader.atEnd()) {
        qWarning("Adventure file is empty");
        return false;
    }
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
                qDebug() << "Load : " << level->getName();
            }
            else {
                return false;
            }
        }
    }
    return true;
}

void Adventure::generateTestAdventure()
{
    Level * level = new Level();
    level->generateTestLevel();
    //level->load("test1");

    levelList->append(level);
}

Level * Adventure::getCurrentLevel() const
{
    return levelList->at(levelList->length() - currentLevel - 1);
}

Player * Adventure::getPlayer() const
{
    return player;
}

bool Adventure::isWin() const
{
    return win;
}

void Adventure::setWin(bool value)
{
    win = value;
}
