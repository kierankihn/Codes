#include <bits/stdc++.h>
namespace solution
{
    typedef char chr;
    typedef bool bol;
    typedef long long i64;
    const int MAXN = 2e5 + 5;
    const int DELTA = 1e5;
    int n, c;
    int pos = 0;
    chr op[MAXN];
    int cnt[MAXN];
    std::size_t ans = 0;
    std::bitset<MAXN> left, right, target;
    int main()
    {
        scanf("%d%d", &n, &c);
        for (int i = 1; i <= n; i++)
        {
            int p;
            scanf("%d", &p);
            target[p + DELTA] = 1;
        }
        scanf("%s", op + 1);
        for (int i = 1; i <= c; i++)
        {
            if (op[i] == 'L')
            {
                pos--;
            }
            if (op[i] == 'R')
            {
                pos++;
            }
            if (op[i] == 'F')
            {
                cnt[pos + DELTA]++, right[pos + DELTA] = 1;
            }
        }
        pos = 0;
        ans = std::max(ans, right.count());
        for (int i = 1; i <= c; i++)
        {
            if (op[i] == 'L')
            {
                ans = std::max({ans,
                                ((left | (right << 2)) & target).count(),
                                ((left | (right << 1)).set(pos + DELTA) & target).count()});
            }
            if (op[i] == 'R')
            {
                ans = std::max({ans,
                                ((left | (right >> 2)) & target).count(),
                                ((left | (right >> 1)).set(pos + DELTA) & target).count()});
            }
            if (op[i] == 'F')
            {
                if (cnt[pos + DELTA] == 1)
                {
                    ans = std::max({ans,
                                    ((left | (right << 1)).set(pos + DELTA, 0) & target).count(),
                                    ((left | (right >> 1)).set(pos + DELTA, 0) & target).count()});
                }
                else
                {
                    ans = std::max({ans,
                                    ((left | (right << 1)) & target).count(),
                                    ((left | (right >> 1)) & target).count()});
                }
            }
            if (op[i] == 'L')
            {
                pos--;
            }
            if (op[i] == 'R')
            {
                pos++;
            }
            if (op[i] == 'F')
            {
                left[pos + DELTA] = 1, cnt[pos + DELTA]--;
                if (cnt[pos + DELTA] == 0)
                {
                    right[pos + DELTA] = 0;
                }
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