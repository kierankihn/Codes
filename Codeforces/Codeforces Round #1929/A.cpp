#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 100 + 5;
    const int INF = 0x3f3f3f3f;
    int t;
    int n;
    int max, min;
    int a[MAXN];
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            max = -INF, min = INF;
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &a[i]);
                max = std::max(max, a[i]), min = std::min(min, a[i]);
            }
            printf("%d\n", max - min);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}