#include <bits/stdc++.h>
namespace input
{
    template <typename T>
    void read(T &x)
    {
        T res = 0, s = 1;
        char ch;
        while ((ch = getchar()) < '0' || ch > '9')
            if (ch == '-')
                s = -1;
        while (ch >= '0' && ch <= '9')
            res = res * 10 + ch - '0', ch = getchar();
        x = res * s;
    }
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        read(first);
        read(rest...);
    }
}
namespace output
{
    void write()
    {
        putchar('\n');
    }
    void write(char ch)
    {
        putchar(ch);
    }
    template <typename T>
    void write(char delimiter, T x)
    {
        if (x < 0)
            putchar('-'), x = -x;
        if (x > 9)
            write(delimiter, x / 10);
        putchar((x % 10) + '0');
    }
    template <typename First, typename... Rest>
    void write(char delimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
    }
    template <typename First, typename... Rest>
    void write(char delimiter, char linedelimiter, First &first, Rest &...rest)
    {
        write(delimiter, first);
        putchar(delimiter);
        if (sizeof...(rest) >= 1)
        {
            write(delimiter, rest...);
        }
        putchar(linedelimiter);
    }
    template <typename... T>
    void write(T... t)
    {
        write(' ', '\n', t...);
    }
}
namespace solution
{
    typedef long long LL;
    const int MAXN = 1e5 + 5;
    const double EXP = 1e-5;
    const LL V = 1e15;
    using input::read;
    using output::write;
    struct Node
    {
        LL sum;
        LL num;
        Node *ls, *rs;
        Node() : sum(0), num(0), ls(nullptr), rs(nullptr) {}
    };
    Node operator+(Node a, Node b)
    {
        Node c;
        c.num = a.num + b.num;
        c.sum = a.sum + b.sum;
        return c;
    }
    LL n, m;
    LL a[MAXN];
    Node *root = new Node();
    void pushup(Node *o, LL l, LL r)
    {
        o->num = o->sum = 0;
        if (o->ls)
        {
            o->num += o->ls->num;
            o->sum += o->ls->sum;
        }
        if (o->rs)
        {
            o->num += o->rs->num;
            o->sum += o->rs->sum;
        }
    }
    void update(Node *o, LL l, LL r, LL x, LL v)
    {
        if (l == r)
        {
            o->num += v;
            o->sum += x * v;
            return;
        }
        LL mid = (l + r) >> 1;
        if (mid >= x)
        {
            if (o->ls == nullptr)
            {
                o->ls = new Node();
            }
            update(o->ls, l, mid, x, v);
        }
        if (mid < x)
        {
            if (o->rs == nullptr)
            {
                o->rs = new Node();
            }
            update(o->rs, mid + 1, r, x, v);
        }
        pushup(o, l, r);
    }
    Node query(Node *o, LL l, LL r, LL ql, LL qr)
    {
        if (ql <= l && r <= qr)
        {
            return *o;
        }
        LL mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            if (o->ls && o->rs)
            {
                return query(o->ls, l, mid, ql, qr) + query(o->rs, mid + 1, r, ql, qr);
            }
            if (o->ls)
            {
                return query(o->ls, l, mid, ql, qr);
            }
            if (o->rs)
            {
                return query(o->rs, mid + 1, r, ql, qr);
            }
            return Node();
        }
        if (mid >= ql && o->ls)
        {
            return query(o->ls, l, mid, ql, qr);
        }
        if (mid < qr && o->rs)
        {
            return query(o->rs, mid + 1, r, ql, qr);
        }
        return Node();
    }
    bool check(double x, LL v)
    {
        Node res = query(root, 0, V, 0, x);
        return res.num * x - res.sum >= v;
    }
    int main()
    {
        std::cout.setf(std::ios::fixed);
        std::cout.precision(5);
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
            update(root, 0, V, a[i], 1);
        }
        for (int i = 1; i <= m; i++)
        {
            int op;
            read(op);
            if (op == 1)
            {
                LL x, v;
                read(x, v);
                update(root, 0, V, a[x], -1);
                a[x] = v;
                update(root, 0, V, a[x], 1);
            }
            if (op == 2)
            {
                LL v;
                double l = 0, r = V;
                read(v);
                while (l + EXP < r)
                {
                    double mid = (l + r) / 2;
                    if (check(mid, v))
                    {
                        r = mid;
                    }
                    else
                    {
                        l = mid;
                    }
                }
                std::cout << l << std::endl;
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