#include "AF.hpp"

using namespace std;

vector<string> split(string line)
{
    string delimiter = " ";
    size_t pos = 0;
    size_t i = 0;

    vector<string> parsed;

    pos = line.find(delimiter);
    while( pos != string::npos )
    {
        parsed.push_back(line.substr(i,pos-i));
        i = pos + 1;
        pos = line.find(delimiter,i);
    }

    parsed.push_back(line.substr(i));

    return parsed;
}

AF::AF() : m_etats(0)
{

}

void AF::draw()
{
	cout << "NON DETERMINISTE !" << endl;
	cout << "------------------" << endl;
	cout << "États      : " << m_etats << endl;

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

	for(int y = 0; y < m_etats; ++y)
	{
		for(int x = 0; x < 3; ++x)
		{
			if((int)m_transitions[y][x].size() > 0)
			{
				for(auto e : m_transitions[y][x])
				{
					cout << "Transition : " << y << " " << x << " " << e << endl;
				}
			}
		}
	}

	cout << "------------------" << endl;
}

bool AF::loadFromFile(string filePath)
{
	ifstream file(filePath.c_str());
    if(!file)
    {
        cout << "Erreur d'ouverture du fichier : " + filePath +" !" << endl;
		return false;
    }
	else
	{
    	string line;
    	vector<string> tuple;

		//NOMBRE D'ÉTATS
		getline(file, line);
		m_etats = stoi(line);

		//ÉTAT INITIAUX
		getline(file, line);
		tuple = split(line);

		for(auto e : tuple)
		{
			m_initiaux.insert(stoi(e));
		}

		tuple.clear();

		//ÉTAT TERMINAUX
		getline(file, line);
		tuple = split(line);

		for(auto e : tuple)
		{
			m_terminaux.insert(stoi(e));
		}

		tuple.clear();

		//TRANSITIONS
		m_transitions.resize(m_etats);

		for(int i = 0; i < m_etats; ++i)
		{
			m_transitions[i].resize(3);
		}

		getline(file, line);

    	while(!file.eof() && !line.empty())
    	{
        	tuple = split(line);

			m_transitions[stoi(tuple[0])][stoi(tuple[1])].insert(stoi(tuple[2]));

			getline(file, line);		
    	}

		file.close();
		
		return true;
	}
}

void AF::deupsilonisation()
{
	//CHERCHE LES UPSILON-TRANSITIONS
	for(int i = 0; i < m_etats; ++i)
	{
		//POUR CHACUNE
		for(auto e : m_transitions[i][2])
		{		
			//ETAPE 1 : Prédecesseur initial ?
			for(auto n : m_initiaux)
			{
				//OUI, alors l'actuel le devient aussi.
				if(i == n)
				{
					m_initiaux.insert(e);
					break;
				}
			}

			//ETAPE 2 : Redirection !
			for(int y = 0; y < m_etats; ++y)
			{
				for(int x = 0; x < 3; ++x)
				{
					for(auto n : m_transitions[y][x])
					{
						//OUI, alors on assigne la sortie à l'état pointé.
						if(i == n)
						{
							m_transitions[y][x].insert(e);
						}
					}
				}
			}

			//ETAPE 3 : Suppression de l'upsilon-transition !
			m_transitions[i][2].erase(e);
		}
	}
}

set<int> AF::initiaux()
{
	return m_initiaux;
}

set<int> AF::terminaux()
{
	return m_terminaux;
}

vector<vector<set<int>>> AF::transitions()
{
	return m_transitions;
}
