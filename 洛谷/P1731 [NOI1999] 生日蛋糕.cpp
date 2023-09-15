#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int INF = 0x3f3f3f3f;
    const int MAXVOL = 15 + 5;
    int n, m;
    int minv[MAXVOL], mins[MAXVOL];
    int ans = INF;
    void solve(int vol, int s, int v, int lastr, int lasth)
    {
        if (vol == 0)
        {
            if (v == n)
            {
                ans = std::min(ans, s);
            }
            return;
        }
        if (s + 2 * (n - v) / lastr >= ans)
        {
            // puts("1");
            return;
        }
        if (v + minv[vol] > n)
        {
            // puts("2");
            return;
        }
        if (s + mins[vol] > ans)
        {
            // puts("3");
            return;
        }
        for (int r = lastr - 1; r >= vol; r--)
        {
            if (vol == m)
            {
                s = r * r;
            }
            int maxh = std::min(lasth - 1, (n - v - minv[vol - 1] / (r * r)));
            for (int h = maxh; h >= 1; h--)
            {
                solve(vol - 1, s + 2 * r * h, v + r * r * h, r, h);
            }
        }
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            minv[i] = minv[i - 1] + i * i * i;
            mins[i] = mins[i - 1] + 2 * i * i;
        }
        solve(m, 0, 0, std::sqrt(n), n);
        printf("%d\n", ans == INF ? 0 : ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}