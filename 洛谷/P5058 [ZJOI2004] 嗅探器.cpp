#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n;
int a, b;

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

bool cut[MAXN];
int dfn[MAXN], low[MAXN], tot = 0;
void tarjan(int u, int root)
{
    dfn[u] = low[u] = ++tot;
    for (int &i : g[u])
    {
        Edge &e = edge[i];
        if (dfn[e.to])
        {
            low[u] = min(low[u], dfn[e.to]);
        }
        if (!dfn[e.to])
        {
            tarjan(e.to, root);
            low[u] = min(low[u], low[e.to]);
            if (u != root && dfn[u] <= low[e.to])
            {
                if (dfn[b] >= dfn[e.to])
                {
                    cut[u] = true;
                }
            }
        }
    }
}

int main()
{
    cin >> n;
    int u, v;
    while (cin >> u >> v && u && v)
    {
        addEdge(u, v), addEdge(v, u);
    }
    cin >> a >> b;
    tarjan(a, a);
    for (int i = 1; i <= n; i++)
    {
        if (cut[i])
        {
            cout << i << endl;
            return 0;
        }
    }
    cout << "No solution" << endl;
    return 0;
}