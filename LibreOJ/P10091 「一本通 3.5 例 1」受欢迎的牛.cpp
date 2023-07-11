#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
int n, m;
int degree[MAXN];

// 链式前向星
struct Edge
{
    int from, to;
    Edge(int u, int v) : from(u), to(v)
    {
    }
};
vector<int> g[MAXN];
vector<Edge> edge;
void addEdge(int u, int v)
{
    g[u].push_back(edge.size());
    edge.push_back(Edge(u, v));
}

// Tarjan 缩点
int cnt[MAXN], color[MAXN], cntt = 0;
int dfn[MAXN], low[MAXN], tot = 0, vis[MAXN];
stack<int> s;
void tarjan(int u)
{
    low[u] = dfn[u] = ++tot;
    s.push(u);
    for (auto &i : g[u])
    {
        Edge &e = edge[i];
        if (dfn[e.to])
        {
            low[u] = min(low[u], low[e.to]);
        }
        else
        {
            tarjan(e.to);
            low[u] = min(low[u], low[e.to]);
        }
    }
    if (low[u] == dfn[u])
    {
        cntt++;
        int tmp = s.top();
        s.pop();
        while (tmp != u)
        {
            color[tmp] = cntt;
            cnt[cntt]++;
            tmp = s.top();
            s.pop();
        }
        color[tmp] = cntt;
        cnt[cntt]++;
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        addEdge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (auto &j : g[i])
        {
            Edge &e = edge[j];
            if (color[i] != color[e.to])
            {
                degree[color[i]]++;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= cntt; i++)
    {
        if (degree[i] == 0)
        {
            if (ans)
            {
                ans = 0;
                break;
            }
            ans = cnt[i];
        }
    }
    cout << ans << endl;
    return 0;
}