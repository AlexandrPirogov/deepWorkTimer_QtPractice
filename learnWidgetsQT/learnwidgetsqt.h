#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_learnwidgetsqt.h"

class learnWidgetsQT : public QMainWindow
{
    Q_OBJECT

public:
    learnWidgetsQT(QWidget *parent = nullptr);
    ~learnWidgetsQT();

private:
    Ui::learnWidgetsQTClass ui;
};
