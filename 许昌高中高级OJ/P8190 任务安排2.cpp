#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
typedef long long LL;
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
LL n, s;
LL c[MAXN];
LL t[MAXN];
LL dp[MAXN];
LL sumc[MAXN], sumt[MAXN];
deque<LL> q;
inline double x(int i)
{
	return sumc[i];
}
inline double y(int i)
{
	return dp[i];
}
inline double slope(int i, int j)
{
	return (y(j) - y(i)) / (x(j) - x(i));
}
int main()
{
	read(n, s);
	for (int i = 1; i <= n; i++)
	{
		read(t[i], c[i]);
		sumc[i] = sumc[i - 1] + c[i];
		sumt[i] = sumt[i - 1] + t[i];
	}
	q.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		while (q.size() >= 2 && slope(q[0], q[1]) < s + sumt[i])
		{
			q.pop_front();
		}
		int j = q[0];
		dp[i] = dp[j] - sumc[j] * (s + sumt[i]) + s * sumc[n] + sumc[i] * sumt[i];
		while (q.size() >= 2 && slope(q[q.size() - 2], q[q.size() - 1]) > slope(q[q.size() - 1], i))
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	write(dp[n]);
	return 0;
}
