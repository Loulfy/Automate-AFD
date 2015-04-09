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
			/*		
			//DRAW
			cout << "set 0=";
			for(auto x : af->transitions()[e][0])
			{
				cout << x << " ";
			}
			cout << endl;

			//DRAW
			cout << "set 1=";
			for(auto x : af->transitions()[e][1])
			{
				cout << x << " ";
			}
			cout << endl;
			*/

			//APPEND
			tmp = af->transitions()[e][0];
			a.insert(tmp.begin(), tmp.end());
			tmp.clear();

			tmp = af->transitions()[e][1];
			b.insert(tmp.begin(), tmp.end());
			tmp.clear();
		}

		vector<int> v(2);

		for(int n = 0; n < (int)m_etats.size(); ++n)
		{
			if(a == m_etats[n])
				v[0] = n;

			if(b == m_etats[n])
				v[1] = n;
		}

		if(i == 0)
		{
			v[0] = 1;
			v[1] = 2;
		}

		//CHECK
		if(checkEtatDoublon(a) && !a.empty())
		{
			m_etats.push_back(a);
			a.clear();
		}

		//CHECK
		if(checkEtatDoublon(b) && !b.empty())
		{
			m_etats.push_back(b);
			b.clear();
		}

		m_transitions.push_back(v);
	}
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
