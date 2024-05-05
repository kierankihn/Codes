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
    long long reads()
    {
        long long res;
        read(res);
        return res;
    }
    template <typename T>
    void readAll(T *begin, T *end)
    {
        for (T *i = begin; i != end; i++)
        {
            basic_IO::__read(*i);
        }
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

    const int MAXN = 1e6 + 5;
    const int INF  = 1e9 + 5;

    struct Node
    {
        int min, max, sum;
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {std::min(a.min, b.min), std::max(a.max, b.max), a.sum + b.sum};
    }

    int n, m;
    int a[MAXN];

    Node node[MAXN << 2];
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o] = {a[l], a[l], 1};
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);
        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    Node query(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            return node[o];
        }

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

        return {INF, -INF, 0};
    }
    void update(int x, int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o] = {INF, -INF, 0};
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, o << 1, l, mid);
        }
        else
        {
            update(x, o << 1 | 1, mid + 1, r);
        }

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    int find(int x, int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            return l;
        }

        int mid = (l + r) >> 1;
        if (x <= node[o << 1].sum)
        {
            return find(x, o << 1, l, mid);
        }
        else
        {
            return find(x - node[o << 1].sum, o << 1 | 1, mid + 1, r);
        }
    }

    int main()
    {
        read(n, m);
        readAll(a + 1, a + n + 1);

        build();

        for (int i = 1; i <= m; i++)
        {
            int op = reads();

            if (op == 1)
            {
                int k = reads();
                update(find(k));
            }
            if (op == 2)
            {
                int l = reads(), r = reads();

                auto res = query(find(l), find(r));

                write(res.min, res.max);
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