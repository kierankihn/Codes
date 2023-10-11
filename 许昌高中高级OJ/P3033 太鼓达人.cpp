#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXK = 12 + 5;
    const int MAX2K = 1 << MAXK;
    int k;
    std::string ans;
    bool vis[MAX2K];
    bool dfs(int u, int cnt)
    {
        if (vis[u])
        {
            return false;
        }
        if (cnt == (1 << k))
        {
            return true;
        }
        vis[u] = true;
        if (dfs(((u << 1) & ((1 << k) - 1)), cnt + 1))
        {
            ans = '0' + ans;
            return true;
        }
        if (dfs(((u << 1) & ((1 << k) - 1)) | 1, cnt + 1))
        {
            ans = '1' + ans;
            return true;
        }
        vis[u] = false;
        return false;
    }
    int main()
    {
        scanf("%d", &k);
        dfs(0, 1);
        for (int i = 1; i <= k; i++)
        {
            ans = '0' + ans;
        }
        printf("%d %s\n", 1 << k, ans.substr(0, ans.size() - k + 1).c_str());
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}