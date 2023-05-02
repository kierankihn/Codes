#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 15;
long long l, r;
long long dp[MAXN][MAXN];
void init()
{
	for (long long i = 0; i <= 9; i++)
	{
		dp[1][i] = 1;
	}
	for (long long i = 2; i <= MAXN; i++)
	{
		for (long long j = 0; j <= 9; j++)
		{
			for (long long k = 0; k <= j - 2; k++)
			{
				dp[i][j] += dp[i - 1][k];
			}
			for (long long k = j + 2; k <= 9; k++)
			{
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	for (long long i = 2; i <= MAXN; i++)
	{
		dp[i][0] = 0;
		for (long long j = 2; j <= 9; j++)
		{
			dp[i][0] += dp[i - 1][j];
		}
	}
}
long long solve(long long x)
{
	if (!x)
	{
		return 0;
	}
	long long len = 0, res = 0;
	long long nums[MAXN];
	memset(nums,0,sizeof(nums));
	while (x)
	{
		len++;
		nums[len] = x % 10;
		x /= 10;
	}
	nums[len + 1] = 785;
	for (long long i = 1; i < len; i++)
	{
		for (long long j = 1; j <= 9; j++)
		{
			res += dp[i][j];
		}
	}
	for (long long i = 1; i < nums[len]; i++)
	{
		res += dp[len][i];
	}
	for (long long i = len - 1; i >= 1; i--)
	{
		for (long long j = 0; j < nums[i] ; j++)
		{
			if (abs(j - nums[i + 1]) >= 2)
			{
				res += dp[i][j];
			}
		}
		if (abs(nums[i + 1] - nums[i]) < 2)
		{
			break;
		}
	}
	for (long long i = 1; i <= len; i++)
	{
		if (abs(nums[i] - nums[i + 1]) < 2)
		{
			break;
		}
		if (i == len)
		{
			res++;
		}
	}
	return res;
}
int main()
{
	init();
	cin >> l >> r;
	cout << solve(r) - solve(l - 1) << endl;
	return 0;
}
