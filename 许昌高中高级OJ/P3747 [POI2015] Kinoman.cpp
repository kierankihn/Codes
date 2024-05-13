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

    const int MAXN = 1e6 + 5;

    struct Node
    {
        i64 max, tag = 0;
    };
    Node operator+(const Node a, const Node b)
    {
        return {std::max(a.max, b.max)};
    }

    int n, m;
    i64 movie[MAXN], w[MAXN], next[MAXN], now[MAXN];

    i64 ans = 0;

    i64 a[MAXN];
    Node node[MAXN << 2];
    void pushdown(int o, int l, int r)
    {
        node[o << 1].max += node[o].tag, node[o << 1].tag += node[o].tag;
        node[o << 1 | 1].max += node[o].tag, node[o << 1 | 1].tag += node[o].tag;
        node[o].tag = 0;
    }
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o] = {a[l]};
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void update(int ql, int qr, i64 v, int o = 1, int l = 1, int r = n)
    {
        if (ql == 0 || qr == -1)
        {
            return;
        }
        if (ql <= l && r <= qr)
        {
            node[o].max += v, node[o].tag += v;
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
    i64 query(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            return node[o].max;
        }

        pushdown(o, l, r);

        int mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            return std::max(query(ql, qr, o << 1, l, mid), query(ql, qr, o << 1 | 1, mid + 1, r));
        }
        if (mid >= ql)
        {
            return query(ql, qr, o << 1, l, mid);
        }
        if (mid < qr)
        {
            return query(ql, qr, o << 1 | 1, mid + 1, r);
        }

        return 0;
    }

    int main()
    {
        read(n, m);
        readAll(movie + 1, movie + n + 1), readAll(w + 1, w + m + 1);

        std::fill(now + 1, now + m + 1, n + 1);
        for (int i = n; i >= 1; i--)
        {
            next[i] = now[movie[i]], now[movie[i]] = i;
        }

        std::fill(now + 1, now + m + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            if (now[movie[i]] == 0)
            {
                a[i] = a[i - 1] + w[movie[i]], now[movie[i]] = 1;
            }
            else if (now[movie[i]] == 1)
            {
                a[i] = a[i - 1] - w[movie[i]], now[movie[i]] = 2;
            }
            else if (now[movie[i]] == 2)
            {
                a[i] = a[i - 1];
            }
        }

        build();

        ans = query(1, n);
        for (int i = 1; i <= n; i++)
        {
            update(i, next[i] - 1, -w[movie[i]]);
            update(next[i], next[next[i]] - 1, w[movie[i]]);
            ans = std::max(ans, query(1, n));
        }

        write(ans);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}