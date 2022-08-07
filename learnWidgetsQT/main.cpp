#include "stdafx.h"
#include "learnwidgetsqt.h"
#include <QtWidgets/QApplication>
#include "TopLayerLayout.h"
#include "QtWebSockets/qwebsocket.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget* t = new QWidget();
    TopLayerLayout* layout = new TopLayerLayout();
    t->setLayout(layout);
    t->setWindowFlags(Qt::WindowStaysOnTopHint | Qt::MSWindowsFixedSizeDialogHint);
    t->show();
    
    return a.exec();
}
