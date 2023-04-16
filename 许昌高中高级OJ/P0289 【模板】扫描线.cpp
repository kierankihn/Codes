#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const ull MAXN = 1e5 + 5;
inline int readInt()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            f = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}
inline void write(ull x)
{
    if (x > 9)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
    return;
}
struct Node
{
    ull cnt;
    ull len;
    Node() : cnt(0), len(0)
    {
        // nothing
    }
};
struct Edge
{
    ull x;
    pair<ull, ull> y;
    ull k;
    Edge() : x(0), y(pair<ull, ull>(0, 0)), k(0)
    {
        // nothing
    }
    Edge(ull x_, ull y1_, ull y2_, ull k_) : x(x_), y(pair<ull, ull>(y1_, y2_)), k(k_)
    {
        // nothing
    }
    bool operator<(Edge a)
    {
        if (a.x == x)
        {
            return k < a.k;
        }
        return x < a.x;
    }
};
ull n;
ull m;
ull ans = 0;
Node node[MAXN * 16];
ull rk[MAXN * 2];
ull raw[MAXN * 2];
Edge edge[MAXN * 2];
void updatelen(ull o, ull l, ull r)
{
    if (node[o].cnt)
    {
        node[o].len = raw[r + 1] - raw[l];
    }
    else
    {
        node[o].len = node[o * 2].len + node[o * 2 + 1].len;
    }
}
void update(ull o, ull l, ull r, ull ql, ull qr, ull val)
{
    if (ql <= l && r <= qr)
    {
        node[o].cnt += val;
        updatelen(o, l, r);
        return;
    }
    ull mid = (l + r) >> 1;
    if (mid >= ql)
    {
        update(o * 2, l, mid, ql, qr, val);
    }
    if (mid < qr)
    {
        update(o * 2 + 1, mid + 1, r, ql, qr, val);
    }
    updatelen(o, l, r);
}
int main()
{
    memset(rk, 0, sizeof(rk));
    memset(raw, 0, sizeof(raw));
    n = readInt();
    for (ull i = 1; i <= n; i++)
    {
        pair<ull, ull> x, y;
        x.first = readInt();
        y.first = readInt();
        x.second = readInt();
        y.second = readInt();
        rk[i * 2 - 1] = y.first;
        rk[i * 2] = y.second;
        edge[i * 2 - 1] = (Edge(x.first, y.first, y.second, 1));
        edge[i * 2] = (Edge(x.second, y.first, y.second, -1));
    }
    sort(rk + 1, rk + 2 * n + 1);
    m = unique(rk + 1, rk + 2 * n + 1) - rk - 1;
    for (ull i = 1; i <= 2 * n; i++)
    {
        pair<ull, ull> newy;
        newy.first = lower_bound(rk + 1, rk + m + 1, edge[i].y.first) - rk;
        newy.second = lower_bound(rk + 1, rk + m + 1, edge[i].y.second) - rk;
        raw[newy.first] = edge[i].y.first;
        raw[newy.second] = edge[i].y.second;
        edge[i].y = newy;
    }
    sort(edge + 1, edge + 2 * n + 1);
    for (ull i = 1; i < (n << 1); i++)
    {
        update(1, 1, m, edge[i].y.first, edge[i].y.second - 1, edge[i].k);
        ans += node[1].len * (edge[i + 1].x - edge[i].x);
    }
    write(ans);
    putchar('\n');
    return 0;
}
