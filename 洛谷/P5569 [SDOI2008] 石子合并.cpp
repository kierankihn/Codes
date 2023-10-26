#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 40000 + 5;
    const LL INF = 0x3f3f3f3fLL;
    int n;
    LL a[MAXN];
    LL ans = 0;
    std::vector<LL> v;
    int find1()
    {
        for (int i = 1; i < v.size(); i++)
        {
            if (v[i - 1] < v[i + 1])
            {
                return i;
            }
        }
        return -1;
    }
    int find2(int x)
    {
        for (int i = x - 1; i >= 0; i--)
        {
            if (v[i] > v[x - 1] + v[x])
            {
                return i;
            }
        }
        return -1;
    }
    int main()
    {
        scanf("%d", &n);
        v.push_back(INF - 1);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
            v.push_back(a[i]);
        }
        v.push_back(INF);

        for (int i = 1; i < n; i++)
        {
            LL p1 = find1();
            LL p2 = find2(p1);
            LL val = v[p1 - 1] + v[p1];
            v.erase(v.begin() + p1 - 1), v.erase(v.begin() + p1 - 1);
            v.insert(v.begin() + p2 + 1, val);
            ans += val;
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