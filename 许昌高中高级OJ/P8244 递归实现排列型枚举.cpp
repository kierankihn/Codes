#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 9;
    int n;
    std::vector<int> nums;
    bool vis[MAXN];
    void solve(int x)
    {
        if ((int)nums.size() == n)
        {
            for (auto &i : nums)
            {
                printf("%d ", i);
            }
            printf("\n");
            return;
        }
        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
            {
                continue;
            }
            vis[i] = true, nums.push_back(i);
            solve(x + 1);
            vis[i] = false, nums.pop_back();
        }
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