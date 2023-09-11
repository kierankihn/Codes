#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e6 + 5;
    int n;
    LL a[MAXN];
    LL p = 0, q = 0;
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        for (int i = 1; i < n; i++)
        {
            if (a[i + 1] - a[i] < 0)
            {
                p += a[i] - a[i + 1];
            }
            else
            {
                q += a[i + 1] - a[i];
            }
        }
        printf("%lld\n%lld\n", std::max(p, q), std::abs(p - q) + 1);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}