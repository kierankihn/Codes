/**
 * @author Kieran Kihn
 * @date 2024.06.05
 * @name CF932F
 * @link https://codeforces.com/contest/932/problem/F
 */
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
    typedef double dbi;
    typedef long long i64;

    constexpr int MAXV = 1e5;
    constexpr int MAXN = 1e5 + 5;
    constexpr i64 INF  = 0x3f3f3f3f3f3f3f3f;

    int n;
    i64 a[MAXN], b[MAXN];

    std::vector<int> e[MAXN];

    struct Line
    {
        i64 k, b;
        i64 calc(i64 x)
        {
            return x * k + b;
        }
    };

    struct Node
    {
        Line line;
        int lson, rson;
    };

    int size = 0;
    int root[MAXN];
    Node node[MAXN << 2];

    void update(Line x, int &o, int l = -MAXV, int r = MAXV)
    {
        if (o == 0)
        {
            node[o = ++size] = {x, 0, 0};
            return;
        }

        if (node[o].line.calc(l) <= x.calc(l) && node[o].line.calc(r) <= x.calc(r))
        {
            return;
        }
        if (x.calc(l) <= node[o].line.calc(l) && x.calc(r) <= node[o].line.calc(r))
        {
            node[o].line = x;
            return;
        }

        int mid = (l + r) >> 1;
        if (x.calc(mid) < node[o].line.calc(mid))
        {
            std::swap(node[o].line, x);
        }
        if (node[o].line.k <= x.k)
        {
            update(x, node[o].lson, l, mid);
        }
        else
        {
            update(x, node[o].rson, mid + 1, r);
        }
    }
    i64 query(i64 x, int o, int l = -MAXV, int r = MAXV)
    {
        if (o == 0)
        {
            return INF;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            return std::min(node[o].line.calc(x), query(x, node[o].lson, l, mid));
        }
        else
        {
            return std::min(node[o].line.calc(x), query(x, node[o].rson, mid + 1, r));
        }
    }
    int merge(int x, int y, int l = -MAXV, int r = MAXV)
    {
        if (x == 0 || y == 0)
        {
            return x | y;
        }

        if (l == r)
        {
            if (node[x].line.calc(l) <= node[y].line.calc(l))
            {
                return x;
            }
            else
            {
                return y;
            }
        }

        int mid = (l + r) >> 1;

        node[x].lson = merge(node[x].lson, node[y].lson, l, mid);
        node[x].rson = merge(node[x].rson, node[y].rson, mid + 1, r);

        update(node[y].line, x, l, r);

        return x;
    }

    i64 dp[MAXN];
    void solve(int u, int fa)
    {
        for (auto v : e[u])
        {
            if (v != fa)
            {
                solve(v, u);
                root[u] = merge(root[u], root[v]);
            }
        }

        dp[u] = query(a[u], root[u]), dp[u] = dp[u] == INF ? 0 : dp[u];

        update({b[u], dp[u]}, root[u]);
    }

    int main()
    {
        read(n);
        readAll(a + 1, a + n + 1);
        readAll(b + 1, b + n + 1);
        for (int i = 1; i < n; i++)
        {
            int u = readi(), v = readi();
            e[u].push_back(v), e[v].push_back(u);
        }

        solve(1, 0);

        writeAll(dp + 1, dp + n + 1);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}