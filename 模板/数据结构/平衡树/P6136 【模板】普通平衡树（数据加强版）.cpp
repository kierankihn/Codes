#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f3f;
const int MAXN = 1e6 + 1e5 + 5;
int n, m;
int ans;
LL readInt()
{
	LL x = 0, s = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
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
		putchar('-'), x = -x;
	}
	while (x)
	{
		putchar(x % 10 + '0'), x = x / 10;
	}
}
struct Node
{
	int ls, rs;
	int val, p;
	int sz;
	int count;
	Node()
	{
		
	}
	Node(int val_) : ls(0), rs(0), val(val_), p(rand()), sz(1), count(1)
	{
		
	}
	Node(int val_, int p_) : ls(0), rs(0), val(val_), p(p_), sz(1), count(1)
	{
		
	}
};
Node node[MAXN];
int root = 0;
int tot = 0;
void zig(int &x) // 右旋
{
	int y = node[x].ls;
	node[x].ls = node[y].rs;
	node[y].rs = x;
	node[y].sz = node[x].sz;
	node[x].sz = node[node[x].ls].sz + node[node[x].rs].sz + node[x].count;
	x = y;
}
void zag(int &x) // 左旋
{
	int y = node[x].rs;
	node[x].rs = node[y].ls;
	node[y].ls = x;
	node[y].sz = node[x].sz;
	node[x].sz = node[node[x].ls].sz + node[node[x].rs].sz + node[x].count;
	x = y;
}
void insert(int &x, int vn)
{
	if (!x)
	{
		x = ++tot;
		node[x] = Node(vn);
		return;
	}
	node[x].sz++;
	if (vn == node[x].val)
	{
		node[x].count++;
		return;
	}
	if (vn < node[x].val)
	{
		insert(node[x].ls, vn);
		if (node[node[x].ls].p > node[x].p)
		{
			zig(x);
		}
	}
	if (vn > node[x].val)
	{
		insert(node[x].rs, vn);
		if (node[node[x].rs].p > node[x].p)
		{
			zag(x);
		}
	}
}
void remove(int &x, int vd)
{
	if (node[x].val == vd)
	{
		if (node[x].count > 1)
		{
			node[x].count--;
			node[x].sz--;
			return;
		}
		else if ((!node[x].ls) || (!node[x].rs))
		{
			x = node[x].ls + node[x].rs;
		}
		else if (node[node[x].ls].p >= node[node[x].rs].p)
		{
			zig(x);
			remove(x, vd);
		}
		else if (node[node[x].ls].p < node[node[x].rs].p)
		{
			zag(x);
			remove(x, vd);
		}
		return;
	}
	node[x].sz--;
	if (vd < node[x].val)
	{
		remove(node[x].ls, vd);
	}
	if (vd > node[x].val)
	{
		remove(node[x].rs, vd);
	}
}
int queryRank(int v)
{
	int x = root, res = 0;
	while (x)
	{
		if (v == node[x].val)
		{
			return res + node[node[x].ls].sz + 1;
		}
		else if (v < node[x].val)
		{
			x = node[x].ls;
		}
		else if (v > node[x].val)
		{
			res += node[node[x].ls].sz + node[x].count;
			x = node[x].rs;
		}
	}
	return res + 1;
}
int queryKth(int k)
{
	int x = root;
	while (x)
	{
		if (node[node[x].ls].sz < k && k <= node[node[x].ls].sz + node[x].count)
		{
			return node[x].val;
		}
		else if (node[node[x].ls].sz >= k)
		{
			x = node[x].ls;
		}
		else if (node[node[x].ls].sz + node[x].count < k)
		{
			k -= node[node[x].ls].sz + node[x].count;
			x = node[x].rs;
		}
	}
	return INF;
}
int queryPre(int v)
{
	int x = root, res = INF;
	while (x)
	{
		if (node[x].val < v)
		{
			res = node[x].val;
			x = node[x].rs;
		}
		else
		{
			x = node[x].ls;
		}
	}
	return res;
}
int queryNxt(int v)
{
	int x = root, res = INF;
	while (x)
	{
		if (node[x].val > v)
		{
			res = node[x].val;
			x = node[x].ls;
		}
		else
		{
			x = node[x].rs;
		}
	}
	return res;
}
void dfs(int u)
{
	if (!u)
	{
		return;
	}
	cout << "dfs node " << u << " : count = " << node[u].count << ", ls = " << node[u].ls << ", rs = " << node[u].rs << ", p = " << node[u].p << ", val = " << node[u].val << ", sz = " << node[u].sz << endl;
	dfs(node[u].ls);
	dfs(node[u].rs);
}
int main()
{
	memset(node, 0, sizeof(node));
	srand(time(NULL));
	n = readInt(), m = readInt();
	for (int i = 1; i <= n; i++)
	{
		LL tmp;
		tmp = readInt();
		insert(root, tmp);
	}
	int last = 0;
	for (int i = 1; i <= m; i++)
	{
		int k, x;
		k = readInt(), x = readInt();
		switch(k)
		{
			case 1 : insert(root, x ^ last); break;
			case 2 : remove(root, x ^ last); break;
			case 3 : last = queryRank(x ^ last); ans = ans ^ last; break;
			case 4 : last = queryKth(x ^ last); ans = ans ^ last; break;
			case 5 : last = queryPre(x ^ last); ans = ans ^ last; break;
			case 6 : last = queryNxt(x ^ last); ans = ans ^ last; break;
		}
//		dfs(root);
	}
	cout << ans << endl;
	return 0;
}
