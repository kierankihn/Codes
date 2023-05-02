#include <bits/stdc++.h>
using namespace std;
const int MAXN = 12 + 2;
int l, r;
int dp[MAXN][MAXN][MAXN];
void init()
{
	for (int i = 0; i <= 9; i++)
	{
		dp[1][i][i] = 1; 
	}
	for (int i = 2; i <= 9; i++)
	{
		for (int j = 0; j <= 9 ; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				for (int p = 0; p <= 9; p++)
				{
					dp[i][j][p] += dp[i][k][p];
				}
			}
			dp[i][j][j] += pow(10, i - 1);
		}
	}
}
vector<int> solve(int x)
{
	vector<int> res;
	res.resize(10);
	int len = 0;
	int nums[MAXN];
	memset(nums, 0, sizeof(nums));
	while(x)
	{
		len++;
		nums[len] = x % 10;
		x /= 10;
	}
	for (int i = len; i >= 1; i--)
	{
		for (int j = 0; j < nums[i]; j++)
		{
			for (int k = 0; k <= 9; k++)
			{
				res[k] += dp[i][j][k];
			}
		}
		if (i == 1)
		{
			for (int j = 1; j <= len; j++)
			{
				res[nums[j]]++;
			}
		}
	}
	return res;
}
int main()
{
	init();
	cin >> l >> r;
	vector<int> resl,resr;
	resl = solve(l - 1);
	resr = solve(r);
	for (int i = 0; i <= 9; i++)
	{
		cout << resr[i] - resl[i] << " ";
	}
	cout << endl;
	return 0;
}
