#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100 + 5;
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
int n;
int s, t;
int vis[MAXN];
vector<int> g[MAXN];
vector<Edge> edge;
void add(int u, int v, int d)
{
    edge.push_back(Edge(u, v, d));
    g[u].push_back(edge.size() - 1);
    edge.push_back(Edge(v, u, 0));
    g[v].push_back(edge.size() - 1);
}
int dfs(int p, int flow)
{
	if (p == t)
	{
		return flow;
	}
	vis[p] = true;
	for (auto& i : g[p])
	{
		int c;
		Edge& e = edge[i];
		if (e.dis > 0 && !(vis[e.to]) && ((c = dfs(e.to, min(e.dis, flow))) != -1))
		{
			edge[i].dis -= c;
			edge[i ^ 1].dis += c;
			return c;
		}
	}
	return -1;
}
int solve()
{
	int ans = 0, c = 0;
	while ((c = dfs(s, INF)) != -1)
	{
		memset(vis, 0, sizeof(vis));
		ans += c;
	}
	return ans;
}
int main()
{
	
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			int d;
			cin >> d;
			if (d)
			{
				add(i, j, d);
			}
		}
	}
	s = 1, t = n;
	cout << solve() << endl;
	return 0;
}
