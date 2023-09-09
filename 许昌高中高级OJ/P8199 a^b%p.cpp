#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    LL qpow(LL a, LL b, LL c)
    {
        LL res = 1;
        while (b)
        {
            if (b & 1)
            {
                res = res * a % c;
            }
            b = b >> 1;
            a = a * a % c;
        }
        return res % c;
    }
    int main()
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        printf("%lld", qpow(a, b, c));
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}