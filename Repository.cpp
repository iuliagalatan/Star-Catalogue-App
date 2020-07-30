#include "Repository.h"
#include <fstream>

Repository::Repository(QObject* parent)
	: QObject(parent)
{
	Read();
	ReadUsers();

}

Repository::~Repository()
{
	
	std::string fileIssues = "stars.txt";
	std::ofstream fout(fileIssues);

	std::vector<TElem>& array = GetObjects();

	std::sort(array.begin(), array.end(),
		[](TElem& starA, TElem& starB) -> bool
		{ return starA.getConstelation() < starB.getConstelation(); });

	for (auto object :array)
		fout << object << '\n';
}

/*
	Specifications:
	AddStar function adds an object of type star to the repository's vector
	Input:Object star
	Output: - (adds to the list of objects, notfies the observers to refresh their tableviews)
*/
void Repository::AddStar( TElem& star)
{
	objects.push_back(star);
	notify();
}

void Repository::Read()
{
	std::string fileIssues = "stars.txt";
	std::ifstream fin(fileIssues);
	TElem object;
	while (fin >> object)
		AddStar(object);
}

void Repository::ReadUsers()
{
	std::string fileIssues = "astronomer.txt";
	std::ifstream fin(fileIssues);
	User object;
	while (fin >> object)
		AddUser(object);
}

void Repository::Write()
{
	
}

void Repository::AddUser(User& u)
{
	users.push_back(u);
	notify();
}

std::vector<TElem>& Repository::GetObjects()
{
	return objects;
}

std::vector<User>& Repository::GetUsers()
{
	// TODO: insert return statement here
	return users;
}

int Repository::size() 
{
	return objects.size();
}

void Repository::RemoveObject( TElem& issue)
{
	for (auto it = objects.begin(); it != objects.end(); ++it)
		if (it->getName() == issue.getName())
		{
			objects.erase(it);
			// notify all observers that an issue was removed
			notify();
			break;
		}
}

void Repository::UpdateObject( TElem& object)
{
	for (auto& iss : objects)
		if (iss.getName()== object.getName())
		{
			iss = object;
			// notify all observers that an issue was resolved
			notify();
			break;
		}
}
