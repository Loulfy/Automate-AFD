#include <iostream>
#include <cstdlib>

#include "Automate.hpp"
#include "AF.hpp"
#include "AFD.hpp"

using namespace std;

int main(int argc, char *argv[])
{
	Automate* af = new AF();
	af->loadFromFile(argv[1]);
	af->draw();

        Automate* afd = new AFD((AF*)af);
	afd->draw();

	delete af;
	delete afd;
	
	return EXIT_SUCCESS;
}
