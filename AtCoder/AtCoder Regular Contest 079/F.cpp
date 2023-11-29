#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 2e5 + 5;
    const int INF = 0x3f3f3f3f;
    int n;
    int fa[MAXN];
    std::vector<int> e[MAXN];
    bool vis[MAXN], loop[MAXN];
    int min = INF, max = -INF, cnt = 0;
    void find_loop()
    {
        int x = 1;
        while (vis[x] == false)
        {
            vis[x] = true, x = fa[x];
        }
        while (loop[x] == false)
        {
            loop[x] = true, x = fa[x];
        }
    }
    int dfs(int u)
    {
        std::set<int> s;
        for (auto v : e[u])
        {
            if (loop[v] == false)
            {
                s.insert(dfs(v));
            }
        }
        if (s.begin() == s.end() || *s.begin() != 0)
        {
            return 0;
        }
        for (auto it = s.begin(); it != s.end(); it++)
        {
            if (std::next(it) == s.end() || (*std::next(it)) != (*it) + 1)
            {
                return (*it) + 1;
            }
        }
        return 0;
    }
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &fa[i]);
            e[fa[i]].push_back(i);
        }
        find_loop();
        for (int i = 1; i <= n; i++)
        {
            if (loop[i])
            {
                cnt++;
                int x = dfs(i);
                min = std::min(min, x), max = std::max(max, x);
            }
        }
        if (min == max && cnt % 2 == 1)
        {
            puts("IMPOSSIBLE");
        }
        else
        {
            puts("POSSIBLE");
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}