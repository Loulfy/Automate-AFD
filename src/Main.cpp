#include <iostream>
#include <cstdlib>

#include "Automate.hpp"
#include "AF.hpp"
#include "AFD.hpp"

using namespace std;

int main(int argc, char *argv[])
{

    if(argc == 2)
    {
        Automate* af = new AF();
        if(af->loadFromFile(argv[1]))
        {
            cout << "\nAutomate AF de départ :" << endl;
            af->draw();

            Automate* afd = new AFD((AF*)af);
            cout << "\nAutomate AFD de fin :" << endl;
            afd->draw();

            delete af;
            delete afd;

            return EXIT_SUCCESS;
        }
        else
        {
            delete af;
        }
    }
    else
    {
        cout << "Usage : auto <file>" << endl;
    }

    return EXIT_FAILURE;
}
