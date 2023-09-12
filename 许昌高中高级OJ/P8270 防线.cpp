#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    const int INF = 0x3f3f3f3f;
    int t;
    int n;
    int mins = INF, maxe = -INF;
    int s[MAXN], e[MAXN], d[MAXN];
    int f(int x, int y, int k)
    {
        return (x <= y) ? ((y - x) / k + 1) : 0;
    }
    int check(int x)
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            res += f(s[i], std::min(e[i], x), d[i]);
        }
        return res;
    }
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d", &n);
            for (int i = 1; i <= n; i++)
            {
                scanf("%d%d%d", &s[i], &e[i], &d[i]);
                mins = std::min(mins, s[i]), maxe = std::max(maxe, e[i]);
            }
            int l = mins, r = maxe;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (check(mid) % 2)
                {
                    r = mid;
                }
                else
                {
                    l = mid + 1;
                }
            }
            if ((check(l) - check(l - 1)) % 2)
            {
                printf("%d %d\n", l, check(l) - check(l - 1));
            }
            else
            {
                puts("There's no weakness.");
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