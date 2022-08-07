#include "stdafx.h"
#include "TopDataLayerLayout.h"

TopDataLayerLayout::TopDataLayerLayout()
{
	gridModel = new TwoHeaderGridModel(0, 2);
	gridView = new TwoHeaderGridView();
	gridView->setModel(gridModel);
	gridView->setAutoFillBackground(true);
	addWidget(gridView);
}
