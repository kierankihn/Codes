#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5 + 5;
int n;
int a[MAXN];

struct Edge
{
    int from, to;
    Edge(int u, int v)
        : from(u), to(v)
    {
    }
};
vector<Edge> edge;
vector<int> g[MAXN];
void addEdge(int u, int v)
{
    if (u == v)
    {
        return;
    }
    g[u].push_back(edge.size());
    edge.push_back(Edge(u, v));
}

int dfn_tot = 0, color_tot = 0;
int dfn[MAXN], low[MAXN], color[MAXN], cnt[MAXN];
bool isinsta[MAXN];
stack<int> s;
void tarjan(int u)
{
    dfn[u] = low[u] = ++dfn_tot;
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
            tarjan(e.to);
            low[u] = min(low[u], low[e.to]);
        }
    }
    if (low[u] == dfn[u])
    {
        color_tot++;
        int tmp = s.top();
        s.pop();
        isinsta[tmp] = false;
        while (tmp != u)
        {
            color[tmp] = color_tot;
            cnt[color_tot]++;
            tmp = s.top();
            s.pop();
            isinsta[tmp] = false;
        }
        color[tmp] = color_tot;
        cnt[color_tot]++;
    }
}

int sum[MAXN];

long long ans = 0;

void solve(int u, int fa)
{
    sum[u] = cnt[u] + sum[fa];
    ans = ans + (long long)cnt[u] * sum[u];

    for (auto e : g[u])
    {
        int v = edge[e].to;
        solve(v, u);
    }
}

int du[MAXN];

int main()
{
    std::cin >> n;
    for (int u = 1; u <= n; u++)
    {
        std::cin >> a[u];
        addEdge(a[u], u);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    for (auto &i : g)
    {
        i.clear();
    }
    edge.clear();
    for (int i = 1; i <= n; i++)
    {
        if (color[a[i]] != color[i])
        {
            addEdge(color[a[i]], color[i]);
            du[color[i]]++;
        }
    }

    for (int i = 1; i <= color_tot; i++)
    {
        if (du[i] == 0)
        {
            solve(i, 0);
        }
    }

    std::cout << ans << std::endl;
    return 0;
}