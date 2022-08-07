#include "stdafx.h"
#include "TwoHeaderGridModel.h"

TwoHeaderGridModel::TwoHeaderGridModel(int rows, int cols, QObject* pObj)
	: QStandardItemModel(rows, cols, pObj)
{
	elapsedTimer = new QElapsedTimer;
	elapsed = -1;

	setHeaderData(0, Qt::Horizontal, "Start date");
	setHeaderData(1, Qt::Horizontal, "Duration");

	insertRow(rowCount());
	QModelIndex firstCol = index(0, 0);
	setData(firstCol, "Total: ");

}
