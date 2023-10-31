#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    const int MAXLOGN = 20 + 5;
    LL n, m, p;
    LL a[MAXN], c[MAXN];
    LL dp[MAXN], sum[MAXN], max[MAXN][MAXLOGN];
    std::deque<int> q;
    std::multiset<LL> s;
    void build()
    {
        for (int i = 0; i <= n; i++)
        {
            max[i][0] = a[i];
        }
        for (int k = 1; k <= std::__lg(n + 1); k++)
        {
            for (int i = 0; i + (1 << k) - 1 <= n; i++)
            {
                max[i][k] = std::max(max[i][k - 1], max[i + (1 << (k - 1))][k - 1]);
            }
        }
    }
    LL query(int l, int r)
    {
        int k = std::__lg(r - l + 1);
        return std::max(max[l][k], max[r - (1 << k) + 1][k]);
    }
    int main()
    {
        std::memset(dp, 0x3f, sizeof(dp));
        scanf("%lld%lld", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            sum[i] = sum[i - 1] + a[i];
        }
        build();
        p = 1;
        for (int i = 1; i <= n; i++)
        {
            while (sum[i] - sum[p - 1] > m)
            {
                p++;
            }
            c[i] = p;
        }
        dp[0] = 0, q.push_back(0), s.insert(0);
        for (int i = 1; i <= n; i++)
        {
            dp[i] = std::min(dp[i], dp[c[i] - 1] + query(c[i], i));
            while (!q.empty() && q.front() < c[i])
            {
                s.erase(s.find(dp[q.front() - 1] + a[q.front()])), q.pop_front();
            }
            while (!q.empty() && a[i] > a[q.back()])
            {
                s.erase(s.find(dp[q.back() - 1] + a[q.back()])), q.pop_back();
            }
            if (!q.empty())
            {
                dp[i] = std::min(dp[i], *(s.begin()));
            }
            q.push_back(i), s.insert(dp[i - 1] + a[i]);
        }
        printf("%lld\n", dp[n]);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}