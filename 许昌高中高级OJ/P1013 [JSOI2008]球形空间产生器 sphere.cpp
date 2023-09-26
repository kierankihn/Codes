#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const double eps = 1e-7;
    const int MAXN = 100 + 5;
    int n;
    double a[MAXN][MAXN];
    double val[MAXN][MAXN];
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n + 1; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%lf", &a[i][j]);
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                val[i][j] = 2 * (a[i][j] - a[i + 1][j]);
                val[i][n + 1] = val[i][n + 1] + a[i][j] * a[i][j] - a[i + 1][j] * a[i + 1][j];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            int maxpos = i;
            for (int j = i + 1; j <= n; j++)
            {
                if (std::fabs(val[j][i]) > std ::fabs(val[maxpos][i]))
                {
                    maxpos = j;
                }
            }
            for (int j = 1; j <= n + 1; j++)
            {
                std::swap(val[i][j], val[maxpos][j]);
            }
            if (std::fabs(val[i][i]) < eps)
            {
                puts("No solution.");
                return 0;
            }
            for (int j = 1; j <= n; j++)
            {
                if (i != j)
                {
                    double tmp = val[j][i] / val[i][i];
                    for (int k = i; k <= n + 1; k++)
                    {
                        val[j][k] -= tmp * val[i][k];
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%.3lf%c", val[i][n + 1] / val[i][i], i == n ? '\n' : ' ');
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}