#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    int t;
    int n, k;
    int a[MAXN], b[MAXN];
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &a[i]), b[i] = a[i];
            }
            std::sort(b + 1, b + n + 1);
            k = std::unique(b + 1, b + n + 1) - b - 1;
            if (k == 1)
            {
                puts("Yes");
            }
            else if (k == 2)
            {
                int cnt1 = 0, cnt2 = 0;
                for (int i = 1; i <= n; i++)
                {
                    if (a[i] == b[1])
                    {
                        cnt1++;
                    }
                    else
                    {
                        cnt2++;
                    }
                }
                if (std::abs(cnt1 - cnt2) <= 1)
                {
                    puts("Yes");
                }
                else
                {
                    puts("No");
                }
            }
            else
            {
                puts("No");
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