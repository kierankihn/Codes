#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e4 + 5;
    std::map<std::pair<int, int>, bool> mp;
    int n, root, h, r;
    int c[MAXN], d[MAXN];
    int main()
    {
        scanf("%d%d%d%d", &n, &root, &h, &r);
        for (int i = 1; i <= r; i++)
        {
            int a, b;
            scanf("%d%d", &a, &b);
            if (a > b)
            {
                std::swap(a, b);
            }
            if (mp[std::make_pair(a, b)])
            {
                continue;
            }
            mp[std::make_pair(a, b)] = true;
            d[a + 1]--, d[b]++;
        }
        for (int i = 1; i <= n; i++)
        {
            c[i] = c[i - 1] + d[i];
            printf("%d\n", c[i] + h);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}