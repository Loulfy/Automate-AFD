#include <iostream>
#include <cstdlib>

#include "Automate.hpp"
#include "AF.hpp"

using namespace std;

int main()
{
	Automate* a = new AF();

	AF* af = dynamic_cast<AF*>(a);

	if(af != nullptr)
	{
		af->loadFromFile("exemple/auto-2.txt");
		af->draw();
		af->toDeterminist();
		af->draw();
	}
	
	return EXIT_SUCCESS;
}
