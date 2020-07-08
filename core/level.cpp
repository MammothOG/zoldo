#include "level.h"
#include "element.h"
#include "unit.h"
#include "config.h"

#include <QDir>
#include <QTextStream>

#include "core/background.h"
#include "core/unit.h"

#include "elements/background/testbackground.h"
#include "elements/enemies/testator.h"
#include "elements/blocks/wall.h"
#include "tools/elementfactory.h"
#include "elements/blocks/door.h"


Level::Level()
{
    // listing the level item
    elementList = new QList<Element*>();
    unitList = new QList<Unit*>();

    // set info level
    name = "noNamedLevel";

    background = new Background();

    // set level dimension
    height = BLOCKSIZE * VERTICAL_BLOCK;
    width = BLOCKSIZE * HORIZONTAL_BLOCK;

    spawnX = 0;
    spawnY = 0;
}

void Level::generateTestLevel()
{
    name = "Test level";

    background = new TestBackground();

    spawnX = 300;
    spawnY = 300;


    Door * door = new Door();
    door->setPos(350,350);
    elementList->append(door);

    // set block wall around the level
    for (int w = 0; w < HORIZONTAL_BLOCK; w++){
        for (int h = 0; h < VERTICAL_BLOCK; h++){
            int posx = w * BLOCKSIZE;
            int posy = h * BLOCKSIZE;

            if(posx == 0 || posy == 0 ||
                    posx == (HORIZONTAL_BLOCK-1)*BLOCKSIZE ||
                    posy == (VERTICAL_BLOCK-1)*BLOCKSIZE)
            {
                Wall * wall = new Wall();

                wall->setPos(posx, posy);

                elementList->append(wall);
            }
        }
    }

    Testator * testEnemy = new Testator();
    testEnemy->setPos(200, 200);
    testEnemy->setCenterAsReferencial();
    unitList->append(testEnemy);
}

void Level::clearLevel()
{
    for(Element * elem : *elementList){
        delete elem;
    }
    elementList->clear();

    for(Unit * unit: *unitList){
        delete unit;
    }
    unitList->clear();
}

bool Level::save()
{
    QDir levelDir("levels");

    if(!levelDir.exists())
        QDir().mkdir(QString("levels"));

    QFile levelFile("levels/" + name + ".lvl");
    if(levelFile.exists())
    {
        qWarning("Unable to create : file name already exist");
        return false;
    }

    // Open file and create it if not exists
    if (!levelFile.open(QIODevice::WriteOnly | QIODevice::Append)) {
        qWarning("Couldn't open file.");
        return false;
    }

    // saving all scene element
    levelFile.write(QString("%1 %2\n")
                    .arg(spawnX/WINSIZE.rwidth())
                    .arg(spawnY/WINSIZE.rheight())
                    .toLocal8Bit());

    saveElement(&levelFile, background);

    for(Element * elem : *elementList)
        saveElement(&levelFile, elem);

    for(Unit * unit : *unitList)
        saveElement(&levelFile, unit);

    levelFile.close();
    return true;
}

void Level::saveElement(QFile * levelFile, Element * element)
{
    QString line = QString("%1 %2 %3\n")
            .arg(element->getElementName())
            .arg(element->x()/WINSIZE.rwidth())
            .arg(element->y()/WINSIZE.rheight());
    levelFile->write(line.toLocal8Bit());
}

#include <QDebug>
bool Level::load(QString levelName)
{
    QFile levelFile("levels/" + levelName + ".lvl");
    if(!levelFile.exists())
    {
        qWarning("Cannot be open : File does not exist!");
        return false;
    }

    // Open file and create it if not exists
    if (!levelFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open file.");
        return false;
    }

    QTextStream reader(&levelFile);

    // reading the spawn position
    QString line = reader.readLine();
    QStringList spawnCoordinates = line.split(" ");

    spawnX = spawnCoordinates.at(0).toInt() * WINSIZE.rwidth();
    spawnY = spawnCoordinates.at(1).toInt() * WINSIZE.rheight();

    Element * newElement;
    while(!reader.atEnd())
    {
        line = reader.readLine();

        QStringList elementData = line.split(" ");
        int elementName = elementData.at(0).toInt();
        int newX = elementData.at(1).toInt() * WINSIZE.rwidth();
        int newY = elementData.at(2).toInt() * WINSIZE.rheight();

        newElement = ElementFactory::create(elementName);
        newElement->setPos(newX, newY);

        appendLevelElement(newElement);
    }

    levelFile.close();

    return true;
}

void Level::appendLevelElement(Element * element)
{
    switch (element->getType()) {
    case BLOCK:
        elementList->append(element);
        break;

    case BACKGROUND:
        background = dynamic_cast<Background*>(element);
        break;

    case ENEMY:
        unitList->append(dynamic_cast<Unit*>(element));
        break;

    case PLAYER:
        spawnX = element->x();
        spawnY = element->y();
        break;
    }
}

QList<Element*> * Level::getElementList() const
{
    return elementList;
}

QList<Unit*> * Level::getUnitList() const
{
    return unitList;
}

Background * Level::getBackground() const
{
    return background;
}

int Level::getSpawnX() const
{
    return spawnX;
}

int Level::getSpawnY() const
{
    return spawnY;
}

void Level::setElementList(QList<Element *> *value)
{
    elementList = value;
}

void Level::setUnitList(QList<Unit *> *value)
{
    unitList = value;
}

void Level::setBackground(Background *value)
{
    background = value;
}

void Level::setSpawn(int X, int Y)
{
    this->spawnX = X;
    this->spawnY = Y;
}

QString Level::getName() const
{
    return name;
}

void Level::setName(const QString &value)
{
    name = value;
}
