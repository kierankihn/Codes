#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    const int INF = 0x3f3f3f3f;
    int n, k;
    LL ans = 0;
    LL s[MAXN];
    struct Node
    {
        LL val;
        LL l, r;
        bool vis;
    };
    Node node[MAXN];
    struct Cmp
    {
        bool operator()(int a, int b)
        {
            return node[a].val > node[b].val;
        }
    };
    std::priority_queue<int, std::vector<int>, Cmp> q;
    int main()
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &s[i]);
        }
        for (int i = 1; i < n; i++)
        {
            node[i].val = s[i + 1] - s[i];
            node[i].l = i - 1, node[i].r = i + 1;
            q.push(i);
        }
        node[0].val = node[n].val = INF;
        for (int i = 1; i <= k; i++)
        {
            int id = q.top();
            q.pop();
            while (node[id].vis)
            {
                id = q.top();
                q.pop();
            }
            Node &u = node[id];
            ans += u.val;
            node[u.l].vis = true, node[u.r].vis = true;
            u.val = node[u.l].val + node[u.r].val - u.val;
            u.l = node[u.l].l, u.r = node[u.r].r;
            node[u.l].r = id, node[u.r].l = id;
            q.push(id);
        }
        printf("%lld\n", ans);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}