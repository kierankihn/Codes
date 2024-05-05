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

    int n, m, p;
    int a[MAXN];

    struct Node
    {
        i64 sum, add = -1, mul = -1;
        void update_add(i64 x)
        {
            if (add == -1)
            {
                add = x;
            }
            else
            {
                add += x;
            }
            add %= p;
        }
        void update_mul(i64 x)
        {
            if (add != -1)
            {
                add *= x;
            }
            add %= p;
            if (mul == -1)
            {
                mul = x;
            }
            else
            {
                mul = mul * x;
            }
            mul %= p;
        }
    };
    Node operator+(const Node &a, const Node &b)
    {
        return {(a.sum + b.sum) % p};
    }

    Node node[MAXN << 2];
    void pushdown(int o, int l, int r)
    {
        int mid = (l + r) >> 1;
        if (node[o].mul != -1)
        {
            node[o << 1].sum *= node[o].mul, node[o << 1].sum %= p;
            node[o << 1 | 1].sum *= node[o].mul, node[o << 1 | 1].sum %= p;
            node[o << 1].update_mul(node[o].mul), node[o << 1 | 1].update_mul(node[o].mul), node[o].mul = -1;
        }
        if (node[o].add != -1)
        {
            node[o << 1].sum += node[o].add * (mid - l + 1), node[o << 1].sum %= p;
            node[o << 1 | 1].sum += node[o].add * (r - mid), node[o << 1 | 1].sum %= p;
            node[o << 1].update_add(node[o].add), node[o << 1 | 1].update_add(node[o].add), node[o].add = -1;
        }
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
    void add(int ql, int qr, i64 v, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            node[o].sum += (r - l + 1) * v, node[o].sum %= p;
            node[o].update_add(v);
            return;
        }

        pushdown(o, l, r);

        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            add(ql, qr, v, o << 1, l, mid);
        }
        if (mid < qr)
        {
            add(ql, qr, v, o << 1 | 1, mid + 1, r);
        }

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void mul(int ql, int qr, i64 v, int o = 1, int l = 1, int r = n)
    {
        if (ql <= l && r <= qr)
        {
            node[o].sum *= v, node[o].sum %= p;
            node[o].update_mul(v);
            return;
        }

        pushdown(o, l, r);

        int mid = (l + r) >> 1;
        if (mid >= ql)
        {
            mul(ql, qr, v, o << 1, l, mid);
        }
        if (mid < qr)
        {
            mul(ql, qr, v, o << 1 | 1, mid + 1, r);
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

        return {0};
    }

    int main()
    {
        read(n, m, p);
        readAll(a + 1, a + n + 1);

        build();
        for (int i = 1; i <= m; i++)
        {
            int op = reads();

            if (op == 1)
            {
                int l = reads(), r = reads(), v = reads();
                mul(l, r, v);
            }
            if (op == 2)
            {
                int l = reads(), r = reads(), v = reads();
                add(l, r, v);
            }
            if (op == 3)
            {
                int l = reads(), r = reads();
                write(query(l, r).sum);
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