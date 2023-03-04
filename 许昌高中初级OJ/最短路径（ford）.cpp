#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100;
const int INF = 0x3f3f3f3f;
int n, m;
int s, t;
vector<struct Edge> edge;
vector<int> g[MAXN + 5];
queue<int> q;
double d[MAXN + 5];
int vis[MAXN + 5];
int pos[MAXN + 5][3];
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
void add(int u, int v, double d)
{
    edge.push_back(Edge(u, v, d));
    edge.push_back(Edge(v, u, d));
    g[u].push_back(edge.size() - 2);
    g[v].push_back(edge.size() - 1);
}
int main()
{
    cin >> n;
    memset(d, 0x7f, sizeof(d));
    for (int i = 1; i <= n; i++)
    {
        cin >> pos[i][1] >> pos[i][2];
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v, sqrt(pow(pos[u][1]-pos[v][1],2)+pow(pos[u][2]-pos[v][2],2)));
    }
    cin >> s >> t;
    q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!q.empty())
    {
        int u;
        u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = 0; i < g[u].size(); i++)
        {
            Edge &e = edge[g[u][i]];
            if (d[u] < INF && d[e.to] > d[u] + e.dis)
            {
                d[e.to] = d[u] + e.dis;
                if(!vis[e.to])
                {
                    q.push(e.to);
                    vis[e.to] = 1;
                }
            }
        }
    }
    cout << fixed << setprecision(2) << d[t] << endl;
    return 0;
}