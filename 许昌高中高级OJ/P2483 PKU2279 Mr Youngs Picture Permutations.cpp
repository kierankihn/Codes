#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 30 + 5;
    int n, k[MAXN];
    LL dp[MAXN][MAXN][MAXN][MAXN][MAXN];
    void init()
    {
        for (int i = n + 1; i <= 5; i++)
        {
            k[i] = 0;
        }
        for (int a = 0; a <= k[1]; a++)
        {
            for (int b = 0; b <= k[2]; b++)
            {
                for (int c = 0; c <= k[3]; c++)
                {
                    for (int d = 0; d <= k[4]; d++)
                    {
                        for (int e = 0; e <= k[5]; e++)
                        {
                            dp[a][b][c][d][e] = 0;
                        }
                    }
                }
            }
        }
        dp[0][0][0][0][0] = 1;
    }
    bool check(int *v)
    {
        for (int i = 1; i < n; i++)
        {
            if (v[i] < v[i + 1])
            {
                return false;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (v[i] < 0)
            {
                return false;
            }
        }
        return true;
    }
    LL solve(int *v)
    {
        LL &res = dp[v[1]][v[2]][v[3]][v[4]][v[5]];
        if (res != 0)
        {
            return res;
        }
        for (int i = 1; i <= n; i++)
        {
            v[i]--;
            if (check(v) == true)
            {
                res += solve(v);
            }
            v[i]++;
        }
        return res;
    }
    int main()
    {
        while (scanf("%d", &n) != EOF && n != 0)
        {
            k[0] = 0;
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &k[i]);
                k[0] += k[i];
            }
            init();
            printf("%lld\n", solve(k));
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}