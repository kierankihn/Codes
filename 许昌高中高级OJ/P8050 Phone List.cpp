#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 5;
const int MAXM = 10 + 1;
const int MAXL = 10 + 1;
int T;
int n;
bool ans = false;
int tot = 0;
string str;
int ch[MAXN * MAXL][MAXM];
bool isend[MAXN * MAXL];
void init()
{
	ans = false;
	tot = 0;
	memset(ch, 0, sizeof(ch));
	memset(isend, 0, sizeof(isend));
}
bool insert(string str)
{
	int u = 0;
	for (unsigned int i = 0; i < str.size(); i++)
	{
		if (!ch[u][str[i] - '0'])
		{
			tot++;
			ch[u][str[i] - '0'] = tot;
		}
		else
		{
			if (i + 1 == str.size())
			{
				return true;
			}
		}
		u = ch[u][str[i] - '0'];
		if (isend[u])
		{
			return true;
		}
	}
	isend[u] = true;
	return false;
}
int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n;
		init();
		for (int i = 1; i <= n; i++)
		{
			cin >> str;
			if (insert(str))
			{
				ans = true;
			}
		}
		if (ans)
		{
			cout << "NO\n";
		}
		else
		{
			cout << "YES\n";
		}
	}
	return 0;
}
