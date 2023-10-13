#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 500 + 5;
    int t;
    int n, m;
    LL ans = 0, sum = 1;
    std::vector<int> e[MAXN];
    int dfn_tot;
    bool cut[MAXN];
    int dfn[MAXN], low[MAXN], vis[MAXN];
    void init()
    {
        ans = 0, sum = 1, m = 0;
        std::memset(vis, 0, sizeof(vis));
        std::memset(cut, 0, sizeof(cut));
        std::memset(dfn, 0, sizeof(dfn));
        std::memset(low, 0, sizeof(low));
        for (int i = 1; i <= n; i++)
        {
            e[i].clear();
        }
    }
    void tarjan(int u, int fa)
    {
        int son = 0;
        dfn[u] = ++dfn_tot, low[u] = dfn[u];
        for (auto &v : e[u])
        {
            if (dfn[v] == 0)
            {
                tarjan(v, u);
                low[u] = std::min(low[u], low[v]);
                if (low[v] >= dfn[u])
                {
                    son++;
                }
            }
            else
            {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (fa == 0 && son >= 2)
        {
            cut[u] = true;
        }
        if (fa != 0 && son >= 1)
        {
            cut[u] = true;
        }
    }
    void dfs(int u, int &size, int &cnt)
    {
        size++, vis[u] = vis[0];
        for (auto &v : e[u])
        {
            if (cut[v] == true && vis[v] != vis[0])
            {
                cnt++, vis[v] = vis[0];
            }
            if (vis[v] == 0)
            {
                dfs(v, size, cnt);
            }
        }
    }
    int main()
    {
        while (scanf("%d", &n) != EOF && n != 0)
        {
            init();
            for (int i = 1; i <= n; i++)
            {
                int u, v;
                scanf("%d%d", &u, &v);
                e[u].push_back(v), e[v].push_back(u);
                m = std::max(m, u), m = std::max(m, v);
            }
            n = m;
            for (int i = 1; i <= n; i++)
            {
                if (dfn[i] == 0)
                {
                    tarjan(i, 0);
                }
            }
            for (int u = 1; u <= n; u++)
            {
                if (cut[u] == false && vis[u] == 0)
                {
                    vis[0]++;
                    int size = 0, cnt = 0;
                    dfs(u, size, cnt);
                    if (cnt == 0)
                    {
                        ans += 2, sum *= (size - 1) * size / 2;
                    }
                    if (cnt == 1)
                    {
                        ans += 1, sum *= size;
                    }
                }
            }
            if (ans == 0)
            {
                ans = 2, sum *= (n - 1) * n / 2;
            }
            printf("Case %d: %lld %lld\n", ++t, ans, sum);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}