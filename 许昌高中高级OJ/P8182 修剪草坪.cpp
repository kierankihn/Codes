#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
long long n, m;
long long sum[MAXN];
long long nums[MAXN];
long long dp[MAXN][2];
deque<int> dl;
template <typename T> T read()
{
	T res = 0, s = 1;
	char ch;
	while ((ch = getchar()) < '0' || ch > '9')    if (ch == '-')    s = -1;
	while (ch >= '0' && ch <= '9')                res = res * 10 + ch - '0', ch = getchar();
	return res * s;
}
template <typename T> void write(T x)
{
	if (x < 0)    putchar('-'), x = -x;
	if (x > 9)    write(x / 10);
	putchar((x % 10) + '0');
}
int main()
{
	n = read<long long>(), m = read<long long>();
	for (int i = 1; i <= n; i++)
	{
		nums[i] = read<long long>();
		sum[i] = sum[i - 1] + nums[i];
	}
	dl.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
		while (!dl.empty() && dl.front() < i - m)
		{
			dl.pop_front();
		}
		dp[i][1] = dp[dl.front()][0] + sum[i] - sum[dl.front()];
		while (!dl.empty() && dp[dl.back()][0] - sum[dl.back()] < dp[i][0] - sum[i])
		{
			dl.pop_back();
		}
		dl.push_back(i);
	}
	write(max(dp[n][0], dp[n][1]));
	putchar('\n');
}
