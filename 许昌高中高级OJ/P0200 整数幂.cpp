#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    int main()
    {
        int n;
        scanf("%d", &n);
        if (std::floor(std::log2(n)) == std::ceil(std::log2(n)))
        {
            std::puts("yes");
        }
        else
        {
            std::puts("no");
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}