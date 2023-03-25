#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 100000;
struct Node
{
    LL sum;
    LL add;
    LL mul;
    Node(LL s = 0, LL a = 0, LL m = 1) : sum(s), add(a), mul(m)
    {
    }
};
LL mod;
LL a[MAXN + 5];
Node node[MAXN * 4 + 5];
void build(int o, int l, int r)
{
    if (l == r)
    {
        node[o].sum = a[l];
        node[o].mul = 1;
    }
    LL mid = (l + r) / 2;
    build(o * 2, l, mid);
    build(o * 2, mid + 1, r);
    node[o].sum = node[o * 2].sum + node[o * 2 + 1].sum;
    node[o].mul = 1;
}
void build(int len)
{
    build(1, 1, len);
}
void pushdown(int o, int l, int r)
{
    int mid = (l + r) / 2;
    node[o * 2].mul *= node[o].mul;
    node[o * 2 + 1].mul *= node[o].mul;
    node[o * 2].add = node[o].add + node[o].mul * node[o * 2].add;
    node[o * 2 + 1].add = node[o].add + node[o].mul * node[o * 2 + 1].add;
    node[o * 2].sum = node[o].mul * node[o * 2].sum + node[o * 2].add * (mid - l + 1);
    node[o * 2 + 1].sum = node[o].mul * node[o * 2 + 1].sum + node[o * 2 + 1].add * (r - mid);
    node[o].add = 0;
    node[o].mul = 1;
}
void update(int o, int ql, int qr, int l, int r, LL addon, LL mulon)
{
    if (ql <= l && r <= qr)
    {
        node[o].sum = (node[o].sum * mulon) % mod;
        node[o].add = (node[o].add + mulon * node[o].add) % mod;
        node[o].sum = (node[o].sum + addon * (r - l + 1)) % mod;
    }
    pushdown(o, l, r);
    int mid = (l + r) / 2;
    if (mid >= ql)
    {
        update(o * 2, ql, qr, l, mid, addon, mulon);
    }
    if (mid < qr)
    {
        update(o * 2 + 1, ql, qr, mid + 1, r, addon, mulon);
    }
}
int main()
{
    return 0;
}