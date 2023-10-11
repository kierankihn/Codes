#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1000 + 5;
    int t;
    int n, m;
    std::vector<int> e[MAXN], ee[MAXN];
    int color_tot, dfn_tot, cnt;
    int dfn[MAXN], low[MAXN], color[MAXN], du[MAXN];
    bool isinsta[MAXN], vis[MAXN];
    std::stack<int> s;
    void init()
    {
        for (int u = 1; u <= n; u++)
        {
            e[u].clear(), ee[u].clear();
        }
        color_tot = dfn_tot = cnt = 0;
        std::memset(du, 0, sizeof(du));
        std::memset(vis, 0, sizeof(vis));
        std::memset(dfn, 0, sizeof(dfn));
        std::memset(low, 0, sizeof(low));
        std::memset(color, 0, sizeof(color));
    }
    void push(int x)
    {
        isinsta[x] = true, s.push(x);
    }
    int pop()
    {
        int x = s.top();
        isinsta[x] = false, s.pop();
        return x;
    }
    void tarjan(int u)
    {
        push(u), dfn[u] = ++dfn_tot, low[u] = dfn[u];
        for (auto &v : e[u])
        {
            if (dfn[v] != 0 && isinsta[v] == true)
            {
                low[u] = std::min(low[u], low[v]);
            }
            if (dfn[v] == 0)
            {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            }
        }
        if (low[u] == dfn[u])
        {
            color_tot++;
            while (s.top() != u)
            {
                color[pop()] = color_tot;
            }
            color[pop()] = color_tot;
        }
    }
    void dfs(int u)
    {
        vis[u] = true;
        if (ee[u].empty())
        {
            return;
        }
        dfs(ee[u][0]);
    }
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d%d", &n, &m);
            init();
            for (int i = 1; i <= m; i++)
            {
                int u, v;
                scanf("%d%d", &u, &v);
                e[u].push_back(v);
            }
            for (int u = 1; u <= n; u++)
            {
                if (dfn[u] == 0)
                {
                    tarjan(u);
                }
            }
            for (int u = 1; u <= n; u++)
            {
                for (auto &v : e[u])
                {
                    if (color[u] != color[v])
                    {
                        ee[color[u]].push_back(color[v]), du[color[v]]++;
                    }
                }
            }
            for (int u = 1; u <= color_tot; u++)
            {
                if (du[u] == 0)
                {
                    dfs(u);
                    break;
                }
            }
            for (int u = 1; u <= color_tot; u++)
            {
                if (vis[u])
                {
                    cnt++;
                }
            }
            if (cnt == color_tot)
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}