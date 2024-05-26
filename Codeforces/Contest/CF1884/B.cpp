#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    int t;
    int n;
    LL ans = 0;
    LL last = 0;
    std::string s;
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            std::cin >> n >> s;
            ans = 0, last = n;
            for (int i = n - 1; i >= 0; i--)
            {
                int j = last - 1;
                while (j >= 0 && s[j] != '0')
                {
                    j--;
                }
                if (j >= 0)
                {
                    ans += i - j;
                    std::swap(s[i], s[j]);
                }
                else
                {
                    ans = -1;
                }
                last = j;
                printf("%lld ", ans);
            }
            puts("");
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}