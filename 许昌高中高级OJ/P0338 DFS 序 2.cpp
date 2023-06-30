#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 5;
typedef long long LL;

int tot = 0;
int n, m, r;
int dep[MAXN], L[MAXN], R[MAXN], num[MAXN], a[MAXN], id[MAXN];

struct Edge
{
    int from, to;
    Edge(int u, int v) : from(u), to(v)
    {
        // nothing
    }
};
vector<Edge> edge;
vector<int> g[MAXN];
void add(int u, int v)
{
    edge.push_back(Edge(u, v));
    g[u].push_back(edge.size() - 1);
}

struct Node
{
    LL sum, tag;
};
Node node[MAXN << 2];
void build(int o, int l, int r)
{
    if (l == r)
    {
        node[o].sum = num[l];
        return;
    }
    int mid = (l + r) / 2;
    build(o * 2, l, mid);
    build(o * 2 + 1, mid + 1, r);
    node[o].sum = node[o * 2].sum + node[o * 2 + 1].sum;
}
void pushdown(int o, int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    node[o * 2].tag += node[o].tag;
    node[o * 2 + 1].tag += node[o].tag;
    node[o * 2].sum += node[o].tag * (mid - l + 1);
    node[o * 2 + 1].sum += node[o].tag * (r - mid);
    node[o].tag = 0;
}
LL query(int o, int ql, int qr, int l, int r)
{
    LL res = 0;
    int mid = (l + r) / 2;
    if (ql <= l && r <= qr)
    {
        return node[o].sum;
    }
    pushdown(o, l, r);
    if (mid >= ql)
    {
        res += query(o * 2, ql, qr, l, mid);
    }
    if (mid < qr)
    {
        res += query(o * 2 + 1, ql, qr, mid + 1, r);
    }
    return res;
}
LL query(int l, int r)
{
    return query(1, l, r, 1, n);
}
void update(int o, int ql, int qr, int l, int r, int v)
{
    int mid = (l + r) / 2;
    if (ql <= l && r <= qr)
    {
        node[o].sum += (LL)v * (r - l + 1);
        node[o].tag += v;
        return;
    }
    pushdown(o, l, r);
    if (mid >= ql)
    {
        update(o * 2, ql, qr, l, mid, v);
    }
    if (mid < qr)
    {
        update(o * 2 + 1, ql, qr, mid + 1, r, v);
    }
    node[o].sum = node[o * 2].sum + node[o * 2 + 1].sum;
}
void update(int l, int r, int v)
{
    update(1, l, r, 1, n, v);
}

void DFS(int x, int fa, int d)
{
    L[x] = ++tot, dep[x] = d, num[tot] = a[x], id[x] = tot;
    for (int &i : g[x])
    {
        Edge &e = edge[i];
        if (e.to == fa)
        {
            continue;
        }
        DFS(e.to, x, d + 1);
    }
    R[x] = tot;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        add(u, v), add(v, u);
    }
    DFS(r, 0, 1);
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int p, v;
            cin >> p >> v;
            update(L[p], R[p], v);
        }
        if (op == 2)
        {
            int x;
            cin >> x;
            cout << query(L[x], R[x]) << endl;
        }
    }
    return 0;
}