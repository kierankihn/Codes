#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e4 + 5;
const int MAXM = 1e5 + 5;
int n, m;
int val[MAXN];
int x[MAXM], y[MAXM];

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
void init()
{
    for (auto &i : g)
    {
        i.clear();
    }
    edge.clear();
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
            cnt[color_tot] += val[tmp];
            tmp = s.top();
            s.pop();
            isinsta[tmp] = false;
        }
        color[tmp] = color_tot;
        cnt[color_tot] += val[tmp];
    }
}

int dp[MAXN];
int solve(int u)
{
    if (dp[u] != -1)
    {
        return dp[u];
    }
    int res = 0;
    for (auto &i : g[u])
    {
        Edge &e = edge[i];
        res = max(res, solve(e.to));
    }
    return dp[u] = res + cnt[u];
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> val[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> x[i] >> y[i];
        addEdge(x[i], y[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
        {
            tarjan(i);
        }
    }
    init();
    for (int i = 1; i <= m; i++)
    {
        if (color[x[i]] != color[y[i]])
        {
            addEdge(color[x[i]], color[y[i]]);
            // cout << x[i] << " " << y[i] << endl;
            // cout << color[x[i]] << " " << color[y[i]] << endl;
        }
    }
    int ans = -1;
    for (int i = 1; i <= color_tot; i++)
    {
        ans = max(ans, solve(i));
    }
    cout << ans << endl;
    return 0;
}