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
int n, m;
int s, t;
int vis[MAXN], pre[MAXN], incf[MAXN];
vector<int> g[MAXN];
vector<Edge> edge;
void add(int u, int v, int d)
{
    edge.push_back(Edge(u, v, d));
    g[u].push_back(edge.size() - 1);
    edge.push_back(Edge(v, u, 0));
    g[v].push_back(edge.size() - 1);
}
bool bfs()
{
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(s);
	incf[s] = INF;
	vis[s] = 1;
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (auto& i : g[u])
		{
			Edge& e = edge[i];
			if ((!vis[e.to]) && (e.dis))
			{
				vis[e.to] = 1, pre[e.to] = i, incf[e.to] = min(e.dis, incf[e.from]);
				q.push(e.to);
				if (e.to == t)
				{
					return true;
				}
			}
		}
	}
	return false;
}
int update()
{
	int u = t;
	while (u != s)
	{
		edge[pre[u]].dis -= incf[t];
		edge[pre[u] ^ 1].dis += incf[t];
		u = edge[pre[u]].from;
	}
	return incf[t];
}
int solve()
{
	int ans = 0;
	while (bfs())
	{
		ans += update();
	}
	return ans;
}
int main()
{
	cin >> n >> m >> s >> t;
	for (int i = 1; i <= m; i++)
	{
		int u, v, d;
		cin >> u >> v >> d;
		add(u, v, d);
	}
	cout << solve() << endl;
	return 0;
}
