#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5e3 + 5;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, dis;
    Edge(int u, int v, int d) : from(u), to(v), dis(d)
    {

    }
};
vector<Edge> edge;
vector<int> g[MAXN];
int n, m;
int vis[MAXN];
int dist[MAXN];
int isinque[MAXN];
void add(int u, int v, int d)
{
    g[u].push_back(edge.size());
    edge.push_back(Edge(u, v, d));
}
bool SPFA()
{
    queue<int> q;
    q.push(0);
    vis[0]++;
    dist[0] = 0;
    isinque[0] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        isinque[u] = false;
        for (auto &i : g[u])
        {
            Edge &e = edge[i];
            if (dist[e.to] > dist[e.from] + e.dis)
            {
                dist[e.to] = dist[e.from] + e.dis;
                if (!isinque[e.to])
                {
                    vis[e.to]++;
                    if (vis[e.to] >= n + 1)
                    {
                        return false;
                    }
                    q.push(e.to);
                    isinque[e.to] = true;
                }
            }
        }
    }
    return true;
}
int main()
{
    memset(dist, 0x3f, sizeof(dist));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        add(v, u, d);
    }
    for (int i = 1; i <= n; i++)
    {
        add(0, i, 0);
    }
    if (SPFA())
    {
        int mind = INF;
        for (int i = 1; i <= n; i++)
        {
            mind = min(mind, dist[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            cout << dist[i] - mind << " ";
        }
        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}