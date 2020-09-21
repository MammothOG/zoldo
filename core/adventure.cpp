#include "adventure.h"
#include "level.h"

#include <QTextStream>

#include "elements/player/playertest.h"
#include "elements/player/link.h"


#include <QDebug>
Adventure::Adventure()
{
    levelList = new QList<QString>();

    currentLevel = new Level;

    levelIndex = 0;

    win = false;

    player = new Link();
    player->setCenterAsReferencial();
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();
}

bool Adventure::nextLevel()
{
    levelList->removeLast();
    if (!levelList->isEmpty()) {
        currentLevel = new Level();
        currentLevel->load(levelList->last());
        qDebug() << "Load : " << currentLevel->getName();
        qDebug() << "Following Level :" << levelList;
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

        //check if line is empty
        if (!line.isEmpty())
        {
            levelList->prepend(line);
        }
    }
    currentLevel->load(levelList->last());
    return true;
}

void Adventure::generateTestAdventure()
{
    //not checked with the new way

    currentLevel->generateTestLevel();
    currentLevel->load("test1");
}

Level * Adventure::getCurrentLevel() const
{
    return currentLevel;
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
