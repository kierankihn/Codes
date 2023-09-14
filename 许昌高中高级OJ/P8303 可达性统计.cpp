#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 3e4 + 5;
    std::vector<int> g[MAXN];
    void addEdge(int u, int v)
    {
        g[u].push_back(v);
    }
    int n, m;
    std::bitset<MAXN> b[MAXN];
    void dfs(int u)
    {
        b[u][u] = 1;
        for (auto &v : g[u])
        {
            if (b[v][v] == 0)
            {
                dfs(v);
            }
            b[u] |= b[v];
        }
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            addEdge(u, v);
        }
        for (int u = 1; u <= n; u++)
        {
            if (b[u][u] == 0)
            {
                dfs(u);
            }
            std::printf("%ld\n", b[u].count());
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}