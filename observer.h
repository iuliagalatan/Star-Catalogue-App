#pragma once
#include <vector>
class Observer
{
public:
	virtual void update() = 0;
	virtual void show() = 0;
	virtual ~Observer() {}
};

class Observable
{
private:

	std::vector<Observer*> observers;
public:
	virtual ~Observable();

	void addObserver(Observer* obs);

	void removeObserver(Observer* obs);

	void notify();
};


