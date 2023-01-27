#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000;
int n;
int nums[MAXN + 5][MAXN + 5];
int dp[MAXN + 5][MAXN + 5];
int main()
{
	memset(dp, -1, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> nums[i][j];
		}
	}
	for (int i = 1; i <= n; i++)
	{
		dp[n][i] = nums[n][i];
	}
	for (int i = n - 1; i >= 1; i--)
	{
		for (int j = 1; j <= n; j++)
		{
			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + nums[i][j];
		}
	}
	cout << dp[1][1] << endl;

	return 0;
}
