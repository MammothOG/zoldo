#include "level.h"
#include "element.h"
#include "unit.h"
#include "config.h"

#include <QDir>
#include <QTextStream>
#include <math.h>

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

    levelDone = false;

    spawnX = 0;
    spawnY = 0;
}

Level::~Level()
{
    delete unitList;
    delete elementList;
    delete background;
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
    unitList->append(testEnemy);
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
                    .arg((float)spawnX/width)
                    .arg((float)spawnY/height)
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
    QString line = QString("%1 %2 %3 %4\n")
            .arg(element->types().last())
            .arg(element->x()/width)
            .arg(element->y()/height)
            .arg(element->getImageName());

    levelFile->write(line.toLocal8Bit());
}

bool Level::load(QString levelName)
{
    name = levelName;
    QFile levelFile("levels/" + levelName + ".lvl");
    if(!levelFile.exists())
    {
        qWarning().noquote() << QString("Cannot be open : \n >%1 \n File does not exist!").arg(levelName);
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

    spawnX = round(spawnCoordinates.at(0).toFloat() * width);
    spawnY = round(spawnCoordinates.at(1).toFloat() * height);

    Element * newElement;
    while(!reader.atEnd())
    {
        line = reader.readLine();

        QStringList elementData = line.split(" ");
        int elementName = elementData.at(0).toInt();
        int newX = round(elementData.at(1).toFloat() * width);
        int newY = round(elementData.at(2).toFloat() * height);
        QString imageName = elementData.at(3);


        newElement = ElementFactory::create(elementName);

        newElement->setStyle(imageName);
        newElement->setPos(newX, newY);

        appendLevelElement(newElement);
    }

    levelFile.close();

    return true;
}

void Level::appendLevelElement(Element * element)
{
    if (element->isType(BLOCK)) {
        elementList->append(element);
    }
    if (element->isType(BACKGROUND)) {
        background = dynamic_cast<Background*>(element);
    }
    if (element->isType(ENEMY)) {
        unitList->append(dynamic_cast<Unit*>(element));
    }
    if (element->isType(PLAYER)) {
        spawnX = element->x();
        spawnY = element->y();
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

bool Level::isLevelDone() const
{
    return levelDone;
}

void Level::setLevelDone(bool value)
{
    levelDone = value;
}
