#include "Service.h"

/*
	Specifications:
	AddObject function adds an object of type star to the repository's vector
	Input:Object o
	Output: - (Calls AddObject from repo) 
*/
void Service::AddObject(TElem& o)
{
	
	repo.AddStar(o);
}

void Service::AddUser(User& o)
{
	repo.AddUser(o);
}

void Service::RemoveObject(TElem& o)
{
	repo.RemoveObject(o);
}

void Service::UpdateObject(TElem& o)
{
	repo.UpdateObject(o);
}

void Service::addObserver(Observer* o)
{
	repo.addObserver(o);
}

std::vector<TElem>& Service::GetObjects()
{
	// TODO: insert return statement here
	return repo.GetObjects();
}

std::vector<User>& Service::GetUsers()
{
	return repo.GetUsers();
}

int Service::size()
{
	return repo.size();
}

int Service::getCoordX()
{
	std::vector<TElem>& array = repo.GetObjects();
	for (auto stea : array)
	{
		if (stoi(stea.getRA()) > x)
			x = stoi(stea.getRA());
		if (stoi(stea.getDEC()) > y)
			y = stoi(stea.getDEC());
	}
	return x;
}
int Service::getCoordY()
{
	std::vector<TElem>& array = repo.GetObjects();
	for (auto stea : array)
	{
		if (stoi(stea.getRA()) > x)
			x = stoi(stea.getRA());
		if (stoi(stea.getDEC()) > y)
			y = stoi(stea.getDEC());
	}
	return y;
}


std::vector<TElem>& Service::getSorted()
{
	std::vector<TElem> &array = repo.GetObjects();

	std::sort(array.begin(), array.end(),
		[](TElem& a, TElem& b) -> bool
		{ return a.getConstelation() < b.getConstelation(); });

	return array;
}

std::vector<TElem> Service::getBySearch(std::string searchString)
{

	
	std::vector<TElem> vectorResult;
	if (searchString.size() == 0)
		return vectorResult;
	for (auto i : this->repo.GetObjects())
	{
		if (i.getName().find(searchString) != std::string::npos )
		{
			vectorResult.push_back(i);
		}
	}
	return vectorResult;

	
	

}

bool Service::findElementinList(TElem item, std::vector<TElem> list)
{
	for (auto elem : list)
	{
		if (elem.getName() == item.getName())
			return true;
	}
	return false;
}


std::vector<TElem> Service::getFiltered(std::string filter)
{
	std::vector<TElem> newlist;
	std::vector<TElem> all = repo.GetObjects();

	for (auto elem : all)
	{
		if (elem.getConstelation() == filter)
			newlist.push_back(elem);
	}

	return newlist;

}
