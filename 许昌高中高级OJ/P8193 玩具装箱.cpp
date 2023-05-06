#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e4 + 5;
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
LL n, l;
LL c[MAXN];
double dp[MAXN];
double sum[MAXN];
deque<LL> q;
inline double a(int i)
{
	return sum[i] + i;
}
inline double b(int i)
{
	return sum[i] + i + l + 1;
}
inline double x(int i)
{
	return b(i);
}
inline double y(int i)
{
	return dp[i] + b(i) * b(i);
}
inline double slope(int i, int j)
{
	return (y(j) - y(i)) / (x(j) - x(i));
}
int main()
{
	read(n, l);
	for (int i = 1; i <= n; i++)
	{
		read(c[i]);
		sum[i] = sum[i - 1] + c[i];
	}
	q.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		while (q.size() >= 2 && slope(q[0], q[1]) < 2 * a(i))
		{
			q.pop_front();
		}
		dp[i] = dp[q[0]] + (a(i) - b(q[0])) * (a(i) - b(q[0]));
		while (q.size() >= 2 && slope(q[q.size() - 2], q[q.size() - 1]) > slope(q[q.size() - 1], i))
		{
			q.pop_back();
		}
		q.push_back(i);
	}
	cout << (LL)dp[n] << endl;
	return 0;
}
