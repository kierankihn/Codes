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
    long long reads()
    {
        long long res;
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

    const int MAXN = 2e5 + 5;

    struct Node
    {
        int sum0, sum1;
        int begin, end, max;
        int tag = -1;
    };
    Node operator+(const Node a, const Node b)
    {
        return {
            a.sum0 + b.sum0,
            a.sum1 + b.sum1,
            a.sum1 == 0 ? a.begin + b.begin : a.begin,
            b.sum1 == 0 ? b.end + a.end : b.end,
            std::max({a.max, b.max, a.end + b.begin})};
    }

    int n, m;

    Node node[MAXN << 2];
    void set(int o, int l, int r, int v)
    {
        int len = r - l + 1;
        if (v == 0)
        {
            node[o].sum0 = len, node[o].sum1 = 0;
        }
        if (v == 1)
        {
            node[o].sum0 = 0, node[o].sum1 = len;
        }

        node[o].begin = node[o].end = node[o].max = node[o].sum0;
    }
    void pushdown(int o, int l, int r)
    {
        int mid = (l + r) >> 1;
        if (node[o].tag != -1)
        {
            set(o << 1, l, mid, node[o].tag), set(o << 1 | 1, mid + 1, r, node[o].tag);
            node[o << 1].tag = node[o << 1 | 1].tag = node[o].tag, node[o].tag = -1;
        }
    }
    void build(int o = 1, int l = 0, int r = n)
    {
        if (l == r)
        {
            set(o, l, r, 1);
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void update(int ql, int qr, int v, int o = 1, int l = 0, int r = n)
    {
        if (ql > qr)
        {
            return;
        }
        if (ql <= l && r <= qr)
        {
            set(o, l, r, v), node[o].tag = v;
            return;
        }

        pushdown(o, l, r);

        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            update(ql, qr, v, o << 1, l, mid);
        }
        if (mid < qr)
        {
            update(ql, qr, v, o << 1 | 1, mid + 1, r);
        }

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    Node query(int ql, int qr, int o = 1, int l = 0, int r = n)
    {
        if (ql > qr)
        {
            return {};
        }
        if (ql <= l && r <= qr)
        {
            return node[o];
        }

        pushdown(o, l, r);

        int mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            return query(ql, qr, o << 1, l, mid) + query(ql, qr, o << 1 | 1, mid + 1, r);
        }
        if (mid >= ql)
        {
            return query(ql, qr, o << 1, l, mid);
        }
        if (mid < qr)
        {
            return query(ql, qr, o << 1 | 1, mid + 1, r);
        }

        return {};
    }
    int find(int x, int o = 1, int l = 0, int r = n)
    {
        if (l == r)
        {
            return l;
        }

        pushdown(o, l, r);

        int mid = (l + r) >> 1;
        if (x <= node[o << 1].sum0)
        {
            return find(x, o << 1, l, mid);
        }
        else
        {
            return find(x - node[o << 1].sum0, o << 1 | 1, mid + 1, r);
        }
    }

    int main()
    {
        read(n, m);

        build();

        for (int i = 1; i <= m; i++)
        {
            int op = reads();
            if (op == 0)
            {
                int l = reads(), r = reads();
                update(l, r, 0);
            }
            if (op == 1)
            {
                int l0 = reads(), r0 = reads(), l1 = reads(), r1 = reads(), sum = query(l0, r0).sum1;

                update(l0, r0, 0);

                r1 = std::min(r1, find(sum + query(0, l1 - 1).sum0));

                update(l1, r1, 1);
            }
            if (op == 2)
            {
                int l = reads(), r = reads();

                write(query(l, r).max);
            }
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}