#pragma once
class BottomBtnsLayout : public QHBoxLayout
{
	Q_OBJECT
	QPushButton* start = nullptr;
	QPushButton* stop = nullptr;
public:
	BottomBtnsLayout();

	inline QPushButton* getStartBtn()
	{
		return start;
	}

	inline QPushButton* getStopBtn()
	{
		return stop;
	}
};

