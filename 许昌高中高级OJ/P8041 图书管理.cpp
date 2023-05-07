#include <bits/stdc++.h>
using namespace std;
int n;
string tmp;
set<string> s;
int main()
{
	cin >> n;
	getline(cin, tmp);
	for (int i = 1; i <= n; i++)
	{
		getline(cin, tmp);
		if(tmp[0] == 'a')
		{
			s.insert(tmp.substr(4, tmp.size() - 4));
		}
		else
		{
			if (s.count(tmp.substr(5, tmp.size() - 5)))
			{
				cout << "yes" << endl;
			}
			else
			{
				cout << "no" <<endl;
			}
		}
	}
	return 0;
} 
