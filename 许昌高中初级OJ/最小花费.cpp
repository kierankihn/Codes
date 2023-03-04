#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2000;
int INF;
typedef struct Edge Edge;
struct Edge
{
    int from;
    int to;
    double dis;
    Edge(int u, int v, double d) : from(u), to(v), dis(d)
    {
        // noting
    }
};
int n, m;
int a, b;
double ans;
double dis[MAXN + 5];
int vis[MAXN + 5];
queue<int> q;
vector<int> g[MAXN + 5];
vector<Edge> edge;
void add(int u, int v, double d)
{
    edge.push_back(Edge(u, v, d));
    g[u].push_back(edge.size() - 1);
    edge.push_back(Edge(v, u, d));
    g[v].push_back(edge.size() - 1);
}
int main()
{
    memset(dis, 0x3f, sizeof(dis));
    INF = dis[0];
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        add(u, v, 1 - 0.01*d);
    }
    cin >> a >> b;
    dis[a] = 1;
    q.push(a);
    vis[a] = 1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = 0; i < g[u].size(); i++)
        {
            Edge &e = edge[g[u][i]];
            if (dis[u] > INF && dis[u] * e.dis > dis[e.to])
            {
                dis[e.to] = dis[u] * e.dis;
                if (!vis[e.to])
                {
                    vis[e.to] = 1;
                    q.push(e.to);
                }
            }
        }
    }
    ans = 100 / dis[b];
    // cout << dis[b] << endl;
    // for (int i = 0; i < edge.size(); i++)
    // {
    //     cout << edge[i].from << "\t" << edge[i].to << "\t" << edge[i].dis << endl;
    // }
    // for (int i = 1; i <= n; i++)
    // {
    //     cout << dis[i] << endl;
    // }
    cout << fixed << setprecision(8) << ans << endl;
    return 0;
}