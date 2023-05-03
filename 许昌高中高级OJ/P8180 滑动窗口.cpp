#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
int n, k;
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
	memset(nums, 0, sizeof(nums));
	n = read<int>(), k = read<int>();
	for (int i = 1; i <= n; i++)
	{
		nums[i] = read<int>();
	}
	for (int i = 1; i <= n; i++)
	{
		while (!dl.empty() && dl.front() < i - k + 1)
		{
			dl.pop_front();
		}
		while (!dl.empty() && nums[dl.back()] >= nums[i])
		{
			dl.pop_back();
		}
		dl.push_back(i);
		if (i >= k)
		{
			write(nums[dl.front()]);
			putchar(' ');
		}
	}
	cout << endl;
	for (int i = 1; i <= n; i++)
	{
		while (!dl.empty() && dl.front() < i - k + 1)
		{
			dl.pop_front();
		}
		while (!dl.empty() && nums[dl.back()] <= nums[i])
		{
			dl.pop_back();
		}
		dl.push_back(i);
		if (i >= k)
		{
			write(nums[dl.front()]);
			putchar(' ');
		}
	}
	cout << endl;
	return 0;
}
