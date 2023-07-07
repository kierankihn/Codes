#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 5e4 + 5;
int n;
int q;
int a[MAXN];

LL readInt()
{
    LL tmp = 0, s = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
        {
            s = -1;
        }
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        tmp = tmp * 10 + ch - '0', ch = getchar();
    }
    return tmp * s;
}
void writeInt(LL x)
{
    if (x < 0)
    {
        putchar('-'), writeInt(-x);
        return;
    }
    if (x >= 10)
    {
        writeInt(x / 10);
    }
    putchar(x % 10 + '0');
}

struct Node
{
    LL lsum, rsum, sum, max;
    Node()
    {

    }
};
Node operator+(Node a, Node b)
{
    Node ans;
    ans.lsum = max(a.lsum, a.sum + b.lsum);
    ans.rsum = max(b.rsum, b.sum + a.rsum);
    ans.sum = a.sum + b.sum;
    ans.max = max(max(a.max, b.max), a.rsum + b.lsum);
    return ans;
}
Node node[MAXN << 2];
void pushup(int o, int l, int r)
{
    node[o] = node[o << 1] + node[o << 1 | 1];
}
void build(int o, int l, int r)
{
    if (l == r)
    {
        node[o].sum = node[o].max = node[o].lsum = node[o].rsum = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);
    pushup(o, l, r);
}
void build()
{
    build(1, 1, n);
}
void update(int o, int l, int r, int x, int v)
{
    if (l == r)
    {
        node[o].sum += v, node[o].max += v, node[o].lsum += v, node[o].rsum += v;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        update(o, l, mid, x, v);
    }
    if (x > mid)
    {
        update(o, mid + 1, r, x, v);
    }
    pushup(o, l, r);
}
void update(int x, int v)
{
    update(1, 1, n, x, v);
}
Node query(int o, int l, int r, int ql, int qr)
{
    if (ql <= l && r <= qr)
    {
        return node[o];
    }
    int mid = (l + r) >> 1;
    if (mid >= ql && mid < qr)
    {
        return query(o << 1, l, mid, ql, qr) + query(o << 1 | 1, mid + 1, r, ql, qr);
    }
    if (mid >= ql)
    {
        return query(o << 1, l, mid, ql, qr);
    }
    if (mid < qr)
    {
        return query(o << 1 | 1, mid + 1, r, ql, qr);
    }
    return Node();
}
LL query(int l, int r)
{
    return query(1, 1, n, l, r).max;
}

int main()
{
    n = readInt();
    for (int i = 1; i <= n; i++)
    {
        a[i] = readInt();
    }
    build();
    q = readInt();
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        l = readInt(), r = readInt();
        writeInt(query(l, r)), putchar('\n');
    }
    return 0;
}