#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 2e5 + 5;
    int n;
    int ans = 0;
    struct Node
    {
        int val, rank;
    };
    bool operator<(const Node a, const Node b)
    {
        return (a.val == b.val) ? (a.rank < b.rank) : (a.val < b.val);
    }
    Node node[MAXN];
    int max[MAXN], min[MAXN], tot;
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &node[i].val);
            node[i].rank = i;
        }
        std::sort(node + 1, node + n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (i == 1 || node[i].val != node[i - 1].val)
            {
                tot++;
                max[tot] = node[i].rank;
                min[tot] = node[i].rank;
            }
            else
            {
                max[tot] = std::max(max[tot], node[i].rank);
                min[tot] = std::min(min[tot], node[i].rank);
            }
        }
        for (int i = 1; i <= tot; i++)
        {
            // printf("%d ", i);
            while (max[i + 1] < min[i] && i < tot)
            {
                i++;
            }
            i++;
            while (max[i] < min[i + 1] && i < tot)
            {
                i++;
            }
            // printf("%d\n", i);
            ans++;
        }
        printf("%d\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}