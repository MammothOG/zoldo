#include "scenemanager.h"

#include <QApplication>
#include <QMainWindow>

#include "tools/setupdialog.h"


void lauchGame() {

    QMainWindow * mainWindow = new QMainWindow();
    SceneManager * game = new SceneManager(mainWindow);

    mainWindow->setCentralWidget(game);
    mainWindow->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    SetupDialog resDialog;
    switch (resDialog.exec()) {
    case QDialog::Accepted:
        lauchGame();
        break;
    case QDialog::Rejected:
        break;
    }

    return a.exec();
}
