#include <bits/stdc++.h>
using namespace std;
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
	int n;
	n = read<int>();
	for (int i = 1; i <= n; i++)
	{
		int x;
		x = read<int>();
		write(x);
		putchar('\n');
	}
	return 0;
}
