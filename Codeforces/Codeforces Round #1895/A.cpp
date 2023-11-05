#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1000 + 5;
    const int INF = 0x3f3f3f3f;
    int t;
    int n, m, k;
    LL ans = 0;
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d%d%d", &n, &m, &k);
            if (m < n)
            {
                ans = n;
            }
            else if (n + k >= m)
            {
                ans = m;
            }
            else
            {
                ans = m + (m - k - n);
            }
            printf("%lld\n", ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}