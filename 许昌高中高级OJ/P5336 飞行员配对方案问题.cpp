#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 + 5;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from;
    int to;
    int dis;
    Edge(int u, int v, int d) : from(u), to(v), dis(d)
    {
    }
};
int n, m;
int ans = 0;
int color[MAXN];
int vis[MAXN];
int match[MAXN];
vector<Edge> edge;
vector<int> g[MAXN];
void add(int u, int v, int d)
{
    edge.push_back(Edge(u, v, d));
    g[u].push_back(edge.size() - 1);
}
int dfs(int x)
{
	for (auto & i : g[x])
	{
		Edge & e = edge[i];
		if (vis[e.to] == 0)
		{
			vis[e.to] = 1;
			if (!match[e.to] || dfs(match[e.to]))
			{
				match[e.to] = x;
				return 1;
			}
		}
	}
	return 0;
}
int main()
{
	int u, v;
	cin >> n >> m;
	while (cin >> u >> v)
	{
		if (u == -1 || v == -1)
		{
			break;
		}
		add(u, v, 1);
		add(v, u, 1);
		color[v] = 1;
	}
	for (int i = 1; i <= n; i++)
	{
		if (color[i] == 0)
		{
			memset(vis, 0, sizeof(vis));
			ans += dfs(i);
		}
	}
	cout << ans << endl;
	for (int i = 1; i <= n + m; i++)
	{
		if (color[i] == 1)
		{
			if (match[i] != 0)
			{
				cout << match[i] << " " << i << endl;
			}
		}
	}
	return 0;
}
