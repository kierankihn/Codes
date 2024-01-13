#include <bits/stdc++.h>
namespace solution
{
    typedef char chr;
    typedef long long i64;
    const int MAXN = 3e7 + 5;
    int n;
    int l, r;
    int ans = 0;
    int d[MAXN];
    chr s[MAXN];
    void read()
    {
        s[n = 1] = '#';
        char ch = getchar();
        while (isalpha(ch))
        {
            s[++n] = ch, s[++n] = '#', ch = getchar();
        }
    }
    int main()
    {
        read();
        for (int i = 1; i <= n; i++)
        {
            int len = 1;
            if (i <= r)
            {
                len = std::min(d[l + r - i], r - i + 1);
            }
            while (1 <= i - len && i + len <= n && s[i - len] == s[i + len])
            {
                len++;
            }
            d[i] = len;
            if (i + len - 1 > r)
            {
                l = i - len + 1, r = i + len - 1;
            }
            ans = std::max(ans, d[i] - 1);
        }
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}