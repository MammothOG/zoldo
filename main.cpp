#include "scenemanager.h"

#include <QApplication>
#include <QMainWindow>

#include "tools/setupdialog.h"


void lauchGame(bool fullScreenEnabled) {

    QMainWindow * mainWindow = new QMainWindow();
    SceneManager * game = new SceneManager(mainWindow);

    if (fullScreenEnabled)
        mainWindow->showFullScreen();

    mainWindow->setCentralWidget(game);
    mainWindow->show();
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    QPixmap icon = QPixmap(":/ressources/images/visuals/icon.png");
    a.setWindowIcon(QIcon(icon));

    SetupDialog resDialog;
    switch (resDialog.exec()) {
    case QDialog::Accepted:
        lauchGame(resDialog.isFullScreen()->isChecked());
        break;
    case QDialog::Rejected:
        QApplication::quit();
        break;
    }

    return a.exec();
}
