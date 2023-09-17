#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    std::string s;
    int cnt = 0;
    int main()
    {
        std::cin >> s;
        for (auto &c : s)
        {
            if (c == '(')
            {
                cnt++;
            }
            if (c == ')')
            {
                if (cnt <= 0)
                {
                    puts("NO");
                    return 0;
                }
                cnt--;
            }
        }
        if (cnt != 0)
        {
            puts("NO");
        }
        else
        {
            puts("YES");
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}