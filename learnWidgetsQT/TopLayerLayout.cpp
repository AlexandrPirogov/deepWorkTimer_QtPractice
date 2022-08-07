#include "stdafx.h"
#include "TopLayerLayout.h"

TopLayerLayout::TopLayerLayout()
{
	bottomBtnsLayout = new BottomBtnsLayout();
	topDataLayerLayout = new TopDataLayerLayout();

	QPushButton* start = bottomBtnsLayout->getStartBtn();
	QPushButton* stop = bottomBtnsLayout->getStopBtn();

	connect(start, &QPushButton::clicked, [start, stop]() {
		start->setEnabled(false);
		stop->setEnabled(true);
		});

	connect(stop, &QPushButton::clicked, [start, stop]() {
		start->setEnabled(true);
		stop->setEnabled(false);
		});

	connect(start, &QPushButton::clicked, topDataLayerLayout, &TopDataLayerLayout::startTimer);
	connect(stop, &QPushButton::clicked, topDataLayerLayout, &TopDataLayerLayout::stopTimer);

	


	addLayout(topDataLayerLayout);
	addLayout(bottomBtnsLayout);
}
