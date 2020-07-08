#include "setupdialog.h"

#include <QPushButton>
#include <QHBoxLayout>
#include <QMap>
#include <QComboBox>

#include "config.h"


QSize WINSIZE;
int BLOCKSIZE;
SetupDialog::SetupDialog()
{
    addResolution(1920, 1080);
    addResolution(1600, 900);

    setLayout(new QHBoxLayout());

    resBox = new QComboBox;
    resBox->addItems(resolutions.keys());
    layout()->addWidget(resBox);

    QPushButton* ok = new QPushButton("ok");
    layout()->addWidget(ok);
    connect(ok, &QPushButton::clicked, this, [this]()
    {
        setupConst();
        accept();
    });

    QPushButton* cancel = new QPushButton("cancel");
    layout()->addWidget(cancel);
    connect(cancel, &QPushButton::clicked, this, [this]()
    {
        reject();
    });
}

void SetupDialog::addResolution(int width, int height)
{
    QString label = QString("%1x%2").arg(height).arg(width);

    QSize size(width, height);

    resolutions.insert(label, size);
}

#include <QDebug>
void SetupDialog::setupConst()
{
        WINSIZE = resolutions[resBox->currentText()];
        BLOCKSIZE = (WINSIZE.height() - TOPSPACE - BOTSPACE) / VERTICAL_BLOCK;
}
