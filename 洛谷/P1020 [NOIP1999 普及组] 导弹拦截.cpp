#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100000;
int h[MAXN + 5];
int ans1 = 1;
int ans2 = 1;
int bomb[MAXN + 5];
int dp[MAXN + 5];
int vis[MAXN + 5];
int solve(int k)
{
	if (vis[k])
	{
		return dp[k];
	}
	else
	{
		for (int i = 1; i < k; i++)
		{
			if (bomb[k] <= bomb[i])
			{
				dp[k] = max(solve(i) + 1, dp[k]);
			}
		}
	}
	vis[k] = 1;
	return dp[k];
}
int main()
{
	memset(vis, 0, sizeof(vis));
	int n = 1;
	cin >> bomb[1];
	h[1] = bomb[1];
	vis[1] = 1;
	while (cin >> bomb[n + 1])
	{
		n++;
		sort(h + 1, h + ans2 + 1);
		int temp = 1;
		while (bomb[n] > h[temp])
		{
			temp++;
			if (temp > ans2)
			{
				ans2++;
				h[ans2] = bomb[n];
				break;
			}
		}
		if (temp <= ans2)
		{
			h[temp] = bomb[n];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		ans1 = max(ans1, solve(i));
	}
	cout << ans1 << endl
		 << ans2 << endl;
}
