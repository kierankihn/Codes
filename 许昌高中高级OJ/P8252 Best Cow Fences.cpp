#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    const double eps = 1e-5;
    int n, len;
    double a[MAXN], sum[MAXN];
    bool check(double x)
    {
        for (int i = 1; i <= n; i++)
        {
            sum[i] = sum[i - 1] + a[i] - x;
        }
        double ans = -1e10, min_val = 0;
        for (int i = len; i <= n; i++)
        {
            min_val = std::min(min_val, sum[i - len]);
            ans = std::max(ans, sum[i] - min_val);
        }
        return ans >= 0;
    }
    int main()
    {
        scanf("%d%d", &n, &len);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf", &a[i]);
        }
        double l = -1e6, r = 1e6;
        while (r - l > eps)
        {
            double mid = (l + r) / 2;
            if (check(mid))
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        printf("%d\n", (int)((l + eps) * 1000));
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}