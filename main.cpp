#include "Exam.h"
#include <QtWidgets/QApplication>
#include "Repository.h"
#include "Service.h"
#include "Test.h"

int main(int argc, char *argv[])
{

	TestAdd();
    QApplication a(argc, argv);

	Repository repo{};
	Service service(repo);

    Exam w(service);
	w.start();
    return a.exec();
}
