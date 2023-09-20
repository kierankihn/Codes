#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    int n;
    LL ans = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int val;
            scanf("%d", &val);
            q.push(val);
        }
        while (q.size() > 1)
        {
            int min1, min2;
            min1 = q.top(), q.pop();
            min2 = q.top(), q.pop();
            ans += min1 + min2;
            q.push(min1 + min2);
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