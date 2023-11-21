#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 1e6 + 5;
    const int INF = 0x3f3f3f3f;
    int n;
    i64 ans = 0;
    int a[MAXN];
    int min[MAXN];
    std::stack<int> s;
    int main()
    {
        std::fill(min, min + MAXN, INF);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            while (s.empty() == false && s.top() < a[i])
            {
                s.pop();
            }
            if (s.empty() == false)
            {
                min[i] = std::min(min[i], s.top());
            }
            s.push(a[i]);
        }
        while (s.empty() == false)
        {
            s.pop();
        }
        for (int i = n; i >= 1; i--)
        {
            while (s.empty() == false && s.top() < a[i])
            {
                s.pop();
            }
            if (s.empty() == false)
            {
                min[i] = std::min(min[i], s.top());
            }
            s.push(a[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (min[i] != INF)
            {
                ans += min[i];
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