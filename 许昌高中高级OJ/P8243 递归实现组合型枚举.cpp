#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    int n, m;
    std::vector<int> nums;
    void solve(int x)
    {
        if ((int)nums.size() > m || (int)nums.size() + (n - x + 1) < m)
        {
            return;
        }
        if ((int)nums.size() == m)
        {
            for (auto &i : nums)
            {
                printf("%d ", i);
            }
            printf("\n");
            return;
        }
        nums.push_back(x), solve(x + 1);
        nums.pop_back(), solve(x + 1);
    }
    int main()
    {
        scanf("%d%d", &n, &m);
        solve(1);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}