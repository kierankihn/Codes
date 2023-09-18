#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e6 + 5;
    int n;
    std::stack<LL> s, t;
    LL ans = 0;
    LL h[MAXN];
    int main()
    {
        while (scanf("%d", &n) && n != 0)
        {
            ans = 0;
            while (!s.empty() && !t.empty())
            {
                s.pop(), t.pop();
            }
            for (int i = 1; i <= n; i++)
            {
                scanf("%lld", &h[i]);
            }
            h[n + 1] = 0;
            for (int i = 1; i <= n + 1; i++)
            {
                if (s.empty() || t.empty() || h[i] > s.top())
                {
                    s.push(h[i]), t.push(1);
                }
                else
                {
                    LL w = 0;
                    while (!s.empty() && !t.empty() && h[i] < s.top())
                    {
                        w += t.top();
                        ans = std::max(ans, w * s.top());
                        s.pop(), t.pop();
                    }
                    s.push(h[i]), t.push(w + 1);
                }
            }
            printf("%lld\n", ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}