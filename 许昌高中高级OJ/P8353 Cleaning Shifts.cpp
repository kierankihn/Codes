#include <bits/stdc++.h>
namespace solution
{
    typedef long long LL;
    const int MAXN = 25000 + 5;
    const int MAXT = 1e6 + 5;
    const int INF = 0x3f3f3f3f;
    int n, t;
    struct Node
    {
        int start, end;
    };
    bool operator<(const Node &a, const Node &b)
    {
        if (a.end == b.end)
        {
            return a.start < b.start;
        }
        return a.end < b.end;
    }
    Node node[MAXN];
    int min[MAXT << 2];
    void update(int o, int l, int r, int x, int v)
    {
        if (l == r)
        {
            min[o] = std::min(min[o], v);
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(o << 1, l, mid, x, v);
        }
        else
        {
            update(o << 1 | 1, mid + 1, r, x, v);
        }
        min[o] = std::min(min[o << 1], min[o << 1 | 1]);
    }
    int query(int o, int l, int r, int ql, int qr)
    {
        if (ql <= l && r <= qr)
        {
            return min[o];
        }
        int mid = (l + r) >> 1, res = INF;
        if (mid >= ql)
        {
            res = std::min(res, query(o << 1, l, mid, ql, qr));
        }
        if (mid < qr)
        {
            res = std::min(res, query(o << 1 | 1, mid + 1, r, ql, qr));
        }
        return res;
    }
    int main()
    {
        std::memset(min, 0x3f, sizeof(min));
        scanf("%d%d", &n, &t);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &node[i].start, &node[i].end);
        }
        std::sort(node + 1, node + n + 1);
        update(1, 0, t, 0, 0);
        for (int i = 1; i <= n; i++)
        {
            update(1, 0, t, node[i].end, query(1, 0, t, node[i].start - 1, node[i].end) + 1);
        }
        printf("%d\n", query(1, 0, t, t, t) == INF ? -1 : query(1, 0, t, t, t));
        return 0;
    }
}
int main()
{
    solution::main();
    return 0;
}