#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
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
inline void write(int x)
{
    if (x < 0)
    {
        putchar('-'), x = -x;
    }
    if (x > 9)
    {
        write(x / 10);
    }
    putchar(x % 10 + '0');
    return;
}

struct Node
{
    int cnt;
    int len;
    Node() : cnt(0), len(0)
    {
        // nothing
    }
};
struct Edge
{
    int x;
    pair<int, int> y;
    int k;
    Edge(int x_, int y1_, int y2_, int k_) : x(x_), y(pair<int, int>(y1_, y2_)), k(k_)
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
int n;
int m;
int ans = 0;
Node node[MAXN * 16];
vector<int> rk;
vector<int> raw;
vector<Edge> edge;
void updatelen(int o, int l, int r)
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
void update(int o, int l, int r, int ql, int qr, int val)
{
    if (ql <= l && r <= qr)
    {
        node[o].cnt += val;
        updatelen(o, l, r);
        return;
    }
    int mid = (l + r) >> 1;
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
    n = readInt();
    for (int i = 1; i <= n; i++)
    {
        pair<int, int> x, y;
        x.first = readInt();
        y.first = readInt();
        x.second = readInt();
        y.second = readInt();
        rk.push_back(y.first);
        rk.push_back(y.second);
        edge.push_back(Edge(x.first, y.first, y.second, 1));
        edge.push_back(Edge(x.second, y.first, y.second, -1));
    }
    sort(rk.begin(), rk.end());
    m = unique(rk.begin(), rk.end()) - rk.begin();
    raw.resize(m);
    for (int i = 0; i < 2 * n; i++)
    {
        pair<int, int> newy;
        newy.first = lower_bound(rk.begin(), rk.end(), edge[i].y.first) - rk.begin();
        newy.second = lower_bound(rk.begin(), rk.end(), edge[i].y.second) - rk.begin();
        raw[newy.first] = edge[i].y.first;
        raw[newy.second] = edge[i].y.second;
        edge[i].y = newy;
    }
    sort(edge.begin(), edge.end());
    for (int i = 0; i < n << 1; i++)
    {
        update(1, 1, m, edge[i].y.first, edge[i].y.second, edge[i].k);
        ans += node[1].cnt * (edge[i + 1].x - edge[i].x);
        write(node[1].cnt);
        putchar(' ');
    }
    putchar('\n');
    write(ans);
    putchar('\n');
    return 0;
}
