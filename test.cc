#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main()
{

	set<int> cs = {10,20,30};
	set<int> css;

	css.insert(cs.begin(), cs.end());

	vector<set<int>> vs;

	vs.push_back(css);

	for(auto i : vs)
	{
		if(i == cs)
		{
			cout << "existe deja" << endl;
		}
		else
		{
			vs.push_back(cs);
		}
	}

	for(int i=0; i < vs.size(); ++i)
	{
		for(auto e : vs[i])
			cout << e << endl;
	}

	return 0;
}
