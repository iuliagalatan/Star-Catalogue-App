#pragma once
#include "Object.h"
#include "observer.h"
#include <QObject>
#include "User.h"
// Repository class for issues 
// and in the same time an observable class 
class Repository : public QObject, public Observable
{
	Q_OBJECT

public:
	Repository(QObject* parent = nullptr);
	~Repository();

	//void AddObject(std::string description, std::string reporter);
	void Read();
	void ReadUsers();
	void Write();
	std::vector<TElem>& GetObjects();
	std::vector<User>& GetUsers();

	//void addObserver(Observer* o);

	int size();
public slots:
	void AddStar(TElem& o);
	void AddUser(User& o);
	void RemoveObject(TElem& o);
	void UpdateObject( TElem& o);

private:
	std::vector<TElem> objects;
	std::vector<User> users;
	//std::string fileIssues;
};
