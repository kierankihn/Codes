#include <bits/stdc++.h>
using namespace std;
const int MAXN = 800;
const int INF = 0x3f3f3f3f;
int n, m, p;
int ans = 0x3f3f3f3f;
int cow[MAXN + 5];
int vis[MAXN + 5];
int dis[MAXN + 5];
struct Edge
{
    int from;
    int to;
    double dis;
    Edge(int u, int v, double d) : from(u), to(v), dis(d)
    {
        // nothing
    }
};
vector<Edge> edge;
vector<int> g[MAXN + 5];
void add(int u, int v, double d)
{
    edge.push_back(Edge(u, v, d));
    edge.push_back(Edge(v, u, d));
    g[u].push_back(edge.size() - 2);
    g[v].push_back(edge.size() - 1);
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> p >> n >> m;
    for (int i = 1; i <= p; i++)
    {
        int pos;
        cin >> pos;
        cow[pos]++;
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        add(u, v, d);
    }
    for (int k = 1; k <= n; k++)
    {
        int res = 0;
        memset(vis, 0, sizeof(vis));
        memset(dis, 0x3f, sizeof(dis));
        queue<int> q;
        q.push(k);
        vis[k] = 1;
        dis[k] = 0;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for (int i = 0; i < g[u].size(); i++)
            {
                Edge &e = edge[g[u][i]];
                if (dis[u] < INF && e.dis + dis[u] < dis[e.to])
                {
                    dis[e.to] = e.dis + dis[u];
                    if (!vis[e.to])
                    {
                        vis[e.to] = 1;
                        q.push(e.to);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            res += dis[i] * cow[i];
        }
        ans = min(ans, res);
    }
    cout << ans << endl;
    return 0;
}