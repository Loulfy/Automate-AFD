#include "AFD.hpp"

using namespace std;

AFD::AFD()
{

}

AFD::AFD(AF* af) : m_initiaux({0}), m_terminaux(af->terminaux())
{
    //"Dé-upsilon-isation" de l'AF
    af->deupsilonisation();

    //Premier état de l'AFD !
    m_etats.push_back(af->initiaux());

    set<int> a;
    set<int> b;

    set<int> tmp;

    //Attention ce FOR est un WHILE !
    for(int i = 0; i < (int)m_etats.size(); ++i)
    {
        //Construit un état par addition de set pour les deux transitions.
        //Un état = un set !
        for(auto e : m_etats[i])
        {
            //Transition : 0
            tmp = af->transitions()[e][0];
            a.insert(tmp.begin(), tmp.end());
            tmp.clear();

            //Transition : 1
            tmp = af->transitions()[e][1];
            b.insert(tmp.begin(), tmp.end());
            tmp.clear();
        }

        //CHECK Transition : 0
        //Si l'état n'existe pas déjà dans m_etats et que l'état n'est pas vide
        if(checkEtatDoublon(a) && !a.empty())
        {
            //On le rajoute
            m_etats.push_back(a);
        }

        //CHECK Transition : 1
        if(checkEtatDoublon(b) && !b.empty())
        {
            m_etats.push_back(b);
        }

        //Un AFD n'a que 2 transitions.
        //Par défaut, les transitions pointent sur l'état puit.
        vector<int> v(2, (int)m_etats.size());
        
        //Relie un état à un état de sortie
        //Par comparaison de set.
        for(int n = 0; n < (int)m_etats.size(); ++n)
        {
            //Pour la transition : 0
            if(a == m_etats[n])
                v[0] = n;

            //Pour la transition : 1
            if(b == m_etats[n])
                v[1] = n;
        }

        //Nettoyage pour le tour de boucle suivant.
        a.clear();
        b.clear();

        //On rajoute les deux transitions à son état.
        m_transitions.push_back(v);
    }

    //UNE FOIS TOUS LES ÉTATS DÉTERMINÉS

    //On détermine les états TERMINAUX
    for(int i = 0; i < (int)m_etats.size(); ++i)
    {
        for(auto e : m_terminaux)
        {
            if(m_etats[i].find(e) != m_etats[i].end())
                m_terminaux.insert(i);
        }
    }

    //Et l'état INITIAL est initialisé dans le constructeur.
}

//Vérifie si l'état existe déjà dans m_etats.
bool AFD::checkEtatDoublon(set<int> set)
{
    for(auto s : m_etats)
    {
        if(set == s)
        {
            return false;
        }
    }

    return true;
}

void AFD::draw()
{
    cout << "DETERMINISTE !" << endl;
    cout << "------------------" << endl;

    //Affiche les états avec leurs équivalents dans l'automate non déterminé
    for(int i = 0; i < (int)m_etats.size(); ++i)
    {
        int cpt = 0;
        cout << i << " : { ";
        for(auto e : m_etats[i])
        {
            ++cpt;
            cout << e;
            if(cpt != (int)m_etats[i].size())
            {
                cout << ", ";
            }
        }
        cout << " }" << endl;
    }

    //Affiche les globalités
    cout << "------------------" << endl;
    cout << "États      : " << m_etats.size() << endl;
    cout << "Initiaux   : ";
    for(auto e : m_initiaux)
    {
        cout << e << " ";
    }
    cout << endl;
    
    cout << "Terminaux  : ";
    for(auto e : m_terminaux)
    {
        cout << e << " ";
    }
    cout << endl;

    for(int y = 0; y < (int)m_transitions.size(); ++y)
    {
        for(int x = 0; x < 2; ++x)
        {
            cout << "Transition : " << y << " " << x << " " << m_transitions[y][x] << endl;
        }
    }
}
