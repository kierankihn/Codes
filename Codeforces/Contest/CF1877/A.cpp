#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    using std::scanf;
    using std::printf;
    int t;
    LL n;
    LL a;
    LL ans;
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            ans = 0;
            scanf("%lld", &n);
            for (int i = 1; i < n; i++)
            {
                scanf("%lld", &a);
                ans -= a;
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