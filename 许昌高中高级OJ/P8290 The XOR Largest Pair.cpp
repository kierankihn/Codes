#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 2;
const int MAXL = 32 + 1;
int n;
int ans = -1;
int tot = 0;
int k;
int ch[MAXN * MAXL][MAXM];
bool isend[MAXN * MAXL];
void init()
{
	ans = false;
	tot = 0;
	memset(ch, 0, sizeof(ch));
	memset(isend, 0, sizeof(isend));
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
int main()
{
	cin >> n;
	init();
	for (int i = 1; i <= n; i++)
	{
		cin >> k;
		insert(k);
		ans = max(ans, find(k));
	}
	cout << ans << endl;
	return 0;
}
