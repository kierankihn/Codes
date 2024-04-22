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
            basic_IO::__write(*i);
        }
    }
}  // namespace IO
namespace solution
{
    using namespace IO;
    typedef double dbi;
    typedef long long i64;

    const i64 INF  = 1e10;
    const int MAXN = 2e5 + 5;

    struct Node
    {
        i64 x, y;
        bool type;  // 0 for station, 1 for agent
    };
    bool operator<(const Node &a, const Node &b)
    {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }

    int t;
    int n;
    dbi ans = INF;
    Node node[MAXN];

    dbi calc(const Node &x, const Node &y)
    {
        if (x.type == y.type)
        {
            return INF;
        }
        return std::sqrt((x.x - y.x) * (x.x - y.x) + (x.y - y.y) * (x.y - y.y));
    }

    void solve(int l, int r)
    {
        if (l == r)
        {
            return;
        }

        i64 mid = (l + r) >> 1, h = node[mid].x;

        solve(l, mid), solve(mid + 1, r);

        auto begin = std::lower_bound(node + l, node + r + 1, Node{h - i64(std::ceil(ans)), -INF, 0}),
             end   = std::upper_bound(node + l, node + r + 1, Node{h + i64(std::ceil(ans)), INF, 1});

        for (auto i = begin; i != end; i++)
        {
            for (auto j = begin; j != end; j++)
            {
                if (i != j)
                {
                    ans = std::min(ans, calc(*i, *j));
                }
            }
        }
    }

    int main()
    {
        std::fixed(std::cout);
        std::cout.precision(3);

        read(t);
        while (t--)
        {
            ans = INF;

            read(n);
            for (int i = 1; i <= n; i++)
            {
                read(node[i].x, node[i].y), node[i].type = 0;
            }
            for (int i = n + 1; i <= 2 * n; i++)
            {
                read(node[i].x, node[i].y), node[i].type = 1;
            }

            std::sort(node + 1, node + 2 * n + 1);

            solve(1, 2 * n);
            write(ans);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}