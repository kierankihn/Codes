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

    constexpr int MAXN   = 5e5 + 5;
    constexpr int MAXP   = 3e7 + 5;
    constexpr int INF    = 0x3f3f3f3f;
    constexpr i64 MAXSUM = 1e15 + 5;

    struct Node
    {
        i64 min;
        int lson, rson;
    };

    int n;
    int ans;
    i64 a[MAXN];

    i64 sum = 0;
    i64 dp[MAXN];

    int size = 1;
    Node node[MAXP];
    void pushup(int o)
    {
        node[o].min = std::min(node[node[o].lson].min, node[node[o].rson].min);
    }
    void update(i64 x, i64 v, int o = 1, i64 l = -MAXSUM, i64 r = MAXSUM)
    {
        if (l == r)
        {
            node[o] = {v};
            return;
        }

        i64 mid = (l + r) >> 1;
        if (x <= mid)
        {
            if (node[o].lson == 0)
            {
                node[o].lson = ++size, node[node[o].lson] = {INF, 0, 0};
            }
            update(x, v, node[o].lson, l, mid);
        }
        if (x > mid)
        {
            if (node[o].rson == 0)
            {
                node[o].rson = ++size, node[node[o].rson] = {INF, 0, 0};
            }
            update(x, v, node[o].rson, mid + 1, r);
        }

        pushup(o);
    }
    i64 query(i64 ql, i64 qr, int o = 1, i64 l = -MAXSUM, i64 r = MAXSUM)
    {
        if (o == 0)
        {
            return INF;
        }
        if (ql <= l && r <= qr)
        {
            return node[o].min;
        }

        i64 mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            return std::min(query(ql, qr, node[o].lson, l, mid), query(ql, qr, node[o].rson, mid + 1, r));
        }
        if (mid >= ql)
        {
            return query(ql, qr, node[o].lson, l, mid);
        }
        if (mid < qr)
        {
            return query(ql, qr, node[o].rson, mid + 1, r);
        }

        return INF;
    }

    int main()
    {
        node[0].min = INF;
        std::fill(dp, dp + MAXN, INF);

        read(n);
        readAll(a + 1, a + n + 1);

        dp[0] = 0, update(0, 0);
        for (int i = 1; i <= n; i++)
        {
            sum += a[i];
            if (a[i] >= 0)
            {
                dp[i] = dp[i - 1];
            }

            dp[i] = std::min(dp[i], query(-MAXSUM, sum) + i - 1);
            update(sum, dp[i] - i);
        }

        write(dp[n] == INF ? -1 : dp[n]);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}