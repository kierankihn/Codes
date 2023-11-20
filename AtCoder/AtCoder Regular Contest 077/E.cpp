#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 1e5 + 5;
    int n, m;
    int a[MAXN];
    i64 ans = 0;
    i64 min = 0;
    i64 sum[MAXN], sum_rev[MAXN], sum_rev_st[MAXN];
    i64 sum_cnt[MAXN], sum_rev_cnt[MAXN], sum_rev_st_cnt[MAXN];
    int lowbit(int x)
    {
        return x & (-x);
    }
    i64 query(i64 *s, int x)
    {
        i64 res = 0;
        while (x > 0)
        {
            res += s[x], x -= lowbit(x);
        }
        return res;
    }
    void update(i64 *s, int x, i64 v)
    {
        while (x <= m)
        {
            s[x] += v, x += lowbit(x);
        }
    }
    struct Range
    {
        int l, r;
    };
    bool operator<(const Range &a, const Range &b)
    {
        return a.l < b.l;
    }
    std::vector<Range> range;
    int main()
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i < n; i++)
        {
            int st = a[i], ed = a[i + 1];
            if (st < ed)
            {
                ans += ed - st;
                range.push_back({st, ed});
            }
            if (st > ed)
            {
                ans += m - st + ed;
                update(sum_rev, ed, m - st - 1), update(sum_rev_cnt, ed, 1);
                update(sum_rev_st, st, -st - 1), update(sum_rev_st_cnt, st, 1);
            }
        }
        std::sort(range.begin(), range.end());
        auto now = range.begin();
        for (int k = 1; k <= m; k++)
        {
            while (now != range.end() && now->l < k)
            {
                update(sum, now->r, -now->l - 1), update(sum_cnt, now->r, 1), now++;
            }
            i64 res = 0;
            res -= query(sum_rev_st, k - 1) + query(sum_rev_st_cnt, k - 1) * k;
            res -= (query(sum, m) + query(sum_cnt, m) * k) - (query(sum, k - 1) + query(sum_cnt, k - 1) * k);
            res -= (query(sum_rev, m) + query(sum_rev_cnt, m) * k) - (query(sum_rev, k - 1) + query(sum_rev_cnt, k - 1) * k);
            min = std::min(min, res);
        }
        printf("%lld\n", ans + min);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}