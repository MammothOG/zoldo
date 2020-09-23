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


    QPixmap icon = QPixmap(":/ressources/images/visuals/icon.png");
    icon = icon.scaled(20,20);
    a.setWindowIcon(QIcon(icon));

    SetupDialog resDialog;
    switch (resDialog.exec()) {
    case QDialog::Accepted:
        lauchGame();
        break;
    case QDialog::Rejected:
        QApplication::quit();
        break;
    }

    return a.exec();
}
