#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    using std::printf;
    using std::scanf;
    std::string s;
    int main()
    {
        std::cin >> s;
        for (int i = 1; i < 16; i++)
        {
            if ((i + 1) % 2 == 0)
            {
                if (s[i] == '1')
                {
                    printf("No\n");
                    return 0;
                }
            }
        }
        printf("Yes\n");
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}