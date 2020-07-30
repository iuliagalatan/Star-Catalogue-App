#pragma once
#include "Repository.h"
#include <algorithm>
#include "TableModel.h"
class Service
{

public:
	Service(Repository& repo) :repo{ repo }{}
	void AddObject(TElem& o);
	void AddUser(User& o);
	void RemoveObject(TElem& o);
	void UpdateObject(TElem& o);

	void addObserver(Observer* o);
	std::vector<TElem>& GetObjects();
	std::vector<User>& GetUsers();
	std::vector<TElem>& getSorted();
	std::vector<TElem> getBySearch(std::string searchString);
	bool findElementinList(TElem item, std::vector<TElem> list);
	std::vector<TElem> getFiltered(std::string name);
	int size();


	bool checked();

	int getCoordX();
	int getCoordY();

private:
	Repository& repo;
	int x = 0;
	int y = 0;

};

