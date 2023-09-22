#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    LL n;
    LL ans = 0;
    LL euler(LL x)
    {
        LL res = x;
        for (LL i = 2; i <= std::sqrt(x); i++)
        {
            if (x % i == 0)
            {
                res = res * (i - 1) / i;
            }
            while (x % i == 0)
            {
                x = x / i;
            }
        }
        if (x > 1)
        {
            res = res * (x - 1) / x;
        }
        return res;
    }
    int main()
    {
        while (scanf("%lld", &n) != EOF)
        {
            ans = 0;
            for (LL i = 1; i < std::sqrt(n); i++)
            {
                if (n % i == 0)
                {
                    ans += i * euler(n / i) + (n / i) * euler(i);
                }
            }
            if (std::ceil(std::sqrt(n)) == std::floor(std::sqrt(n)))
            {
                ans += std::sqrt(n) * euler(std::sqrt(n));
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