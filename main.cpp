#include "gameengine.h"

#include <QApplication>
#include <QMainWindow>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QMainWindow * mainWindow = new QMainWindow();

    GameEngine * game = new GameEngine(mainWindow);
    mainWindow->setCentralWidget(game);
    mainWindow->show();

    return a.exec();
}
