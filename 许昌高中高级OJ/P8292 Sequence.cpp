#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXM = 100 + 5;
    const int MAXN = 2000 + 5;
    int t;
    int n, m;
    int a[MAXN];
    int b[MAXN];
    int sum[MAXN];
    struct Node
    {
        int i, j;
        bool lst;
        Node(int i_ = 0, int j_ = 0, bool lst_ = false) : i(i_), j(j_), lst(lst_) {}
    };
    bool operator>(const Node x, const Node y)
    {
        return a[x.i] + b[x.j] > a[y.i] + b[y.j];
    }
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
    int main()
    {
        scanf("%d", &t);
        while (t--)
        {
            scanf("%d%d", &m, &n);
            for (int i = 1; i <= n; i++)
            {
                scanf("%d", &a[i]);
            }
            std::sort(a + 1, a + n + 1);
            for (int i = 1; i < m; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    scanf("%d", &b[j]);
                }
                std::sort(b + 1, b + n + 1);
                while (!q.empty())
                {
                    q.pop();
                }
                q.push(Node(1, 1, false));
                for (int j = 1; j <= n; j++)
                {
                    Node u = q.top();
                    q.pop();
                    sum[j] = a[u.i] + b[u.j];
                    if (u.i + 1 <= n && u.lst == false)
                    {
                        q.push(Node(u.i + 1, u.j, false));
                    }
                    if (u.j + 1 <= n)
                    {
                        q.push(Node(u.i, u.j + 1, true));
                    }
                }
                for (int j = 1; j <= n; j++)
                {
                    a[j] = sum[j];
                }
            }
            for (int i = 1; i <= n; i++)
            {
                printf("%d%c", a[i], i == n ? '\n' : ' ');
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