#pragma once
#include "BottomBtnsLayout.h"
#include "TopDataLayerLayout.h"

class TopLayerLayout : public QVBoxLayout
{
	BottomBtnsLayout* bottomBtnsLayout = nullptr;
	TopDataLayerLayout* topDataLayerLayout = nullptr;
public:
	TopLayerLayout();

signals:

public slots:

};

