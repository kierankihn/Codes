#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 26 + 5;
    int n, m;
    std::string res;
    int du[MAXN], d[MAXN];
    std::vector<int> g[MAXN];
    void addEdge(int u, int v)
    {
        g[u].push_back(v);
        du[v]++;
    }
    int topo()
    {
        res = "";
        int cnt = 0;
        int check = 1;
        std::queue<int> q;
        for (int i = 1; i <= n; i++)
        {
            d[i] = du[i];
            if (d[i] == 0)
            {
                q.push(i);
            }
        }
        while (!q.empty())
        {
            if (q.size() > 1)
            {
                check = 0;
            }
            int u = q.front();
            q.pop();
            cnt++;
            res = res + (char)(u + 'A' - 1);
            for (auto &v : g[u])
            {
                d[v]--;
                if (d[v] == 0)
                {
                    q.push(v);
                }
            }
        }
        if (cnt < n)
        {
            check = -1;
        }
        return check;
    }
    int main()
    {
        while (scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0)
        {
            bool flag = false;
            for (int i = 1; i <= m; i++)
            {
                char str[10];
                scanf("%s", str + 1);
                if (flag == true)
                {
                    continue;
                }
                addEdge(str[1] - 'A' + 1, str[3] - 'A' + 1);
                int check = topo();
                if (check == -1)
                {
                    flag = true;
                    printf("Inconsistency found after %d relations.\n", i);
                }
                if (check == 1)
                {
                    flag = true;
                    printf("Sorted sequence determined after %d relations: %s.\n", i, res.c_str());
                }
            }
            if (flag == false)
            {
                puts("Sorted sequence cannot be determined.");
            }
            for (int i = 1; i <= 26; i++)
            {
                g[i].clear(), du[i] = 0;
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}