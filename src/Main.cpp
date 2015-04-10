#include <iostream>
#include <cstdlib>

#include "Automate.hpp"
#include "AF.hpp"
#include "AFD.hpp"

using namespace std;

int main()
{
	Automate* a = new AF();

	AF* af = dynamic_cast<AF*>(a);

	if(af != nullptr)
	{
		af->loadFromFile("exemple/auto-3.txt");
		af->draw();
		Automate* afd = new AFD(af);
		afd->draw();
	}
	
	return EXIT_SUCCESS;
}
