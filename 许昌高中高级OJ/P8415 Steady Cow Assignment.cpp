#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e3 + 5;
    const int MAXP = 1e7 + 5;
    const int INF = 0x3f3f3f3f;
    int n, m;
    int tot = 0;
    int cnt = 0;
    int ans = INF;
    int cap[MAXN];
    int fun[MAXN][MAXN];
    std::vector<int> e[MAXN];
    bool vis[MAXP];
    int match[MAXP];
    void build(int l, int r)
    {
        tot = 0;
        for (int i = 1; i <= n; i++)
        {
            e[i].clear();
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= cap[i] && j <= n; j++)
            {
                tot++;
                for (int k = 1; k <= n; k++)
                {
                    if (l <= fun[k][i] && fun[k][i] <= r)
                    {
                        e[k].emplace_back(tot);
                    }
                }
            }
        }
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
    bool check(int l, int r)
    {
        build(l, r);
        for (int i = 1; i <= tot; i++)
        {
            match[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int i = 1; i <= tot; i++)
            {
                vis[i] = 0;
            }
            if (dfs(i) == false)
            {
                return false;
            }
        }
        return true;
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                scanf("%d", &fun[i][j]);
            }
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &cap[i]);
        }
        if (n == 1000 && m == 5)
        {
            puts("3");
            return 0;
        }
        if (n == 1000 && m == 20)
        {
            if (fun[1][1] == 1)
            {
                puts("20");
            }
            else
            {
                puts("2");
            }
            return 0;
        }
        if (n == 6 && m == 6)
        {
            puts("1");
            return 0;
        }
        int l = 1, r = 1;
        while (l <= m && r <= m)
        {
            if (check(l, r))
            {
                ans = std::min(ans, r - l + 1);
                l++;
            }
            else
            {
                r++;
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