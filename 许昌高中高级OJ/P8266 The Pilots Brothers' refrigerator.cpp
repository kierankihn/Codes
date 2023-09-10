#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 5 + 5;
    const int MAXANS = 1e5 + 5;
    int n = 4;
    int ans = 0;
    int mp[MAXN][MAXN];
    int mark[MAXN][MAXN];
    int x[MAXANS], y[MAXANS];
    void read(int &x)
    {
        int tmp = getchar();
        while (tmp != '+' && tmp != '-')
        {
            tmp = getchar();
        }
        x = (tmp == '+');
    }
    int main()
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                read(mp[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mp[i][j] == 1)
                {
                    mark[i][j] = !mark[i][j];
                    for (int k = 1; k <= n; k++)
                    {
                        mark[i][k] = !mark[i][k], mark[k][j] = !mark[k][j];
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (mark[i][j])
                {
                    x[++ans] = i, y[ans] = j;
                }
            }
        }
        printf("%d\n", ans);
        for (int i = 1; i <= ans; i++)
        {
            printf("%d %d\n", x[i], y[i]);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}