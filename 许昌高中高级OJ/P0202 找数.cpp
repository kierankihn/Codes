#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    std::set<int> s;
    int n;
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int a;
            scanf("%d", &a);
            if (s.count(a))
            {
                s.erase(a);
            }
            else
            {
                s.insert(a);
            }
        }
        printf("%d\n", *s.begin());
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}