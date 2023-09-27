#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v)
    {
        g[u].push_back(v);
    }
    int n, m;
    int dp[MAXN];
    int price[MAXN];
    int minprice[MAXN];
    void dfs(int u, int fa)
    {
        bool flag = false;
        if (std::min(minprice[fa], price[u]) < minprice[u])
        {
            minprice[u] = std::min(minprice[fa], price[u]);
            flag = true;
        }
        if (std::max(dp[fa], price[u] - minprice[u]) > dp[u])
        {
            dp[u] = std::max(dp[fa], price[u] - minprice[u]);
            flag = true;
        }
        if (flag == false)
        {
            return;
        }
        for (auto &v : g[u])
        {
            dfs(v, u);
        }
    }
    int main()
    {
        std::memset(minprice, 0x3f, sizeof(minprice));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &price[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v, z;
            scanf("%d%d%d", &u, &v, &z);
            if (z == 1)
            {
                addEdge(u, v);
            }
            if (z == 2)
            {
                addEdge(u, v), addEdge(v, u);
            }
        }
        dfs(1, 0);
        printf("%d\n", dp[n]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}