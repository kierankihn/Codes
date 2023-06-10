#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4e5 + 5;
const int MAXM = 2;
const int MAXL = 32 + 1;
int n;
int k;
int sum;
int tot = 0;
int ans = -1;
int nums[MAXN];
int tmp[MAXN][2];
int ch[MAXN * MAXL][MAXM];
bool isend[MAXN * MAXL];
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
bool insert(int x)
{
	int res = 0;
	int u = 0;
	for (unsigned int i = 32; i >= 1; i--)
	{
		int c = 1 & (x >> (i - 1));
		if (!ch[u][c])
		{
			tot++;
			ch[u][c] = tot;
		}
		u = ch[u][c];
	}
	isend[u] = true;
	return res;
}
int find(int x)
{
	int res = 0;
	int u = 0;
	for (unsigned int i = 32; i >= 1; i--)
	{
		int c = 1 & (x >> (i - 1));
		if (ch[u][c ^ 1])
		{
			res = res | (1 << (i - 1));
			u = ch[u][c ^ 1];
		}
		else
		{
			u = ch[u][c];
		}
	}
	return res;
}
void init()
{
	sum = 0;
	ans = -1;
	tot = 0;
	memset(ch, 0, sizeof(ch));
	memset(isend, 0, sizeof(isend));
	insert(0);
}
int main()
{
	read(n);
	init();
	for (int i = 1; i <= n; i++)
	{
		read(nums[i]);
		sum = sum ^ nums[i];
		insert(sum);
		tmp[i][0] = max(tmp[i - 1][0], find(sum));
	}
	init();
	for (int i = n; i >= 1; i--)
	{
		sum = sum ^ nums[i];
		insert(sum);
		tmp[i][1] = max(tmp[i + 1][1], find(sum));
	}
	for (int i = 1; i < n; i++)
	{
		ans = max(ans, tmp[i][0] + tmp[i + 1][1]);
	}
	write(ans);
	return 0;
}
