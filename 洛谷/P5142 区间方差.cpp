#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
const int MAXN = 1e5 + 5;
const int MOD = 1e9 + 7;

template <typename T> void read(T& x)
{
	T res = 0, s = 1;
	char ch;
	while ((ch = getchar()) < '0' || ch > '9')    if (ch == '-')    s = -1;
	while (ch >= '0' && ch <= '9')                res = res * 10 + ch - '0', ch = getchar();
	x = res * s;
}
template <typename First, typename... Rest> void read(First& first, Rest&... rest)
{
	read(first);
	read(rest...);
}
void write()
{
	putchar('\n');
}
void write(char ch)
{
	putchar(ch);
}
template <typename T> void write(char delimiter, T x)
{
	if (x < 0)    putchar('-'), x = -x;
	if (x > 9)    write(delimiter, x / 10);
	putchar((x % 10) + '0');
}
template <typename First, typename... Rest> void write(char delimiter, First& first, Rest&... rest)
{
	write(delimiter, first);
	putchar(delimiter);
	if (sizeof...(rest) >= 1)
	{
		write(delimiter, rest...);
	}
}
template <typename First, typename... Rest> void write(char delimiter, char linedelimiter, First& first, Rest&... rest)
{
	write(delimiter, first);
	putchar(delimiter);
	if (sizeof...(rest) >= 1)
	{
		write(delimiter, rest...);
	}
	putchar(linedelimiter);
}
template <typename... T> void write(T... t)
{
	write(' ', '\n', t...);
}

LL qpow(LL x, LL a = MOD - 2)
{
    LL res = 1;
    while (a)
    {
        if (a & 1)
        {
            res = res * x % MOD;
        }
        x = x * x % MOD;
        a = a >> 1;
    }
    return res % MOD;
}

struct Node
{
    LL sqr, sum;
    Node()
    {

    }
    Node(LL a, LL b) : sqr(a), sum(b)
    {

    }
};
Node operator+(Node a, Node b)
{
    return Node((a.sqr + b.sqr) % MOD, (a.sum + b.sum) % MOD);
}
int n, m;
LL a[MAXN];
Node node[MAXN << 2];
void pushup(int o, int l, int r)
{
    node[o].sum = node[o << 1].sum + node[o << 1 | 1].sum;
    node[o].sqr = node[o << 1].sqr + node[o << 1 | 1].sqr;
    node[o].sum %= MOD, node[o].sqr %= MOD;
}
void build(int o, int l, int r)
{
    if (l == r)
    {
        node[o].sum = a[l], node[o].sqr = a[l] * a[l];
        node[o].sum %= MOD, node[o].sqr %= MOD;
        return;
    }
    int mid = (l + r) >> 1;
    build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);
    pushup(o, l, r);
}
void update(int o, int l, int r, int x, int v)
{
    if (l == r)
    {
        node[o].sum = v, node[o].sqr = v * v;
        node[o].sum %= MOD, node[o].sqr %= MOD;
        return;
    }
    int mid = (l + r) >> 1;
    if (x <= mid)
    {
        update(o << 1, l, mid, x, v);
    }
    if (x > mid)
    {
        update(o << 1 | 1, mid + 1, r, x, v);
    }
    pushup(o, l, r);
}
Node query(int o, int l, int r, int ql, int qr)
{
    if (l == r)
    {
        return node[o];
    }
    int mid = (l + r) >> 1;
    if (mid >= ql && mid < qr)
    {
        return query(o << 1, l, mid, ql, qr) + query(o << 1 | 1, mid + 1, r, ql ,qr);
    }
    if (mid >= ql)
    {
        return query(o << 1, l, mid, ql, qr);
    }
    if (mid < qr)
    {
        return query(o << 1, mid + 1, r, ql, qr);
    }
    return Node();
}

LL solve(int l, int r)
{
    Node tmp = query(1, 1, n, l, r);
    int res = tmp.sqr * (r - l + 1) - tmp.sum * tmp.sum;
    res = (res % MOD + MOD) % MOD;
    res = qpow((r - l + 1) * (r - l + 1), MOD - 2) * res % MOD;
    return res;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(nullptr), cout.tie(nullptr);
    read(n, m);
    for (int i = 1; i <= n; i++)
    {
        read(a[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int op, x, y;
        read(op, x, y);
        if (op == 1)
        {
            update(1, 1, n, x, y);
        }
        if (op == 2)
        {
            write(solve(x, y));
        }
    }
    return 0;
}