#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    const int MAXP = 1e6 + 5;
    const int INF = 0x3f3f3f3f;
    int n;
    std::string a[MAXN];
    LL cnt[10][50];
    LL ans = 0;
    LL calc(std::string x)
    {
        LL res = 0;
        for (auto &c : x)
        {
            res += c - '0';
        }
        return res;
    }
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            std::cin >> a[i];
            cnt[a[i].size()][calc(a[i])]++;
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i].size() == 1)
            {
                ans += cnt[1][calc(a[i])];
            }
            if (a[i].size() == 2)
            {
                ans += cnt[2][calc(a[i])];
            }
            if (a[i].size() == 3)
            {
                ans += cnt[1][a[i][0] + a[i][1] - a[i][2] - (int)'0'];
                ans += cnt[1][a[i][2] + a[i][1] - a[i][0] - (int)'0'];
                ans += cnt[3][calc(a[i])];
            }
            if (a[i].size() == 4)
            {
                ans += cnt[2][a[i][0] + a[i][1] + a[i][2] - a[i][3] - (int)'0' * 2];
                ans += cnt[2][a[i][3] + a[i][2] + a[i][1] - a[i][0] - (int)'0' * 2];
                ans += cnt[4][calc(a[i])];
            }
            if (a[i].size() == 5)
            {
                ans += cnt[1][a[i][0] + a[i][1] + a[i][2] - a[i][3] - a[i][4] - (int)'0'];
                ans += cnt[1][a[i][4] + a[i][3] + a[i][2] - a[i][1] - a[i][0] - (int)'0'];
                ans += cnt[3][a[i][0] + a[i][1] + a[i][2] + a[i][3] - a[i][4] - (int)'0' * 3];
                ans += cnt[3][a[i][4] + a[i][3] + a[i][2] + a[i][1] - a[i][0] - (int)'0' * 3];
                ans += cnt[5][calc(a[i])];
            }
        }
        printf("%lld\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}