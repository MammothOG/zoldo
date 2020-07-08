#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>
#include <QComboBox>


class SetupDialog : public QDialog
{
private:
    QComboBox * resBox;

    QMap<QString, QSize> resolutions;
public:
    SetupDialog();

    void addResolution(int width, int height);

    void setupConst();
};

#endif // SETUPDIALOG_H
