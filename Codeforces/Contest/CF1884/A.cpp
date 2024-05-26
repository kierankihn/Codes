#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    int t;
    int getSum(int x)
    {
        int res = 0;
        while (x)
        {
            res += x % 10, x /= 10;
        }
        return res;
    }
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            int x, k;
            scanf("%d%d", &x, &k);
            while (getSum(x) % k != 0)
            {
                x++;
            }
            printf("%d\n", x);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}