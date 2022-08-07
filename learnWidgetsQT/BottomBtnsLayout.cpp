#include "stdafx.h"
#include "BottomBtnsLayout.h"

BottomBtnsLayout::BottomBtnsLayout()
{
	start = new QPushButton();
	start->setText("Start");
	stop = new QPushButton();
	stop->setText("Stop");
	addWidget(start);
	addWidget(stop);
}
