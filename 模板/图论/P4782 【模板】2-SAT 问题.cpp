#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 * 2 + 5;
int n, m;
int val[MAXN];

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

int color_cnt = 0, dfn_cnt = 0;
int color[MAXN], dfn[MAXN], low[MAXN], vis[MAXN];
stack<int> s;
void tarjan(int u)
{
    dfn[u] = low[u] = ++dfn_cnt;
    vis[u] = true;
    s.push(u);
    for (auto &i : g[u])
    {
        Edge &e = edge[i];
        if (dfn[e.to] && vis[e.to])
        {
            low[u] = min(low[u], low[e.to]);
        }
        if (!dfn[e.to])
        {
            tarjan(e.to);
            low[u] = min(low[u], low[e.to]);
        }
    }
    if (low[u] == dfn[u])
    {
        int tmp = s.top();
        s.pop();
        vis[tmp] = false;
        color_cnt++;
        while (tmp != u)
        {
            color[tmp] = color_cnt;
            tmp = s.top();
            s.pop();
            vis[tmp] = false;
        }
        color[tmp] = color_cnt;
    }
}

int main()
{
    memset(val, -1, sizeof(val));
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, a, b;
        cin >> u >> a >> v >> b;
        addEdge(u * 2 + (a ^ 1), v * 2 + b);
        addEdge(v * 2 + (b ^ 1), u * 2 + a);
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (color[i * 2] == color[i * 2 + 1])
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        val[i] = color[i * 2] > color[i * 2 + 1];
    }
    cout << "POSSIBLE" << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << val[i] << " ";
    }
    cout << endl;
    return 0;
}