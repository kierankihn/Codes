#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXP = 1e2 + 5;
typedef long long LL;
LL n, m, p;
LL d[MAXN], a[MAXN], sum[MAXN], g[MAXN];
LL dp[MAXP][MAXN];
deque<int> q;
template <typename T> void read(T& x)
{
	T res = 0, s = 1;
	char ch;
	while ((ch = getchar()) < '0' || ch > '9')    if (ch == '-')    s = -1;
	while (ch >= '0' && ch <= '9')                res = res * 10 + ch - '0', ch = getchar();
	x = res * s;
}
template <typename First, typename... Rest> void read(First& first, Rest&... rest)
{
	read(first);
	read(rest...);
}
void write()
{
	putchar('\n');
}
void write(char ch)
{
	putchar(ch);
}
template <typename T> void write(char delimiter, T x)
{
	if (x < 0)    putchar('-'), x = -x;
	if (x > 9)    write(delimiter, x / 10);
	putchar((x % 10) + '0');
}
template <typename First, typename... Rest> void write(char delimiter, First& first, Rest&... rest)
{
	write(delimiter, first);
	putchar(delimiter);
	if (sizeof...(rest) >= 1)
	{
		write(delimiter, rest...);
	}
}
template <typename First, typename... Rest> void write(char delimiter, char linedelimiter, First& first, Rest&... rest)
{
	write(delimiter, first);
	putchar(delimiter);
	if (sizeof...(rest) >= 1)
	{
		write(delimiter, rest...);
	}
	putchar(linedelimiter);
}
template <typename... T> void write(T... t)
{
	write(' ', '\n', t...);
}
LL x(int i)
{
	return i;
}
LL y(int j, int i)
{
	return dp[i - 1][j] + sum[j];
}
double slope(int i, int j, int k)
{
	return (double)(x(i) - x(j)) / (y(i, k) - y(j, k));
}
int main()
{
	memset(dp, 0x3f, sizeof(dp));
	dp[0][0] = 0;
	read(n, m, p);
	for (int i = 2; i <= n; i++)
	{
		read(d[i]);
		d[i] += d[i - 1];
	}
	for (int i = 1; i <= m; i++)
	{
		int h, t;
		read(h, t);
		a[i] = t - d[h];
	}
	sort(a + 1, a + m + 1);
	for (int i = 1; i <= m; i++)
	{
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= p; i++)
	{
		q.clear();
		q.push_back(0);
		for (int j = 1; j <= m; j++)
		{
			g[j] = y(j, i);
		}
		for (int j = 1; j <= m; j++)
		{
			while (q.size() >= 2 && a[j] * (q[1] - q[0]) >= g[q[1]] - g[q[0]])
			{
				q.pop_front();
			}
			int k = q[0];
			dp[i][j] = min(dp[i - 1][j], dp[i - 1][k] + a[j] * (j - k) + sum[k] - sum[j]);
			if (g[j] >= 0x3f3f3f3f3f3f3f3fll)
			{
				continue;
			}
			while (q.size() >= 2 && (g[j] - g[q[q.size() - 1]]) * (q[q.size() - 1] - q[q.size() - 2]) <= (g[q[q.size() - 1]] - g[q[q.size() - 2]]) * (j - q[q.size() - 1]))
			{
				q.pop_back();
			}
			q.push_back(j);
		}
	}
	write(dp[p][m]);
	return 0;
}
