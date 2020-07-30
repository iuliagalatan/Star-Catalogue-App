#include "Exam.h"
#include "Observer1.h"

void Exam::start()
{
	std::vector<User> users = service.GetUsers();
	for (User& user : users)
	{
		Observer* observer = CreateObserver(user);
		service.addObserver(observer);
		observer->show();
	}
}



Observer* Exam::CreateObserver( User& user)
{
	Observer* observer = nullptr;
	
	
		observer = new Observer1(service, QString::fromStdString(user.getConstelation()),QString::fromStdString(user.getName()) ,model);

	return observer;
}

