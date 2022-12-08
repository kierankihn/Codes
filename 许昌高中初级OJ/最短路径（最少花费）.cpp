#include <bits/stdc++.h>
using namespace std;
const int MAXN = 20;
int n;
int mp[MAXN + 5][MAXN + 5];
int dp[MAXN + 5];
int vis[MAXN + 5];
int solve(int x)
{
	int ans = -2;
	if (dp[x] != -1)
	{
		ans = dp[x];
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (mp[x][i])
			{
				if ((ans == -2) || (ans > solve(i) + mp[x][i]))
				{
					ans = solve(i) + mp[x][i];
				}
			}
		}
	}
	return dp[x] = ans;
}
void print(int i)
{
	cout << i << " ";
	for (int j = 1; j <= n; j++)
	{
		if (mp[i][j] && (mp[i][j] + dp[j] == dp[i]))
		{
			print(j);
		}
	}
	return;
}
int main()
{
	memset(mp, 0, sizeof(mp));
	memset(vis, 0, sizeof(vis));
	memset(dp, -1, sizeof(dp));
	cin >> n;
	dp[n] = 0;
	vis[1] = vis[n] = true;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> mp[i][j];
		}
	}
	cout << "minlong=" << solve(1) << endl;
	print(1);
	cout << endl;
	return 0;
}
