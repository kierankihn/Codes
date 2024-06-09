/**
 * @author Kieran Kihn
 * @date 2024.06.09
 * @name F
 * @link
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
    typedef long long i64;

    constexpr int MAXN = 2e5 + 5;
    constexpr int MOD  = 998244353;

    struct Node
    {
        i64 sum, suma, sumb;
        i64 taga, tagb;
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {(a.sum + b.sum) % MOD, (a.suma + b.suma) % MOD, (a.sumb + b.sumb) % MOD, 0, 0};
    }

    int n, q;
    i64 a[MAXN], b[MAXN];

    Node node[MAXN << 2];
    void add(int op, i64 v, int o, int l, int r)
    {
        if (op == 1)
        {
            node[o].sum += node[o].sumb * v, node[o].sum %= MOD;
            node[o].suma += v * (r - l + 1), node[o].suma %= MOD;
            node[o].taga += v, node[o].taga %= MOD;
        }
        if (op == 2)
        {

            node[o].sum += node[o].suma * v, node[o].sum %= MOD;
            node[o].sumb += v * (r - l + 1), node[o].sumb %= MOD;
            node[o].tagb += v, node[o].tagb %= MOD;
        }
    }
    void pushdown(int o, int l, int r)
    {
        int mid = (l + r) >> 1;
        if (node[o].taga != 0)
        {
            add(1, node[o].taga, o << 1, l, mid);
            add(1, node[o].taga, o << 1 | 1, mid + 1, r);
            node[o].taga = 0;
        }
        if (node[o].tagb != 0)
        {
            add(2, node[o].tagb, o << 1, l, mid);
            add(2, node[o].tagb, o << 1 | 1, mid + 1, r);
            node[o].tagb = 0;
        }
    }
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o].sum = a[l] * b[l] % MOD, node[o].suma = a[l] % MOD, node[o].sumb = b[l] % MOD;
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void update(int op, int ql, int qr, i64 v, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            add(op, v, o, l, r);
            return;
        }

        pushdown(o, l, r);

        int mid = (l + r) >> 1;
        if (ql <= mid)
        {
            update(op, ql, qr, v, o << 1, l, mid);
        }
        if (qr > mid)
        {
            update(op, ql, qr, v, o << 1 | 1, mid + 1, r);
        }

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    i64 query(int ql, int qr, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            return node[o].sum;
        }

        pushdown(o, l, r);

        int mid = (l + r) >> 1;
        if (ql <= mid && qr > mid)
        {
            return (query(ql, qr, o << 1, l, mid) + query(ql, qr, o << 1 | 1, mid + 1, r)) % MOD;
        }
        if (ql <= mid)
        {
            return query(ql, qr, o << 1, l, mid);
        }
        if (qr > mid)
        {
            return query(ql, qr, o << 1 | 1, mid + 1, r);
        }

        return 0;
    }

    int main()
    {
        read(n, q);
        readAll(a + 1, a + n + 1);
        readAll(b + 1, b + n + 1);

        build();

        for (int i = 1; i <= q; i++)
        {
            int op = readi();
            if (op == 1 || op == 2)
            {
                i64 l = readi(), r = readi(), x = readi();
                update(op, l, r, x);
            }
            if (op == 3)
            {
                i64 l = readi(), r = readi();
                write(query(l, r));
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