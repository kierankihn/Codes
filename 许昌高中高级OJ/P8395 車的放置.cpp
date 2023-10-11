#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 400 + 5;
    int n, m, t;
    int ans = 0;
    bool ban[MAXN][MAXN];
    std::vector<int> e[MAXN];
    int p[MAXN];
    bool vis[MAXN];
    bool dfs(int u)
    {
        for (auto &v : e[u])
        {
            if (vis[v] == false)
            {
                vis[v] = true;
                if (p[v] == 0 || dfs(p[v]))
                {
                    p[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int main()
    {
        scanf("%d%d%d", &n, &m, &t);
        for (int i = 1; i <= t; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            ban[u][v] = true;
        }
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= m; v++)
            {
                if (ban[u][v] == false)
                {
                    e[u].push_back(v + n);
                }
            }
        }
        for (int u = 1; u <= n; u++)
        {
            std::memset(vis, 0, sizeof(vis));
            if (dfs(u))
            {
                ans++;
            }
        }
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}