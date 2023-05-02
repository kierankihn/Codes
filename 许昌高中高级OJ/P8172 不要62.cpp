#include <bits/stdc++.h>
using namespace std;
const int MAXN = 12;
int l, r;
int dp[MAXN][MAXN];
void init()
{
	for (int i = 0; i <= 9; i++)
	{
		if (i != 4)
		{
			dp[1][i] = 1;
		}
	}
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 0; j <= 9 ; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				if (j != 4 && k != 4 && (j != 6 || k != 2))
				{
					dp[i][j] += dp[i - 1][k];
				}
			}
		}
	}
}
int solve(int x)
{
	if(!x)
	{
		return 1;
	}
	int res = 0;
	int len = 0;
	int nums[MAXN];
	memset(nums, 0, sizeof(nums));
	while(x)
	{
		len++;
		nums[len] = x % 10;
		x /= 10;
	}
	nums[len + 1] = 785;
	for (int i = len; i >= 1; i--)
	{
		for (int j = 0; j < nums[i]; j++)
		{
			if (j != 4 && (nums[i + 1] != 6 || j != 2))
			{
				res += dp[i][j];
			}
		}
		if (nums[i] == 4 || (nums[i + 1] == 6 && nums[i] == 2))
		{
			break;
		}
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
	while(cin >> l >> r)
	{
		if(!(l && r))
		{
			break;
		}
		cout << solve(r) - solve(l - 1) << endl;
	}
	return 0;
}
