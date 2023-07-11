#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
int n, m;

// 链式前向星
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

// Tarjan
int dfn_tot = 0, color_tot = 0;
int vis[MAXN];
int dfn[MAXN];
int low[MAXN];
int color[MAXN];
int isinsta[MAXN];
vector<int> ans[MAXN];
int isoutput[MAXN];
stack<int> s;
void Tarjan(int u)
{
    dfn_tot++;
    low[u] = dfn[u] = dfn_tot;
    s.push(u);
    isinsta[u] = true;
    for (auto &i : g[u])
    {
        Edge &e = edge[i];
        if (dfn[e.to] && isinsta[e.to])
        {
            low[u] = min(low[u], low[e.to]);
        }
        if (!dfn[e.to])
        {
            Tarjan(e.to);
            low[u] = min(low[u], low[e.to]);
        }
    }
    if (low[u] == dfn[u])
    {
        int tmp = s.top();
        s.pop();
        isinsta[tmp] = false;
        color_tot++;
        while (tmp != u)
        {
            color[tmp] = color_tot;
            ans[color_tot].push_back(tmp);
            tmp = s.top();
            s.pop();
            isinsta[tmp] = false;
        }
        color[tmp] = color_tot;
        ans[color_tot].push_back(tmp);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u == v)
        {
            continue;
        }
        addEdge(u, v);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            Tarjan(i);
        }
    }
    cout << color_tot << endl;
    for (int i = 1; i <= n; i++)
    {
        int c = color[i];
        if (!isoutput[c])
        {
            sort(ans[c].begin(), ans[c].end());
            for (auto &j : ans[c])
            {
                cout << j << " ";
            }
            cout << endl;
            isoutput[c] = true;
        }
    }
    return 0;
}