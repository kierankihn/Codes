#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 1e5 + 5;
int t, q, tot;
LL MOD;
int op[MAXN];
struct Node
{
	LL mul;
}node[MAXN << 2];
void build(int o, int l, int r)
{
	if (l == r)
	{
		node[o].mul = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(o * 2, l, mid), build(o * 2 + 1, mid + 1, r);
	node[o].mul = node[o * 2].mul * node[o * 2 + 1].mul;
}
void update(int o, int l, int r, int x, LL v)
{
	if (l == x && r == x)
	{
		node[o].mul = v;
		return;
	}
	int mid = (l + r) >> 1;
	if (mid >= x)
	{
		update(o * 2, l, mid, x, v);
	}
	if (mid < x)
	{
		update(o * 2 + 1, mid + 1, r, x, v);
	}
	node[o].mul = node[o * 2].mul * node[o * 2 + 1].mul % MOD;
}
LL query(int o, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr)
	{
		return node[o].mul;
	}
	LL ans = 1;
	int mid = (l + r) >> 1;
	if (mid >= ql)
	{
		ans = ans * query(o * 2, l, mid, ql, qr);
		ans = ans % MOD;
	}
	if (mid < qr)
	{
		ans = ans * query(o * 2 + 1, mid + 1, r, ql, qr);
		ans = ans % MOD;
	}
	return ans;
}
int main()
{
	cin >> t;
	while (t--)
	{
		cin >> q >> MOD;
		build(1, 1, q);
		tot = 0;
		for (int i = 1; i <= q; i++)
		{
			int opp;
			cin >> opp;
			cin >> op[++tot];
			if (opp == 1)
			{
				update(1, 1, q, tot, op[tot]);
			}
			if (opp == 2)
			{
				update(1, 1, q, op[tot], 1);
			}
			cout << query(1, 1, q, 1, q) << endl;
		}
	}
	return 0;
}
