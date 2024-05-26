#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 100 + 5;
    int t;
    int n;
    int a[MAXN];
    int ton[MAXN];
    int flag1 = 0, flag2 = 0;
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            flag1 = flag2 = 0;
            std::memset(ton, 0, sizeof(ton));
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &a[i]);
                ton[a[i]]++;
            }
            for (int i = 1; i <= n; i++)
            {
                if (flag1 == 0)
                {
                    if (ton[a[i]] >= 2)
                    {
                        flag1 = a[i];
                    }
                }
                else if (flag2 == 0)
                {
                    if (ton[a[i]] >= 2 && flag1 != a[i])
                    {
                        flag2 = a[i];
                        break;
                    }
                }
            }
            if (flag1 == 0 || flag2 == 0)
            {
                puts("-1");
                continue;
            }
            for (int i = 1; i <= n; i++)
            {
                if (flag1 == a[i])
                {
                    printf("%d ", 1);
                    flag1 = 0;
                }
                else if (flag2 == a[i])
                {
                    printf("%d ", 2);
                    flag2 = 0;
                }
                else
                {
                    printf("%d ", 3);
                }
            }
            puts("");
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}