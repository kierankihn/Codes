#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1000 + 5;
    using std::printf;
    using std::scanf;
    int n, m;
    int ans = 0;
    bool hate[MAXN][MAXN];
    std::vector<int> e[MAXN];
    void build()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (hate[i][j] == false)
                {
                    e[i].push_back(j), e[j].push_back(i);
                }
            }
        }
    }
    std::stack<int> s;
    std::vector<int> dcc[MAXN];
    int tot = 0;
    int cnt = 0;
    int dfn[MAXN], low[MAXN];
    void tarjan(int u, int fa)
    {
        dfn[u] = low[u] = ++tot, s.push(u);
        if (fa == 0 && e[u].empty())
        {
            dcc[++cnt].clear();
            dcc[cnt].push_back(u);
        }
        for (auto &v : e[u])
        {
            if (dfn[v] == 0)
            {
                tarjan(v, u);
                if (low[v] >= dfn[u])
                {
                    dcc[++cnt].clear();
                    while (s.top() != v)
                    {
                        dcc[cnt].push_back(s.top()), s.pop();
                    }
                    s.pop();
                    dcc[cnt].push_back(u), dcc[cnt].push_back(v);
                }
                low[u] = std::min(low[u], low[v]);
            }
            else
            {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
    }
    bool flag;
    int now = 0;
    bool able[MAXN];
    int c[MAXN], p[MAXN];
    void dfs(int u, int color)
    {
        c[u] = color;
        for (auto &v : e[u])
        {
            if (p[v] != now)
            {
                continue;
            }
            if (c[v] != 0 && c[v] == color)
            {
                flag = true;
                return;
            }
            if (c[v] == 0)
            {
                dfs(v, 3 - color);
            }
        }
    }
    void init()
    {
        while (!s.empty())
        {
            s.pop();
        }
        ans = now = 0;
        tot = cnt = 0;
        std::memset(c, 0, sizeof(c));
        std::memset(p, 0, sizeof(p));
        std::memset(dfn, 0, sizeof(dfn));
        std::memset(low, 0, sizeof(low));
        std::memset(hate, 0, sizeof(hate));
        std::memset(able, 0, sizeof(able));
        for (int i = 1; i <= n; i++)
        {
            dcc[i].clear(), e[i].clear();
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
                hate[u][v] = hate[v][u] = true;
            }
            build();
            for (int u = 1; u <= n; u++)
            {
                if (dfn[u] == 0)
                {
                    tarjan(u, 0);
                }
            }
            for (int i = 1; i <= cnt; i++)
            {
                now++, flag = false;
                for (auto &u : dcc[i])
                {
                    p[u] = now, c[u] = 0;
                }
                dfs(dcc[i][0], 1);
                if (flag == true)
                {
                    for (auto &u : dcc[i])
                    {
                        able[u] = true;
                    }
                }
            }
            for (int i = 1; i <= n; i++)
            {
                if (able[i] == false)
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