#include <bits/stdc++.h>
using namespace std;
const int MAXN = 50 + 5;
const int MAXREP = 31;
int l, r;
int n, b;
int dp[MAXN][MAXN];
void init()
{
	dp[0][0] = 1;
	for (int i = 1; i <= MAXREP; i++)
	{
		dp[i][0] = 1;
		for (int j = 1; j <= i; j++)
		{
			dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
		}
	}
}
int countBinNum(int x, int k)
{
	int tot, ans;
	tot = ans = 0;
	for (int i = MAXREP; i > 0; i--)
	{
		if (x & (1 << i))
		{
			tot++;
			if(tot > k)
			{
				break;
			}
			x = x ^ (1 << i);
		}
		if (1 << (i - 1) <= x)
		{
			ans += dp[i - 1][k - tot];
		}
	}
	if (tot + x == k)
	{
		ans++;
	}
	return ans;
}
int convertToBin(int x)
{
	int res = 0;
	int tot = 0;
	bool isOtherNumExist = false;
	int x_in_b[MAXREP];
	while (x)
	{
		tot++;
		x_in_b[tot] = x % b;
		x = x / b;
	}
	for (int i = tot; i >= 1; i--)
	{
		if (x_in_b[i] > 1)
		{
			isOtherNumExist = true;
		}
		if (isOtherNumExist)
		{
			x_in_b[i] = 1;
			continue;
		}
	}
	for (int i = 1; i <= tot; i++)
	{
		res += x_in_b[i] * (1 << (i - 1));
	}
	return res;
}
int main()
{
	init();
	cin >> l >> r;
	cin >> n >> b;
	l = convertToBin(l);
	r = convertToBin(r);
	cout << countBinNum(r, n) - countBinNum(l - 1, n) << endl;
	return 0;
}
