#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>
#include <QComboBox>
#include <QCheckBox>

class SetupDialog : public QDialog
{
private:
    QComboBox * resBox;

    QMap<QString, QSize> resolutions;

    QCheckBox * fullScreen;
public:
    SetupDialog();

    void addResolution(int width, int height);

    void setupConst();

    QCheckBox *isFullScreen() const;
};

#endif // SETUPDIALOG_H
