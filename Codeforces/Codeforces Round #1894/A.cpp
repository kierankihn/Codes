#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    int t;
    int n;
    std::string s;
    int main()
    {
        std::cin >> t;
        while (t--)
        {
            std::cin >> n;
            std::cin >> s;
            std::cout << s.back() << std::endl;
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}