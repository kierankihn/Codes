#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    typedef unsigned long long ULL;
    const int MAXN = 1e6 + 5;
    const ULL P = 785;
    int n, m;
    ULL pn[MAXN], hash[MAXN];
    char s[MAXN];
    int main()
    {
        scanf("%s%d", s + 1, &m);
        n = std::strlen(s + 1);
        pn[0] = 1;
        for (int i = 1; i <= n; i++)
        {
            pn[i] = pn[i - 1] * P;
        }
        for (int i = 1; i <= n; i++)
        {
            hash[i] = hash[i - 1] * P + s[i];
        }
        for (int i = 1; i <= m; i++)
        {
            int l1, r1, l2, r2;
            scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
            if (hash[r1] - hash[l1 - 1] * pn[r1 - l1 + 1] == hash[r2] - hash[l2 - 1] * pn[r2 - l2 + 1])
            {
                puts("Yes");
            }
            else
            {
                puts("No");
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}