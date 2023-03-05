#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAXN = 500;
const int MAXM = 1000;
int n, m;
int vis[MAXM];
vector<int> g[MAXN + 5];
int lowcost[MAXN + 5][MAXN + 5];
struct Edge
{
    int from;
    int to;
    int dis;
    Edge()
    {
        // nothing
    }
    Edge(int u, int v, int d) : from(u), to(v), dis(d)
    {
        // nothing
    }
};
vector<Edge> edge;
void add(int u, int v, int d)
{
    edge.push_back(Edge(u, v, d));
    g[u].push_back(edge.size() - 1);
    edge.push_back(Edge(v, u, d));
    g[v].push_back(edge.size() - 1);
}
int main()
{
    memset(lowcost, 0x3f, sizeof(lowcost));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        add(u, v, d);
    }
    return 0;
}