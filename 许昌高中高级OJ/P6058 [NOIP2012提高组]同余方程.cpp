#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    LL exgcd(LL a, LL b, LL &x, LL &y)
    {
        if (b == 0)
        {
            x = 1, y = 0;
            return a;
        }
        LL d = exgcd(b, a % b, x, y);
        LL z = x;
        x = y, y = z - y * (a / b);
        return d;
    }
    int main()
    {
        LL a, b, x, y;
        scanf("%lld%lld", &a, &b);
        exgcd(a, b, x ,y);
        printf("%lld\n", (x % b + b) % b);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}