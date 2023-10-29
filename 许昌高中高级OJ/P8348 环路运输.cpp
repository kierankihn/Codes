#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e6 + 5;
    int n;
    LL ans = 0;
    LL v[MAXN];
    std::deque<std::pair<LL, int>> q;
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &v[i]);
            v[i + n] = v[i];
        }
        for (int i = 1; i <= 2 * n; i++)
        {
            while (!q.empty() && q.front().second < i - n / 2)
            {
                q.pop_front();
            }
            if (!q.empty())
            {
                ans = std::max(ans, v[i] + q.front().first + i);
            }
            while (!q.empty() && (q.back().first < v[i] - i || q.back().second < i - n / 2))
            {
                q.pop_back();
            }
            q.push_back(std::make_pair(v[i] - i, i));
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