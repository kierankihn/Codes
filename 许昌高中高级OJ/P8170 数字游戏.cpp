#include <bits/stdc++.h>
using namespace std;
const int MAXN = 15;
int l, r;
int dp[MAXN][MAXN];
void init()
{
	for (int i = 0; i <= 9; i++)
	{
		dp[1][i] = 1;
	}
	for (int i = 2; i <= MAXN ; i++)
	{
		for (int j = 0; j <= 9; j++)
		{
			for (int k = j; k <= 9; k++)
			{
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
}
int solve(int x)
{
	int tot = 0;
	int res = 0;
	int pre = 0;
	int num[MAXN];
	if (!x)
	{
		return 1;
	}
	while (x)
	{
		tot++;
		num[tot] = x % 10;
		x /= 10;
	}
	for (int i = tot; i >= 1; i--)
	{
		if (num[i] < pre)
		{
			break;
		}
		for (int j = pre; j < num[i]; j++)
		{
			res += dp[i][j];
//			cout << i << " " << j << " " << dp[i][j] << endl;
		}
		pre = num[i];
		if (i == 1)
		{
			res++;
		}
	}
	return res;
}
int main()
{
	init();
	while (cin >> l >> r)
	{
//		cout << solve(r) << endl;
//		cout << solve(l - 1) << endl;
		cout << solve(r) - solve(l - 1) << endl;
	}
	return 0;
}
