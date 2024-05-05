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

    const int MAXN = 1e5 + 5;

    struct Node
    {
        int sum[2];
        int begin[2], end[2], max[2];
        int tag  = -1;
        bool rev = false;
        Node()
        {
        }
        Node(const int sum0, const int sum1, const int begin0, const int begin1, const int end0, const int end1, const int max0, const int max1)
        {
            sum[0] = sum0, sum[1] = sum1;
            begin[0] = begin0, begin[1] = begin1;
            end[0] = end0, end[1] = end1;
            max[0] = max0, max[1] = max1;
        }

        void update_tag(int v)
        {
            tag = v, rev = false;
        }
        void update_rev(bool v)
        {
            rev ^= v;
        }
    };
    Node operator+(const Node a, const Node b)
    {
        return {
            a.sum[0] + b.sum[0],
            a.sum[1] + b.sum[1],
            a.sum[1] == 0 ? a.begin[0] + b.begin[0] : a.begin[0],
            a.sum[0] == 0 ? a.begin[1] + b.begin[1] : a.begin[1],
            b.sum[1] == 0 ? b.end[0] + a.end[0] : b.end[0],
            b.sum[0] == 0 ? b.end[1] + a.end[1] : b.end[1],
            std::max({a.max[0], b.max[0], a.end[0] + b.begin[0]}),
            std::max({a.max[1], b.max[1], a.end[1] + b.begin[1]})};
    }

    int n, m;
    int a[MAXN];

    Node node[MAXN << 2];
    void set(int o, int l, int r, int v)
    {
        int len = r - l + 1;
        if (v == 0)
        {
            node[o] = {len, 0, len, 0, len, 0, len, 0};
        }
        if (v == 1)
        {
            node[o] = {0, len, 0, len, 0, len, 0, len};
        }
    }
    void rev(int o, int l, int r)
    {
        std::swap(node[o].sum[0], node[o].sum[1]);
        std::swap(node[o].begin[0], node[o].begin[1]);
        std::swap(node[o].end[0], node[o].end[1]);
        std::swap(node[o].max[0], node[o].max[1]);
    }
    void pushdown(int o, int l, int r)
    {
        int mid = (l + r) >> 1;
        if (node[o].tag != -1)
        {
            set(o << 1, l, mid, node[o].tag), set(o << 1 | 1, mid + 1, r, node[o].tag);
            node[o << 1].update_tag(node[o].tag), node[o << 1 | 1].update_tag(node[o].tag);
            node[o].tag = -1;
        }
        if (node[o].rev != false)
        {
            rev(o << 1, l, mid), rev(o << 1 | 1, mid + 1, r);
            node[o << 1].update_rev(node[o].rev), node[o << 1 | 1].update_rev(node[o].rev);
            node[o].rev = false;
        }
    }
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            set(o, l, r, a[l]);
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);
        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void update(int ql, int qr, int v, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            set(o, l, r, v);
            node[o].update_tag(v);
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
    void reverse(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            rev(o, l, r);
            node[o].update_rev(true);
            return;
        }

        pushdown(o, l, r);

        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            reverse(ql, qr, o << 1, l, mid);
        }
        if (mid < qr)
        {
            reverse(ql, qr, o << 1 | 1, mid + 1, r);
        }

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    Node query(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
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

    int main()
    {
        read(n, m);
        readAll(a + 1, a + n + 1);

        build();

        for (int i = 1; i <= m; i++)
        {
            int op = reads(), l = reads() + 1, r = reads() + 1;
            if (op == 0)
            {
                update(l, r, 0);
            }
            if (op == 1)
            {
                update(l, r, 1);
            }
            if (op == 2)
            {
                reverse(l, r);
            }
            if (op == 3)
            {
                write(query(l, r).sum[1]);
            }
            if (op == 4)
            {
                write(query(l, r).max[1]);
            }

            // for (int i = 1; i <= n; i++)
            // {
            //     basic_IO::__write(query(i, i).sum[1]), putchar(' ');
            // }
            // putchar('\n');
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}