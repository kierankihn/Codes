#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200;
int n;
int res = -1;
int mp[MAXN + 5][MAXN + 5];
int dp[MAXN + 5][3]; // 0为原数据 1为dp 2为上一个点
int solve(int k)
{
	int ans = dp[k][0];
	if (dp[k][1] != -1)
	{
		return dp[k][1];
	}
	else
	{
		for (int i = k; i <= n; i++)
		{
			if (mp[k][i])
			{
				if (ans < solve(i) + dp[k][0])
				{
					ans = solve(i) + dp[k][0];
					dp[k][2] = i;
				}
			}
		}
	}
	return dp[k][1] = ans;
}
void print_ans(int k)
{
	cout << k;
	if (dp[k][2] != -1)
	{
		cout << "-";
		print_ans(dp[k][2]);
	}
}
int main()
{
	memset(mp, 0, sizeof(mp));
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> dp[i][0];
		dp[i][1] = -1;
		dp[i][2] = -1;
	}
	int tmp1, tmp2;
	while (cin >> tmp1 >> tmp2)
	{
		if ((!tmp1) || (!tmp2))
		{
			break;
		}
		mp[tmp1][tmp2] = 1;
	}
	int p;
	for (int i = 1; i <= n; i++)
	{
		if (solve(i) > res)
		{
			res = solve(i);
			p = i;
		}
	}
	print_ans(p);
	cout << endl;
	cout << res << endl;
	return 0;
}
