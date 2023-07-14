#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e4 + 5;
int n, m;
int ans = 0;

struct Edge
{
    int from, to;
    Edge(int u, int v) : from(u), to(v)
    {
    }
};
vector<Edge> edge;
vector<int> g[MAXN];
void addEdge(int u, int v)
{
    g[u].push_back(edge.size());
    edge.push_back(Edge(u, v));
}

int tot = 0;
int dfn[MAXN], low[MAXN];
bool cut[MAXN];
void tarjan(int u, int root)
{
    int cnt = 0;
    dfn[u] = low[u] = ++tot;
    for (auto &i : g[u])
    {
        Edge &e = edge[i];
        if (!dfn[e.to])
        {
            tarjan(e.to, root);
            low[u] = min(low[u], low[e.to]);
            if (low[e.to] >= dfn[u])
            {
                cnt++;
            }
        }
        else
        {
            low[u] = min(low[u], dfn[e.to]);
        }
    }
    if (u == root && cnt >= 2)
    {
        cut[u] = true;
    }
    if (u != root && cnt >= 1)
    {
        cut[u] = true;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v), addEdge(v, u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i, i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (cut[i])
        {
            ans++;
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        if (cut[i])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}