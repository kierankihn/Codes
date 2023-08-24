#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1500;
struct Edge
{
	int from;
	int to;
	int dis;
	Edge(int u, int v, int d) : from(u), to(v), dis(d)
	{
		// nothing
	}
};
int n;
int root;
int vis[MAXN + 5];
int nums[MAXN + 5];
int dp[MAXN + 5][4];
vector<Edge> edge;
vector<int> g[MAXN + 5];
inline int readInt()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
		{
			f = -1;
		}
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}
inline void write(int x)
{
	if (x < 0)
	{
		putchar('-'), x = -x;
	}
	if (x > 9)
	{
		write(x / 10);
	}
	putchar(x % 10 + '0');
	return;
}
void add(int u, int v, int d)
{
	edge.push_back(Edge(u, v, d));
	g[u].push_back(edge.size() - 1);
}
int solve(int x, int k)
{
	if (dp[x][k] != 0x3f3f3f3f)
	{
		return dp[x][k];
	}
	dp[x][k] = 0;
	if (k == 1) // 被父亲看守
	{
		for (unsigned int i = 0; i < g[x].size(); i++)
		{
			int v = edge[g[x][i]].to;
			dp[x][k] += min(solve(v, 2), solve(v, 3));
		}
	}
	else if (k == 2) // 被儿子看守
	{
		int d = 0x3f3f3f3f;
		for (unsigned int i = 0; i < g[x].size(); i++)
		{
			int v = edge[g[x][i]].to;
			dp[x][k] += min(solve(v, 2), solve(v, 3));
			d = min(d, solve(v, 3) - min(solve(v, 3), solve(v, 2)));
		}
		dp[x][k] += d;
	}
	else if (k == 3) // 被自己看守
	{
		dp[x][k] += nums[x];
		for (unsigned int i = 0; i < g[x].size(); i++)
		{
			int v = edge[g[x][i]].to;
			dp[x][k] += min(min(solve(v, 1), solve(v, 2)), solve(v, 3));
		}
	}
	return dp[x][k];
}
int main()
{
	memset(dp, 0x3f, sizeof(dp));
	n = readInt();
	for (int i = 1; i <= n; i++)
	{
		int id, k;
		id = readInt(), nums[id] = readInt(), k = readInt();
		for (int j = 1; j <= k; j++)
		{
			int v = readInt();
			vis[v] = 1;
			add(id, v, 1);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (vis[i] == 0)
		{
			root = i;
			break;
		}
	}
	write(min(solve(root, 2), solve(root, 3)));
	putchar('\n');
	//	write(root);
	//	putchar('\n');
	//	for(int i=1;i<=n;i++)
	//	{
	//		write(solve(i,1));
	//		putchar(' ');
	//	}
	//	putchar('\n');
	//	for(int i=1;i<=n;i++)
	//	{
	//		write(solve(i,2));
	//		putchar(' ');
	//	}
	//	putchar('\n');
	//	for(int i=1;i<=n;i++)
	//	{
	//		write(solve(i,3));
	//		putchar(' ');
	//	}
	//	putchar('\n');
	return 0;
}
