#include "Test.h"

void TestAdd()
{
	Repository repo{};
	Service service(repo);
	int vectorsize = repo.size();
	Star star = Star("luna", "Milk", "12", "12", 23);
	repo.AddStar(star);
	assert(repo.size() == vectorsize + 1);

}
