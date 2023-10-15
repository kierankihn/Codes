#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 200 + 5;
    int n, m;
    int ans = 0;
    bool vis[MAXN];
    int match[MAXN];
    bool mp[MAXN][MAXN];
    bool dfs(int u)
    {
        for (int v = 1; v <= n; v++)
        {
            if (mp[u][v] == true && vis[v] == false)
            {
                vis[v] = true;
                if (match[v] == 0 || dfs(match[v]) == true)
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
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            mp[u][v] = true;
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    mp[i][j] = mp[i][j] | (mp[i][k] & mp[k][j]);
                }
            }
        }
        ans = n;
        for (int i = 1; i <= n; i++)
        {
            std::memset(vis, 0, sizeof(vis));
            if (dfs(i))
            {
                ans--;
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