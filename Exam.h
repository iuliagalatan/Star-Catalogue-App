#pragma once
#include "Service.h"
#include "observer.h"
#include <QtWidgets/QMainWindow>
//#include "ui_Exam.h"
#include "TableModel.h"

class Exam 
{
  

public:
	Exam(Service& serv) :service{ serv }
	{
		model = new TableModel(&serv);
	};
	void start();
	Observer* CreateObserver(User& user);

private:
	Service& service;
	TableModel* model;

};
