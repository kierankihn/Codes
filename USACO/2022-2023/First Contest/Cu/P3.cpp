#include <bits/stdc++.h>
using namespace std;
const int MAXM = 100;
int n, m;
string input[MAXM + 5];
int output[MAXM + 5];
bool vis[MAXM + 5];
int count()
{
	int res = 0;
	for (int i = 1; i <= m; i++)
	{
		if (!vis[i])
		{
			res++;
		}
	}
	return res;
}
void solve()
{
	int cnt = 0;
	do
	{
		cnt=count();
		for (int i = 0; i < n; i++)
		{
			int tmp[2] = {-1, -1};
			int is[2] = {1, 1};
			for (int j = 1; j <= m; j++)
			{
				if (vis[j])
				{
					continue;
				}
				if (tmp[input[j][i] - '0'] == -1)
				{
					tmp[input[j][i] - '0'] = output[j];
				}
				if (tmp[input[j][i] - '0'] != output[j])
				{
					is[input[j][i] - '0'] = 0;
				}
			}
			if (is[0])
			{
				for (int j = 1; j <= m; j++)
				{
					if (input[j][i] == '0')
					{
						vis[j] = true;
					}
				}
			}
			if (is[1])
			{
				for (int j = 1; j <= m; j++)
				{
					if (input[j][i] == '1')
					{
						vis[j] = true;
					}
				}
			}
		}
	}
	while(count() != 0 && count()!=cnt);
	for (int i = 1; i <= m; i++)
	{
		if (!vis[i])
		{
			cout << "LIE\n";
			return;
		}
	}
	cout << "OK\n";
}
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(vis, 0, sizeof(vis));
		cin >> n >> m;
		for (int i = 1; i <= m; i++)
		{
			cin >> input[i] >> output[i];
		}
		solve();
	}
	return 0;
}
