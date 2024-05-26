#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    using std::printf;
    using std::scanf;
    int n;
    int ans = 0;
    std::map<LL, LL> mp;
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            LL s, c;
            scanf("%lld%lld", &s, &c);
            mp[s] += c;
        }
        for (auto &u : mp)
        {
            mp[u.first * 2] += u.second / 2;
            u.second = u.second % 2;
            if (u.second)
            {
                ans++;
            }
        }
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}