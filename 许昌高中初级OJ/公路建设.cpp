#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 500;
const int MAXM = 1000;
int n, m;
double vis[MAXN + 5];
int pos[MAXN + 5];
vector<int> g[MAXN + 5];
int lowcost[MAXN + 5][MAXN + 5];
struct Edge
{
    int from;
    int to;
    bool vis;
    double dis;
    Edge()
    {
        // nothing
    }
    Edge(int u, int v, double d, bool vi) : from(u), to(v), dis(d), vis(vi)
    {
        // nothing
    }
};
vector<Edge> edge;
void add(int u, int v, double d)
{
    edge.push_back(Edge(u, v, d, true));
    g[u].push_back(edge.size() - 1);
    edge.push_back(Edge(v, u, d, true));
    g[v].push_back(edge.size() - 1);
}
int bfs(int u, int v)
{
    memset(vis, -1, sizeof(vis));
    int maxlen = 0;
    queue<int> q;
    q.push(u);
    vis[u] = 0;
    while (!q.empty())
    {
        int fr = q.front();
        q.pop();
        for (int i = 0; i < g[fr].size(); i++)
        {
            Edge &e = edge[g[fr][i]];
            if (e.vis == false)
            {
                continue;
            }
            if (vis[e.to] < max(e.dis, vis[e.from]))
            {
                vis[e.to] = max(e.dis, vis[e.from]);
                if (e.dis > vis[e.from])
                {
                    pos[e.to] = g[fr][i];
                }
                else
                {
                    pos[e.to] = pos[e.from];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == -1)
        {
            return 0;
        }
    }
    edge[pos[v]].vis = false;
    return 1;
}
int main()
{
    memset(lowcost, 0x3f, sizeof(lowcost));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        add(u, v, (double)d * 0.5);
        if (bfs(u, v))
        {
            double cnt = 0;
            for (int i = 0; i < edge.size(); i++)
            {
                if (edge[i].vis)
                {
                    cnt += edge[i].dis;
                }
            }
            cout << fixed << setprecision(2) << cnt << " ";
            for (int i = 0; i < edge.size(); i++)
            {
                if (edge[i].vis)
                {
                    cout << i << " ";
                }
            }
            cout << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}