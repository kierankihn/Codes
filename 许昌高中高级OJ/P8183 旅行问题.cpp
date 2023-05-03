#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
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
long long n;
long long p[MAXN], d[MAXN];
long long nums[MAXN * 2];
long long sum[MAXN * 2];
bool isok[MAXN * 2];
deque<int> q;
int main()
{
	memset(isok, 0, sizeof(isok));
	n = read<int>();
	for (int i = 1; i <= n; i++)
	{
		p[i] = read<long long>();
		d[i] = read<long long>();
		nums[i] = p[i] - d[i];
		sum[i]= sum[i - 1] + nums[i];
	}
	for (int i = 1; i <= n; i++)
	{
		nums[i + n] = nums[i];
		sum[i + n] = sum[i + n - 1] + nums[i + n];
	}
	q.push_back(0);
	for (int i = 1; i < 2 * n; i++)
	{
		while (!q.empty() && q.front() < i - n + 1)
		{
			q.pop_front();
		}
		while (!q.empty() && sum[q.back()] >= sum[i])
		{
			q.pop_back();
		}
		q.push_back(i);
		if (i >= n)
		{
			if (sum[q.front()] >= sum[i - n])
			{
				isok[i - n + 1] = isok[i - n + 1] || true;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		nums[i] = p[i] - d[i - 1];
	}
	nums[1] = p[1] - d[n];
	for (int i = 1; i <= n; i++)
	{
		nums[i + n] = nums[i];
	}
	for (int i = 2 * n; i >= 1; i--)
	{
		sum[i] = sum[i + 1] + nums[i];
	}
	q.clear();
	q.push_back(2 * n + 1);
	for (int i = 2 * n; i > 1; i--)
	{
		while (!q.empty() && q.front() > i + n - 1)
		{
			q.pop_front();
		}
		while (!q.empty() && sum[q.back()] >= sum[i])
		{
			q.pop_back();
		}
		q.push_back(i);
		if (i <= n + 1)
		{
			if (sum[q.front()] >= sum[i + n])
			{
				isok[i - 1] = isok[i - 1] || true;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (isok[i])
		{
			cout << "TAK\n";
		}
		else
		{
			cout << "NIE\n";
		}
	}
	return 0;
}
