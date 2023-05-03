#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
int ans = -0x7f7f7f7f;
int n, m;
int sum[MAXN];
int nums[MAXN];
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
	n = read<int>();
	for (int i = 1; i <= n; i++)
	{
		nums[i] = read<int>();
		sum[i] = sum[i - 1] + nums[i];
	}
	 m = read<int>();
	for (int i = 0; i <= n; i++)
	{
		while (!dl.empty() && dl.front() < i - m)
		{
			dl.pop_front();
		}
		if (!dl.empty() && dl.front() != i)
		{
			ans = max(ans, sum[i] - sum[dl.front()]);
		}
		while (!dl.empty() && sum[dl.back()] >= sum[i])
		{
			dl.pop_back();
		}
		dl.push_back(i);
	}
	write(ans);
	putchar('\n');
}
