#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 300 + 5;
    i64 n;
    i64 ans = 0;
    i64 a[MAXN][MAXN];
    i64 d[MAXN][MAXN];
    bool r[MAXN][MAXN];
    int main()
    {
        scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%lld", &a[i][j]);
                d[i][j] = a[i][j];
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
                    if (i != k && j != k)
                    {
                        if (d[i][j] == d[i][k] + d[k][j])
                        {
                            r[i][j] = true;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            bool breakflag = false;
            for (int j = i; j <= n; j++)
            {
                if (d[i][j] != a[i][j])
                {
                    ans = -1, breakflag = true;
                    break;
                }
                if (r[i][j] == false)
                {
                    ans += d[i][j];
                }
            }
            if (breakflag)
            {
                break;
            }
        }
        printf("%lld\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}