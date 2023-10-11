#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    int n, m;
    int cnt = 0;
    bool flag = false;
    int in[MAXN], out[MAXN];
    std::vector<int> e[MAXN];
    std::set<int> ee[MAXN];
    int dfn_tot = 0, color_tot = 0;
    int dfn[MAXN], low[MAXN], color[MAXN], size[MAXN];
    std::stack<int> s;
    bool isinsta[MAXN];
    void push(int x)
    {
        s.push(x), isinsta[x] = true;
    }
    int pop()
    {
        int x = s.top();
        isinsta[x] = false, s.pop();
        return x;
    }
    void tarjan(int u)
    {
        push(u), dfn[u] = ++dfn_tot, low[u] = dfn[u];
        for (auto &v : e[u])
        {
            if (dfn[v] != 0 && isinsta[v] == true)
            {
                low[u] = std::min(low[u], low[v]);
            }
            if (dfn[v] == 0)
            {
                tarjan(v);
                low[u] = std::min(low[u], low[v]);
            }
        }
        if (dfn[u] == low[u])
        {
            color_tot++;
            while (s.top() != u)
            {
                color[pop()] = color_tot, size[color_tot]++;
            }
            color[pop()] = color_tot, size[color_tot]++;
        }
    }
    bool check(int u)
    {
        if (flag == true)
        {
            return false;
        }
        if (size[u] != 1)
        {
            return false;
        }
        for (auto &v : ee[u])
        {
            if (in[v] == 1)
            {
                return false;
            }
        }
        return flag = true;
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
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
                if (color[u] != color[v] && ee[color[u]].find(color[v]) == ee[color[u]].end())
                {
                    ee[color[u]].insert(color[v]);
                    out[color[u]]++, in[color[v]]++;
                }
            }
        }
        for (int u = 1; u <= color_tot; u++)
        {
            if (in[u] == 0 && check(u) == false)
            {
                cnt++;
            }
        }
        printf("%.6lf\n", (double)(n - cnt) / n);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}