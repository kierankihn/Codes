#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 30 + 5;
    int t;
    int n;
    int from[MAXN], to[MAXN];
    int a[MAXN][MAXN];
    int val[MAXN][MAXN];
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            std::memset(a, 0, sizeof(a));
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &from[i]);
            }
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &to[i]);
            }
            int p, q;
            while (scanf("%d%d", &p, &q) != EOF && p != 0 && q != 0)
            {
                a[q][p] = 1;
            }
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    val[i][j] = a[i][j];
                }
                val[i][i] = 1;
                val[i][n + 1] = from[i] ^ to[i];
            }
            for (int i = 1; i <= n; i++)
            {
                int maxpos = -1;
                for (int j = i; j <= n; j++)
                {
                    if (val[j][i])
                    {
                        maxpos = j;
                        break;
                    }
                }
                if (maxpos == -1)
                {
                    continue;
                }
                for (int j = 1; j <= n + 1; j++)
                {
                    std::swap(val[i][j], val[maxpos][j]);
                }
                for (int j = 1; j <= n; j++)
                {
                    if (i != j)
                    {
                        if (val[j][i] == 0)
                        {
                            continue;
                        }
                        for (int k = i; k <= n + 1; k++)
                        {
                            val[j][k] = val[j][k] ^ val[i][k];
                        }
                    }
                }
            }
            LL ans = 0;
            for (int i = 1; i <= n; i++)
            {
                if (val[i][i] == 0 && val[i][n + 1] == 1)
                {
                    ans = -1;
                    break;
                }
                if (val[i][i] == 0 && val[i][n + 1] == 0)
                {
                    ans++;
                }
            }
            // for (int i = 1; i <= n; i++)
            // {
            //     for (int j = 1; j <= n + 1; j++)
            //     {
            //         printf("%d%c", val[i][j], (j == n + 1) ? '\n' : ' ');
            //     }
            // }
            if (ans == -1)
            {
                puts("Oh,it's impossible~!!");
            }
            else
            {
                printf("%lld\n", 1LL << ans);
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