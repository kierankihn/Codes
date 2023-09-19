#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXF = 6;
    const int MAXN = 1e5 + 5;
    const int delta[12][6] = {{0, 1, 2, 3, 4, 5},
                              {1, 2, 3, 4, 5, 0},
                              {2, 3, 4, 5, 0, 1},
                              {3, 4, 5, 0, 1, 2},
                              {4, 5, 0, 1, 2, 3},
                              {5, 0, 1, 2, 3, 4},
                              {5, 4, 3, 2, 1, 0},
                              {4, 3, 2, 1, 0, 5},
                              {3, 2, 1, 0, 5, 4},
                              {2, 1, 0, 5, 4, 3},
                              {1, 0, 5, 4, 3, 2},
                              {0, 5, 4, 3, 2, 1}};
    int n;
    struct Snow
    {
        int val[MAXF];
    };
    bool operator<(const Snow a, const Snow b)
    {
        for (int i = 0; i < MAXF; i++)
        {
            if (a.val[i] != b.val[i])
            {
                return a.val[i] < b.val[i];
            }
        }
        return false;
    }
    std::set<Snow> s;
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            Snow now, nxt;
            for (int j = 0; j < MAXF; j++)
            {
                scanf("%d", &now.val[j]);
            }
            for (auto &j : delta)
            {
                for (int k = 0; k < MAXF; k++)
                {
                    nxt.val[k] = now.val[j[k]];
                    // printf("%d ", nxt.val[k]);
                }
                // printf("\n");
                if (s.count(nxt))
                {
                    puts("Twin snowflakes found.");
                    return 0;
                }
            }
            s.insert(now);
        }
        puts("No two snowflakes are alike.");
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}