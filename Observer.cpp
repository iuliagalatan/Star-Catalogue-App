#include "observer.h"

Observable::~Observable()
{

}

void Observable::addObserver(Observer* obs)
{
	observers.push_back(obs);
}

void Observable::removeObserver(Observer* obs)
{
	auto it = std::find(observers.begin(), observers.end(), obs);
	if (it != observers.end())
		observers.erase(it);
}

void Observable::notify()
{
	for (auto observer : observers)
	{
		observer->update();
	}
}