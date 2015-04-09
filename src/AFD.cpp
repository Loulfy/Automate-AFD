#include "AFD.hpp"

using namespace std;

AFD::AFD(AF* af) : m_initiaux(af->initiaux()), m_terminaux(af->terminaux())
{
	af->toDeterminist();
	af->draw();

	m_etats.push_back(m_initiaux);

	set<int> a;
	set<int> b;

	set<int> tmp;

	for(int i = 0; i < (int)m_etats.size(); ++i)
	{
		for(auto e : m_etats[i])
		{
			//APPEND
			tmp = af->transitions()[e][0];
			a.insert(tmp.begin(), tmp.end());
			tmp.clear();

			tmp = af->transitions()[e][1];
			b.insert(tmp.begin(), tmp.end());
			tmp.clear();
		}

		//CHECK : 0
		if(checkEtatDoublon(a) && !a.empty())
		{
			m_etats.push_back(a);
		}

		//CHECK : 1
		if(checkEtatDoublon(b) && !b.empty())
		{
			m_etats.push_back(b);
		}

		vector<int> v(2);

		for(int n = 0; n < (int)m_etats.size(); ++n)
		{
			if(a == m_etats[n])
				v[0] = n;

			if(b == m_etats[n])
				v[1] = n;
		}

		a.clear();
		b.clear();

		m_transitions.push_back(v);
	}

	//TERMINAUX
	for(int i = 0; i < (int)m_etats.size(); ++i)
	{


		for(auto e : m_terminaux)
		{
			if(m_etats[i].find(e) != m_etats[i].end())
				m_terminaux.insert(i);
		}
	}

	//INITIAUX
	m_initiaux.clear();
	m_initiaux.insert(0);
}

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

	cout << "------------------" << endl;
	for(int i = 0; i < (int)m_etats.size(); ++i)
	{
		cout << "E " << i << " : ";
		for(auto e : m_etats[i])
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
