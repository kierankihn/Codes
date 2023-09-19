#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    const int INF = 0x3f3f3f3f;
    int n;
    struct Node
    {
        int val, rank;
        Node() {}
        Node(int x, int y) : val(x), rank(y) {}
    };
    bool operator<(const Node a, const Node b)
    {
        return a.val < b.val;
    }
    Node node[MAXN];
    int rev[MAXN];
    int l[MAXN], r[MAXN];
    int res[MAXN], pos[MAXN];
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
            l[i] = i - 1, r[i] = i + 1, rev[node[i].rank] = i;
        }
        for (int i = n; i >= 2; i--)
        {
            if (l[rev[i]] < 1)
            {
                res[i] = node[r[rev[i]]].val - node[rev[i]].val, pos[i] = node[r[rev[i]]].rank;
            }
            if (r[rev[i]] > n)
            {
                res[i] = node[rev[i]].val - node[l[rev[i]]].val, pos[i] = node[l[rev[i]]].rank;
            }
            if (1 <= l[rev[i]] && r[rev[i]] <= n)
            {
                if (node[rev[i]].val - node[l[rev[i]]].val <= node[r[rev[i]]].val - node[rev[i]].val)
                {
                    res[i] = node[rev[i]].val - node[l[rev[i]]].val, pos[i] = node[l[rev[i]]].rank;
                }
                else
                {
                    res[i] = node[r[rev[i]]].val - node[rev[i]].val, pos[i] = node[r[rev[i]]].rank;
                }
            }
            l[r[rev[i]]] = l[rev[i]];
            r[l[rev[i]]] = r[rev[i]];
        }
        for (int i = 2; i <= n; i++)
        {
            printf("%d %d\n", res[i], pos[i]);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}