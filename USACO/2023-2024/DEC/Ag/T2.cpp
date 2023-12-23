#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 5e5 + 5;
    int n, k;
    int ans = 0;
    int a[MAXN];
    int b[MAXN];
    int pos[MAXN];
    int cnt[MAXN];
    std::set<int> inab;
    int main()
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= k; i++)
        {
            scanf("%d", &a[i]), pos[a[i]] = i;
            inab.insert(a[i]);
        }
        for (int i = 1; i <= k; i++)
        {
            scanf("%d", &b[i]);
            inab.insert(b[i]);
        }
        std::fill(cnt, cnt + MAXN, 0);
        for (int i = 1; i <= k; i++)
        {
            if (pos[b[i]] != 0)
            {
                int delta = 0;
                if (i <= pos[b[i]])
                {
                    delta = pos[b[i]] - i;
                }
                else
                {
                    delta = pos[b[i]] + k - i;
                }
                cnt[delta]++;
            }
        }
        for (int i = 0; i <= k; i++)
        {
            ans = std::max(ans, cnt[i]);
        }
        std::fill(cnt, cnt + MAXN, 0);
        std::reverse(b + 1, b + k + 1);
        for (int i = 1; i <= k; i++)
        {
            if (pos[b[i]] != 0)
            {
                int delta = 0;
                if (i <= pos[b[i]])
                {
                    delta = pos[b[i]] - i;
                }
                else
                {
                    delta = pos[b[i]] + k - i;
                }
                cnt[delta]++;
            }
        }
        for (int i = 0; i <= k; i++)
        {
            ans = std::max(ans, cnt[i]);
        }
        ans += n - inab.size();
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}