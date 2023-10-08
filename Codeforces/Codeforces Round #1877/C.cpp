#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    using std::printf;
    using std::scanf;
    int t;
    LL n, m, k;
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            scanf("%lld%lld%lld", &n, &m, &k);
            if (k == 1)
            {
                puts("1");
            }
            if (k == 2)
            {
                printf("%lld\n", std::min(m, m / n + n - 1));
            }
            if (k == 3)
            {
                printf("%lld\n", std::max(0LL, m - std::min(m, m / n + n - 1)));
            }
            if (k >= 4)
            {
                puts("0");
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