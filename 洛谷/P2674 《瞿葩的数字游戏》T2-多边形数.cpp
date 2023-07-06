#include <bits/stdc++.h>
using namespace std;
vector<int> k; 
void solve(int x)
{
	k.clear();
	if (x == 1)
	{
		k.push_back(4), k.push_back(3);
	}
	x = 2 * x;
	for (int i = 2; i * i + i <= x; i++)
	{
		if ((x - 2 * i) % (i * i - i) == 0)
		{
			k.push_back((x - 2 * i) / (i * i - i) + 2);
		}
	}
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		int x;
		cin >> x;
		solve(x);
		if (k.size() >= 2)
		{
			cout << k[k.size() - 1] << " " << k[k.size() - 2] << endl;
		}
		else if (k.size() == 1)
		{
			cout << k[0] << endl;
		}
		else
		{
			cout << "Poor" << x << endl;
		}
	}
	return 0;
}
