#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 2e3 + 5;
    int n;
    int x[MAXN];
    int sum[MAXN];
    std::vector<int> e[MAXN];
    int dfs(int u)
    {
        std::vector<int> dp(x[u] + 5);
        dp[0] = true;
        for (auto v : e[u])
        {
            sum[u] += dfs(v);
            for (int j = x[u]; j >= 0; j--)
            {
                if (j >= x[v] && j >= sum[v] - x[v])
                {
                    dp[j] = dp[j - x[v]] | dp[j - (sum[v] - x[v])];
                }
                else if (j >= x[v])
                {
                    dp[j] = dp[j - x[v]];
                }
                else if (j >= sum[v] - x[v])
                {
                    dp[j] = dp[j - (sum[v] - x[v])];
                }
                else
                {
                    dp[j] = false;
                }
            }
        }
        for (int i = x[u]; i >= 0; i--)
        {
            if (dp[i] == true)
            {
                return sum[u] += x[u] - i;
            }
        }
        puts("IMPOSSIBLE");
        exit(0);
    }
    int main()
    {
        scanf("%d", &n);
        for (int v = 2; v <= n; v++)
        {
            int u;
            scanf("%d", &u);
            e[u].push_back(v);
        }
        for (int u = 1; u <= n; u++)
        {
            scanf("%d", &x[u]);
        }
        dfs(1);
        puts("POSSIBLE");
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}