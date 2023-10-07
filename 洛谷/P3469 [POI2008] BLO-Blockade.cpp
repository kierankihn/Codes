#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    using std::printf;
    using std::scanf;
    int n, m;
    LL ans[MAXN];
    std::vector<int> e[MAXN];
    void addEdge(int u, int v)
    {
        e[u].push_back(v);
    }
    int tot = 0;
    int low[MAXN], dfn[MAXN], size[MAXN];
    void tarjan(int u)
    {
        LL sum = 0;
        size[u] = 1, dfn[u] = ++tot, low[u] = dfn[u];
        for (auto &v : e[u])
        {
            if (dfn[v] == 0)
            {
                tarjan(v);
                size[u] += size[v];
                if (low[v] >= dfn[u])
                {
                    ans[u] += size[v] * sum;
                    sum += size[v];
                }
                low[u] = std::min(low[u], low[v]);
            }
            else
            {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        ans[u] += sum * (n - sum - 1);
        ans[u] += n - 1;
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v), addEdge(v, u);
        }
        tarjan(1);
        for (int i = 1; i <= n; i++)
        {
            printf("%lld\n", ans[i] * 2);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}