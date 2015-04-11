#ifndef AFD_H
#define AFD_H

#include <iostream>
#include <vector>
#include <set>

#include "Automate.hpp"
#include "AF.hpp"

class AFD : public Automate
{
    public:

        AFD();
        AFD(AF* af);
        void draw() override;

    private:

        std::set<int> m_initiaux;
        std::set<int> m_terminaux;
        std::vector<std::vector<int>> m_transitions;
        std::vector<std::set<int>> m_etats;

        bool checkEtatDoublon(std::set<int> set);

};

#endif
