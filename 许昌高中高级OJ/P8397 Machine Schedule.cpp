#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    int n, m, k;
    int ans = 0;
    std::vector<int> e[MAXN];
    bool vis[MAXN];
    int match[MAXN];
    void init()
    {
        ans = 0;
        for (int i = 1; i < n; i++)
        {
            e[i].clear();
        }
        std::memset(match, 0, sizeof(match));
    }
    bool dfs(int u)
    {
        for (auto &v : e[u])
        {
            if (vis[v] == false)
            {
                vis[v] = true;
                if (match[v] == 0 || dfs(match[v]))
                {
                    match[v] = u;
                    return true;
                }
            }
        }
        return false;
    }
    int main()
    {
        while (scanf("%d%d%d", &n, &m, &k) != EOF && n != 0)
        {
            init();
            for (int i = 0; i < k; i++)
            {
                int u, v;
                scanf("%d%d%d", &i, &u, &v);
                if (u != 0 && v != 0)
                {
                    e[u].push_back(v);
                }
            }
            for (int i = 1; i < n; i++)
            {
                std::memset(vis, 0, sizeof(vis));
                if (dfs(i))
                {
                    ans++;
                }
            }
            printf("%d\n", ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}