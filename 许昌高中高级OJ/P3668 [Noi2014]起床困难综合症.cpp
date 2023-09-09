#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    struct OP
    {
        LL type, x;
        OP() {}
        OP(LL type_, LL x_) : type(type_), x(x_) {}
    };
    LL now = 0, ans = 0;
    LL n, m;
    OP op[MAXN];
    LL res0, res1;
    int main()
    {
        scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            char a[20];
            scanf("%s%lld", a, &op[i].x);
            if (strcmp(a, "AND") == 0)
            {
                op[i].type = 1;
            }
            if (strcmp(a, "XOR") == 0)
            {
                op[i].type = 2;
            }
            if (strcmp(a, "OR") == 0)
            {
                op[i].type = 3;
            }
        }
        res0 = 0, res1 = (1 << ((int)std::ceil(std::log2(m)) + 1)) - 1;
        for (int i = 1; i <= n; i++)
        {
            if (op[i].type == 1)
            {
                res0 = res0 & op[i].x, res1 = res1 & op[i].x;
            }
            if (op[i].type == 2)
            {
                res0 = res0 ^ op[i].x, res1 = res1 ^ op[i].x;
            }
            if (op[i].type == 3)
            {
                res0 = res0 | op[i].x, res1 = res1 | op[i].x;
            }
        }
        for (int i = 35; i >= 0; i--)
        {
            if (((res1 & (1LL << i)) > (res0 & (1LL << i))) && (now + (1LL << i) <= m))
            {
                now += (1LL << i);
                ans += res1 & (1LL << i);
            }
            else
            {
                ans += res0 & (1LL << i);
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