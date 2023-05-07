#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n;
int ans = 0;
int nums[MAXN];
int pre[MAXN];
unordered_map<int, int> cur;
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
int main()
{
	read(n);
	for (int i = 1; i <= n; i++)
	{
		read(nums[i]);
		if (cur.count(nums[i]))
		{
			pre[i] = cur[nums[i]];
		}
		cur[nums[i]] = i;
	}
	int l, r;
	l = r = 1;
	while (r <= n)
	{
		while (pre[r] < l && r <= n)
		{
			r++;
		}
		ans = max(ans, r - l);
		l++;
	}
	cout << ans << endl;
	return 0;
}
