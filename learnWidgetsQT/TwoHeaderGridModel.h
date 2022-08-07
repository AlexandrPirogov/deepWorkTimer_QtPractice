#pragma once
class TwoHeaderGridModel : public QStandardItemModel
{
	QElapsedTimer* elapsedTimer = nullptr;
	long long elapsed;
public:
	TwoHeaderGridModel(int rows, int cols, QObject* pObj = nullptr);
	
	inline long long getElapsed() const
	{
		return elapsed;
	}

signals:

public slots:
	void startTimer()
	{
		elapsedTimer->start();
	};
	void stopTimer()
	{
		elapsed = elapsedTimer->elapsed();
		elapsedTimer->restart();
	};
};

