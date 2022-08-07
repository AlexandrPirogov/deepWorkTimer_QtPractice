#pragma once
#include "TwoHeaderGridModel.h"
#include "TwoHeaderGridView.h"

class TopDataLayerLayout : public QHBoxLayout
{
	TwoHeaderGridModel* gridModel = nullptr;
	TwoHeaderGridView* gridView = nullptr;
public:
	TopDataLayerLayout();

public slots:
	void startTimer()
	{
		gridModel->startTimer();

		gridModel->insertRow(gridModel->rowCount());
		QModelIndex firstCol = gridModel->index(gridModel->rowCount() - 1, 0);	
		qint64 secondsSinceEpoch = QDateTime::currentSecsSinceEpoch();

		QDateTime currentTime = QDateTime::currentDateTime();
		gridModel->setData(firstCol, currentTime.toString("hh:mm:ss"));

		QModelIndex secondCol = gridModel->index(gridModel->rowCount() - 1, 1);
		gridModel->setData(secondCol, "Timer has started!");
	}

	void stopTimer()
	{
		gridModel->stopTimer();
		long long elapsed = gridModel->getElapsed();
		QModelIndex secondCol = gridModel->index(gridModel->rowCount() - 1, 1);

		int totalNumberOfSeconds = elapsed/1000; // nr of seconds more than 1 day.
		int seconds = totalNumberOfSeconds % 60;
		int minutes = (totalNumberOfSeconds / 60) % 60;
		int hours = (totalNumberOfSeconds / 60 / 60);

		QString timeString = QString("%1:%2:%3")
			.arg(hours, 2, 10, QChar('0'))
			.arg(minutes, 2, 10, QChar('0'))
			.arg(seconds, 2, 10, QChar('0'));
		gridModel->setData(secondCol, timeString);
		updateTotal();
	}

private:
	void updateTotal()
	{
		QModelIndex total = gridModel->index(0, 1);
		int rowCount = gridModel->rowCount();
		int totalSeconds = 0;
		for (int i = 1; i < rowCount; i++)
		{
			QTime time = QTime::fromString(gridModel->index(i, 1).data().toString());
			totalSeconds += QTime(0, 0, 0).secsTo(time);
			qDebug() << totalSeconds;
		}

		int totalNumberOfSeconds = totalSeconds; // nr of seconds more than 1 day.
		int seconds = totalNumberOfSeconds % 60;
		int minutes = (totalNumberOfSeconds / 60) % 60;
		int hours = (totalNumberOfSeconds / 60 / 60);

		QString timeString = QString("%1:%2:%3")
			.arg(hours, 2, 10, QChar('0'))
			.arg(minutes, 2, 10, QChar('0'))
			.arg(seconds, 2, 10, QChar('0'));

		gridModel->setData(total, timeString);
	}
};

