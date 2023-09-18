#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    LL n, m, q, u, v, t;
    LL a[MAXN];
    std::priority_queue<LL> p;
    int main()
    {
        std::scanf("%lld%lld%lld%lld%lld%lld", &n, &m, &q, &u, &v, &t);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            p.push(a[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            if (i % t == 0)
            {
                printf("%lld ", p.top() + (i - 1) * q);
            }
            int now = (p.top() + (i - 1) * q) * u / v;
            p.push(now - (i * q)), p.push((p.top() + (i - 1) * q - now) - (i * q));
            p.pop();
        }
        printf("\n");
        for (int i = 1; i <= n + m; i++)
        {
            if (i % t == 0)
            {
                printf("%lld ", p.top() + m * q);
            }
            p.pop();
        }
        printf("\n");
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}