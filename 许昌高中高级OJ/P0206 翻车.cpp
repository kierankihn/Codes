#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    int n, k, m;
    int a[MAXN];
    std::vector<int> z[MAXN];
    int main()
    {
        scanf("%d%d%d", &n, &k, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            z[a[i] % m].push_back(a[i]);
        }
        for (int i = 0; i < m; i++)
        {
            if (z[i].size() >= k)
            {
                std::puts("Yes");
                for (int j = 0; j < k; j++)
                {
                    printf("%d ", z[i][j]);
                }
                printf("\n");
                exit(0);
            }
        }
        std::puts("No");
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}