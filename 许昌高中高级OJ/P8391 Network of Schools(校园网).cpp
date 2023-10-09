#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    using std::printf;
    using std::scanf;
    std::vector<int> e[MAXN];
    int dfn_tot = 0;
    std::stack<int> s;
    bool isinsta[MAXN];
    int dfn[MAXN], low[MAXN];
    int color_tot = 0;
    int color[MAXN];
    void tarjan(int u)
    {
        s.push(u), isinsta[u] = true;
        dfn[u] = ++dfn_tot, low[u] = dfn[u];
        for (auto &v : e[u])
        {
            if (dfn[v] != 0 && isinsta[v])
            {
                low[u] = std::min(low[u], low[v]);
            }
            if (dfn[v] == 0)
            {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            }
        }
        if (low[u] == dfn[u])
        {
            color_tot++;
            while (s.top() != u)
            {
                color[s.top()] = color_tot, isinsta[s.top()] = false, s.pop();
            }
            color[u] = color_tot, isinsta[u] = false, s.pop();
        }
    }
    int n;
    int de[MAXN][2];
    int main()
    {
        scanf("%d", &n);
        for (int u = 1; u <= n; u++)
        {
            int v;
            while (scanf("%d", &v) != EOF && v != 0)
            {
                e[u].push_back(v);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (dfn[i] == 0)
            {
                tarjan(i);
            }
        }
        for (int u = 1; u <= n; u++)
        {
            for (auto &v : e[u])
            {
                if (color[u] != color[v])
                {
                    de[color[u]][0]++, de[color[v]][1]++;
                }
            }
        }
        for (int i = 1; i <= color_tot; i++)
        {
            if (de[i][0] == 0)
            {
                de[0][0]++;
            }
            if (de[i][1] == 0)
            {
                de[0][1]++;
            }
        }
        printf("%d\n", de[0][1]);
        printf("%d\n", color_tot == 1 ? 0 : std::max(de[0][0], de[0][1]));
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}