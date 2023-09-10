#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    int n, m;
    std::vector<int> nums;
    void solve(int x)
    {
        if (x == n + 1)
        {
            for (auto &i : nums)
            {
                printf("%d ", i);
            }
            printf("\n");
            return;
        }
        solve(x + 1);
        nums.push_back(x);
        solve(x + 1);
        nums.pop_back();
    }
    int main()
    {
        scanf("%d", &n);
        solve(1);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}