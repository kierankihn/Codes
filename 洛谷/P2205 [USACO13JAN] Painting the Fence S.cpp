#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int MAXN = 1e5 + 5;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int n, k, m;
int tmp;
vector<LL> rev, input;
map<LL, int> mp;
LL read()
{
	char ch = getchar();
	LL x = 0, s = 1;
	while (ch > '9' || ch < '0')
	{
		if (ch == '-')
		{
			s = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * s;
}
void write(LL x)
{
	if (x < 0)
	{
		putchar('-');
		x = -x;
	}
	while (x)
	{
		putchar(x % 10 + '0'), x = x / 10;
	}
}
 
struct Node
{
	LL min;
	LL tag;
};
Node node[MAXN << 3];
void pushdown(int o, int l, int r)
{
	node[o * 2].min += node[o].tag, node[o * 2 + 1].min += node[o].tag;
	node[o * 2].tag += node[o].tag, node[o * 2 + 1].tag += node[o].tag;
	node[o].tag = 0;
}
void update(int o, int l, int r, int ql, int qr, LL v)
{
	if (ql <= l && r <= qr)
	{
		node[o].tag += v;
		node[o].min += v;
		return;
	}
	pushdown(o, l, r);
	int mid = (l + r) >> 1;
	if (mid >= ql)
	{
		update(o * 2, l, mid, ql, qr, v);
	}
	if (mid < qr)
	{
		update(o * 2 + 1, mid + 1, r, ql, qr, v);
	}
	node[o].min = min(node[o * 2].min, node[o * 2 + 1].min);
}
LL query(int o, int l, int r, int ql, int qr)
{
	if (ql <= l && r <= qr)
	{
		return node[o].min;
	}
	pushdown(o, l, r);
	int mid = (l + r) >> 1;
	LL ans = INF;
	if (mid >= ql)
	{
		ans = min(ans, query(o * 2, l, mid, ql, qr));
	}
	if (mid < qr)
	{
		ans = min(ans, query(o * 2 + 1, mid + 1, r, ql, qr));
	}
	return ans;
}
LL solve(int l, int r)
{
//	cout << rev[l] << " " << rev[r + 1] << " " << query(1, 0, m - 1, l, r) << " " << l << " " << r << endl;
	if (query(1, 0, m - 1, l, r) >= k)
	{
//		cout << rev[l] << " " << rev[r + 1] - 1 << endl;
		return rev[r + 1] - rev[l];
	}
	else
	{
		if (l == r)
		{
			return 0;
		}
		int mid = (l + r) >> 1;
		return solve(l, mid) + solve(mid + 1, r);
	}
}
 
int main()
{
	cin >> n >> k;
	rev.push_back(0), input.push_back(0);
	for (int i = 1; i <= n; i++)
	{
		char dire;
		LL tmpp = read();
		cin >> dire;
		if (dire == 'L')
		{
			tmpp = - tmpp;
		}
		tmp = tmp + tmpp;
		input.push_back(tmp), rev.push_back(tmp), rev.push_back(tmp - 1);
	}
	sort(rev.begin(), rev.end());
	m = unique(rev.begin(), rev.end()) - rev.begin();
	for (int i = 0; i < m; i++)
	{
		mp[rev[i]] = i;
	}
	for (int i = 1; i <= n; i++)
	{
		int a = input[i - 1], b = input[i];
		if (a > b)
		{
			swap(a, b);
		}
		update(1, 0, m - 1, mp[a], mp[b - 1], 1);
//		cout << "upd: " << a << " " << b - 1 << " " << mp[a] << " " << mp[b - 1] << endl;
	}
	cout << solve(0, m - 1) << endl;
	return 0;
}
