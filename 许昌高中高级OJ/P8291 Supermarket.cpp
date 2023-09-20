#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 10000 + 5;
    int n;
    int now = 0;
    int ans = 0;
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    struct Node
    {
        int p, d;
    };
    bool operator<(const Node a, const Node b)
    {
        return a.d < b.d;
    }
    Node node[MAXN];
    int main()
    {
        while (scanf("%d", &n))
        {
            now = ans = 0;
            while (!q.empty())
            {
                q.pop();
            }
            for (int i = 1; i <= n; i++)
            {
                scanf("%d%d", &node[i].p, &node[i].d);
            }
            std::sort(node + 1, node + n + 1);
            for (int i = 1; i <= n; i++)
            {
                if (now + 1 <= node[i].d)
                {
                    ans += node[i].p;
                    q.push(node[i].p);
                    now++;
                }
                else
                {
                    if (!q.empty() && node[i].p > q.top())
                    {
                        ans += node[i].p - q.top();
                        q.pop();
                        q.push(node[i].p);
                    }
                }
            }
            printf("%d\n", ans);
        }
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}