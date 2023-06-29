#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 5;
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
int vis[MAXN];
vector<Edge> edge;
vector<int> g[MAXN];
void add(int u, int v, int d)
{
    edge.push_back(Edge(u, v, d));
    g[u].push_back(edge.size() - 1);
//    int k = edge.size() - 1;
//    cout << "get edge " << edge[k].from << " " << edge[k].to << " " << edge[k].dis << " " << *(g[u].end() - 1) << endl;
}
bool dfs(int p, int x)
{
//	cout << "dfs(" << p << "," << x << ")"<< endl;
	for (auto & i : g[p])
	{
		Edge & e = edge[i];
//		cout << "Edge:" << i << " " << p << " " << e.from << " " << e.to << " " << e.dis << endl;
		if (e.dis < x)
		{
			continue;
		}
		if (vis[e.to])
		{
			if (vis[e.to] == vis[p])
			{
//				cout << e.to << " " << vis[e.to] << " " << p << " " << vis[p] << endl;
				return false;
			}
		}
		else
		{
			vis[e.to] = 3 - vis[p];
			if (!dfs(e.to, x))
			{
				return false;
			}
		}
	}
	return true;
}
bool check(int x)
{
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
	{
//		cout << i << endl;
		if (!vis[i] && (vis[i] = 1) && !dfs(i, x))
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int l = 0, r = -1;
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		add(u, v, d);
		add(v, u ,d);
		r = max (r, d + 1);
	}
	while (l + 1 < r)
	{
		int mid = (l + r) >> 1;
		if (check(mid))
		{
			r = mid;
		}
		else
		{
			l = mid;
		}
	}
	cout << l << endl;
	return 0;
}
