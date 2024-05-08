#pragma GCC optimize(3, "Ofast", "inline")
#include <bits/stdc++.h>
namespace IO
{
    namespace basic_IO
    {
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __read(T &x)
        {
            char ch;
            T res = 0, f = 1;
            while (std::isdigit(ch = getchar()) == false)
            {
                f = (ch != '-');
            }
            do
            {
                res = res * 10 + (ch - '0');
            } while (std::isdigit(ch = getchar()) == true);
            x = res * (f ? 1 : -1);
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __read(T &x)
        {
            std::cin >> x;
        }
        template <typename First, typename... Rest>
        void __read(First &first, Rest &...rest)
        {
            __read(first);
            __read(rest...);
        }
        template <typename T>
        typename std::enable_if<std::is_integral<T>::value>::type __write(T x)
        {
            if (x < 0)
            {
                std::putchar('-'), __write(-x);
                return;
            }
            if (x >= 10)
            {
                __write(x / 10);
            }
            std::putchar(x % 10 + '0');
        }
        template <typename T>
        typename std::enable_if<!std::is_integral<T>::value>::type __write(T x)
        {
            std::cout << x;
        }
        template <typename First, typename... Rest>
        void __write(First first, Rest... rest)
        {
            __write(first), std::putchar(' '), __write(rest...);
        }
    }  // namespace basic_IO
    template <typename First, typename... Rest>
    void read(First &first, Rest &...rest)
    {
        basic_IO::__read(first, rest...);
    }
    template <typename T>
    void readAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__read(*i);
        }
    }
    long long readi()
    {
        long long res;
        read(res);
        return res;
    }
    std::string reads()
    {
        std::string res;
        read(res);
        return res;
    }
    template <typename First, typename... Rest>
    void write(First first, Rest... rest)
    {
        basic_IO::__write(first, rest...), std::putchar('\n');
    }
    template <typename T>
    void writeAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__write(*i), std::putchar(' ');
        }
        std::putchar('\n');
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef long long i64;

    const int MAXN = 4e5 + 5;

    struct Node
    {
        int sum;
        int lson, rson;
    };

    int n;
    int m = 1;
    int a[MAXN];
    int son[MAXN][2];

    i64 ans = 0;

    void input(int x)
    {
        read(a[x]);
        if (a[x] == 0)
        {
            input(son[x][0] = ++m);
            input(son[x][1] = ++m);
        }
    }

    int size = 0;
    int root[MAXN];

    Node node[MAXN << 6];
    void pushup(int o)
    {
        node[o].sum = node[node[o].lson].sum + node[node[o].rson].sum;
    }
    void update(int x, int v, int o, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o].sum += v;
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            if (node[o].lson == 0)
            {
                node[o].lson = ++size;
            }
            update(x, v, node[o].lson, l, mid);
        }
        if (x > mid)
        {
            if (node[o].rson == 0)
            {
                node[o].rson = ++size;
            }
            update(x, v, node[o].rson, mid + 1, r);
        }

        pushup(o);
    }
    int query(int ql, int qr, int o, int l = 1, int r = n)
    {
        if (ql > qr || o == 0)
        {
            return 0;
        }
        if (ql <= l && r <= qr)
        {
            return node[o].sum;
        }

        int res = 0;
        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            res += query(ql, qr, node[o].lson, l, mid);
        }
        if (mid < qr)
        {
            res += query(ql, qr, node[o].rson, mid + 1, r);
        }

        return res;
    }

    void upd(int x, int o, int l = 1, int r = n)
    {
        if (o == 0)
        {
            return;
        }
        if (l == r)
        {
            update(l, node[o].sum, x);
        }

        int mid = (l + r) >> 1;
        upd(x, node[o].lson, l, mid), upd(x, node[o].rson, mid + 1, r);
    }
    i64 calc(int x, int o, int l = 1, int r = n)
    {
        if (o == 0)
        {
            return 0;
        }
        if (l == r)
        {
            return query(1, l - 1, x);
        }

        int mid = (l + r) >> 1;
        return calc(x, node[o].lson, l, mid) + calc(x, node[o].rson, mid + 1, r);
    }
    void solve(int u)
    {
        if (son[u][0] == 0)
        {
            update(a[u], 1, root[u] = ++size);
            return;
        }

        solve(son[u][0]), solve(son[u][1]);

        if (node[root[son[u][0]]].sum > node[root[son[u][1]]].sum)
        {
            std::swap(son[u][0], son[u][1]);
        }

        root[u] = root[son[u][1]];
        i64 res = calc(root[u], root[son[u][0]]);

        ans += std::min(res, (i64)node[root[son[u][0]]].sum * node[root[son[u][1]]].sum - res);

        upd(root[u], root[son[u][0]]);
    }

    int main()
    {
        read(n), input(1);

        solve(1);

        write(ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}