#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    const int MAXLOGN = 20 + 5;
    using std::printf;
    using std::scanf;
    int n, m, q;
    int ans = 0;
    int cas = 0;
    std::vector<int> e[MAXN];
    int tot;
    int fa[MAXN];
    bool bridge[MAXN];
    int dfn[MAXN], low[MAXN];
    void init()
    {
        tot = 0;
        ans = 0;
        std::memset(fa, 0, sizeof(fa));
        std::memset(dfn, 0, sizeof(dfn));
        std::memset(low, 0, sizeof(low));
        std::memset(bridge, 0, sizeof(bridge));
        for (int i = 1; i <= n; i++)
        {
            e[i].clear();
        }
    }
    void tarjan(int u, int father)
    {
        dfn[u] = ++tot, low[u] = dfn[u];
        for (auto &v : e[u])
        {
            if (v == father)
            {
                continue;
            }
            if (dfn[v] == 0)
            {
                fa[v] = u;
                tarjan(v, u);
                if (low[v] > dfn[u])
                {
                    ans++;
                    bridge[v] = true;
                }
                low[u] = std::min(low[u], low[v]);
            }
            else
            {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
    }
    void LCA(int x, int y)
    {
        if (dfn[x] < dfn[y])
        {
            std::swap(x, y);
        }
        while (dfn[x] > dfn[y])
        {
            if (bridge[x])
            {
                bridge[x] = false;
                ans--;
            }
            x = fa[x];
        }
        while (x != y)
        {
            if (bridge[y])
            {
                bridge[y] = false;
                ans--;
            }
            y = fa[y];
        }
    }
    int main()
    {
        while (scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0)
        {
            init();
            for (int i = 1; i <= m; i++)
            {
                int u, v;
                scanf("%d%d", &u, &v);
                e[u].push_back(v), e[v].push_back(u);
            }
            tarjan(1, 0);
            scanf("%d", &q);
            printf("Case %d:\n", ++cas);
            for (int i = 1; i <= q; i++)
            {
                int u, v;
                scanf("%d%d", &u, &v);
                LCA(u, v);
                printf("%d\n", ans);
            }
            printf("\n");
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}