#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    int t;
    int n, k;
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d%d", &n, &k);
            if (k < n * 4 - 2 - 2)
            {
                printf("%d\n", (int)std::ceil(k / 2.0));
            }
            else
            {
                printf("%d\n", n * 2 - 2 + k - (n * 4 - 2 - 2));
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