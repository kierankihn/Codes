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

    const int MAXN    = 1e4 + 5;
    const int MAXSIZE = 1e5 + 5;
    const int INF     = 0x3f3f3f3f;

    struct Cow
    {
        int a, b;
        int cost;
    };
    bool operator<(const Cow &a, const Cow &b)
    {
        return a.b < b.b || (a.b == b.b && a.a < b.a);
    }

    int n;
    int start, end;
    Cow cow[MAXN];

    int node[MAXSIZE << 2];
    void build(int o = 1, int l = 0, int r = end + 1)
    {
        if (l == r)
        {
            node[o] = INF;
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);
        node[o] = std::min(node[o << 1], node[o << 1 | 1]);
    }
    int query(int ql, int qr, int o = 1, int l = 0, int r = end + 1)
    {
        if (ql <= l && r <= qr)
        {
            return node[o];
        }

        int mid = (l + r) >> 1, res = INF;
        if (mid >= ql)
        {
            res = std::min(res, query(ql, qr, o << 1, l, mid));
        }
        if (mid < qr)
        {
            res = std::min(res, query(ql, qr, o << 1 | 1, mid + 1, r));
        }
        return res;
    }
    void update(int x, int v, int o = 1, int l = 0, int r = end + 1)
    {
        if (l == r)
        {
            node[o] = std::min(node[o], v);
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, v, o << 1, l, mid);
        }
        if (x > mid)
        {
            update(x, v, o << 1 | 1, mid + 1, r);
        }
        node[o] = std::min(node[o << 1], node[o << 1 | 1]);
    }

    int main()
    {
        read(n, start, end);
        for (int i = 1; i <= n; i++)
        {
            read(cow[i].a, cow[i].b, cow[i].cost);
        }
        std::sort(cow + 1, cow + n + 1);

        build();
        update(start, 0);

        for (int i = 1; i <= n; i++)
        {
            update(cow[i].b + 1, query(cow[i].a, cow[i].b) + cow[i].cost);
        }

        write(query(end + 1, end + 1) == INF ? -1 : query(end + 1, end + 1));

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}