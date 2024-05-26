#include <bits/stdc++.h>
namespace solution
{
    typedef long long i64;
    const int MAXN = 2e5 + 5;
    const int MAXLOGN = 20 + 5;
    const int INF = 0x3f3f3f3f;
    int n;
    int p[MAXN];
    int minv[2][MAXN][MAXLOGN];
    int min(int x, int y)
    {
        return p[x] < p[y] ? x : y;
    }
    void init()
    {
        p[0] = INF;
        for (int i = 1; i <= n; i++)
        {
            for (int k = 0; k <= 1; k++)
            {
                if ((i & 1) == k)
                {
                    minv[k][i][0] = i;
                }
            }
        }
        for (int i = 1; i <= std::__lg(n); i++)
        {
            for (int l = 1, r = 1 << i; r <= n; l++, r++)
            {
                for (int k = 0; k <= 1; k++)
                {
                    minv[k][l][i] = min(minv[k][l][i - 1], minv[k][l + (1 << (i - 1))][i - 1]);
                }
            }
        }
    }
    int query(int k, int l, int r)
    {
        int len = std::__lg(r - l + 1);
        return min(minv[k][l][len], minv[k][r - (1 << len) + 1][len]);
    }
    struct Node
    {
        int l, r, v;
        Node(int _l, int _r) : l(_l), r(_r), v(l <= r ? p[query(l & 1, l, r)] : INF) {}
    };
    bool operator>(const Node &a, const Node &b)
    {
        return a.v > b.v;
    }
    std::priority_queue<Node, std::vector<Node>, std::greater<Node>> q;
    void insert(int l, int r)
    {
        if (l < r)
        {
            q.push(Node(l, r));
        }
    }
    int main()
    {
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &p[i]);
        }
        init();
        insert(1, n);
        while (!q.empty())
        {
            auto now = q.top();
            q.pop();
            int l = now.l, r = now.r;
            int ansl = query(l & 1, l, r);
            int ansr = query((l & 1) ^ 1, ansl + 1, r);
            printf("%d %d ", p[ansl], p[ansr]);
            insert(l, ansl - 1), insert(ansl + 1, ansr - 1), insert(ansr + 1, r);
        }
        puts("");
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}