#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e6 + 5;
    const int INF = 0x3f3f3f3f;
    int q;
    std::stack<int> l, r;
    int sum[MAXN], max[MAXN];
    int main()
    {
        for (auto &i : max)
        {
            i = -INF;
        }
        scanf("%d", &q);
        for (int i = 1; i <= q; i++)
        {
            char op;
            scanf("%s", &op);
            if (op == 'I')
            {
                int x;
                scanf("%d", &x);
                l.push(x);
                sum[l.size()] = sum[l.size() - 1] + l.top();
                max[l.size()] = std::max(max[l.size() - 1], sum[l.size()]);
            }
            if (op == 'D')
            {
                if (!l.empty())
                {
                    l.pop();
                }
                max[l.size() + 1] = -INF;
            }
            if (op == 'L')
            {
                if (!l.empty())
                {
                    r.push(l.top());
                    l.pop();
                }
            }
            if (op == 'R')
            {
                if (!r.empty())
                {
                    l.push(r.top());
                    r.pop();
                    sum[l.size()] = sum[l.size() - 1] + l.top();
                    max[l.size()] = std::max(max[l.size() - 1], sum[l.size()]);
                }
            }
            if (op == 'Q')
            {
                int x;
                scanf("%d", &x);
                printf("%d\n", max[x]);
            }
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}