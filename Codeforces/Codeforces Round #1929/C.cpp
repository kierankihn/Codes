#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    int t;
    i64 k, x, a, sum = 0, ans = 0;
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            sum = 0, ans = 1;
            scanf("%lld%lld%lld", &k, &x, &a);
            for (int i = 1; i <= x + 1; i++)
            {
                a -= sum / (k - 1) + 1, sum += sum / (k - 1) + 1;
                if (a < 0)
                {
                    ans = 0;
                    break;
                }
            }
            if (ans)
            {
                puts("YES");
            }
            else
            {
                puts("NO");
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