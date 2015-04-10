#include <iostream>
#include <cstdlib>

#include "Automate.hpp"
#include "AF.hpp"
#include "AFD.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Automate* a = new AF();
	Automate* afd = nullptr;

	AF* af = dynamic_cast<AF*>(a);

	if(af != nullptr)
	{
		af->loadFromFile(argv[1]);
		af->draw();

		afd = new AFD(af);
		afd->draw();
	}

	delete af;
	delete afd;
	
	return EXIT_SUCCESS;
}
