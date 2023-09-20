#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    int n, k;
    LL ans = 0;
    struct Node
    {
        LL val, dep;
        Node(LL v, LL d) : val(v), dep(d) {}
    };
    bool operator>(const Node a, const Node b)
    {
        return a.val == b.val ? a.dep > b.dep : a.val > b.val;
    }
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
    int main()
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            LL val;
            scanf("%lld", &val);
            q.push(Node(val, 1));
        }
        while ((q.size() - 1) % (k - 1) != 0)
        {
            q.push(Node(0, 1));
        }
        while (q.size() > 1)
        {
            Node v(0, 0);
            for (int i = 1; i <= k; i++)
            {
                v.dep = std::max(v.dep, q.top().dep);
                v.val += q.top().val;
                q.pop();
            }
            v.dep++;
            ans += v.val;
            q.push(v);
        }
        printf("%lld\n%lld\n", ans, q.top().dep - 1);
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}