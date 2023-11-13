#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 50 + 5;
    int tt;
    int n, m;
    bool ft = true, ans = true;
    std::string s, t;
    int main()
    {
        std::cin >> tt;
        while (tt--)
        {
            ft = ans = true;
            std::cin >> n >> m >> s >> t;
            for (size_t i = 1; i <= t.size(); i++)
            {
                if (t[i - 1] == t[i])
                {
                    ft = false;
                }
            }
            for (size_t i = 1; i < s.size(); i++)
            {
                if (s[i - 1] == s[i])
                {
                    if (s[i - 1] == t.front() || s[i] == t.back() || ft == false)
                    {
                        ans = false;
                    }
                }
            }
            if (ans)
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