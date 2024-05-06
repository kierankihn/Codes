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

    const int MAXN = 2e5 + 5;
    const int MOD  = 1e9 + 7;

    struct Node
    {
        i64 k, b;
        i64 calc(i64 x)
        {
            return (k * x + b) % MOD;
        }
    };
    Node operator+(const Node a, const Node b)
    {
        return {b.k * a.k % MOD, (a.b * b.k + b.b) % MOD};
    }

    int n, m;
    i64 ak[MAXN], ab[MAXN];

    Node node[MAXN << 2];
    void build(int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o] = {ak[l], ab[l]};
            return;
        }

        int mid = (l + r) >> 1;
        build(o << 1, l, mid), build(o << 1 | 1, mid + 1, r);

        node[o] = node[o << 1] + node[o << 1 | 1];
    }
    void update(int x, i64 vk, i64 vb, int o = 1, int l = 1, int r = n)
    {
        if (l == r)
        {
            node[o] = {vk, vb};
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, vk, vb, o << 1, l, mid);
        }
        else
        {
            update(x, vk, vb, o << 1 | 1, mid + 1, r);
        }

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

        return {};
    }

    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            read(ak[i], ab[i]);
        }

        build();

        for (int i = 1; i <= m; i++)
        {
            std::string op = reads();

            if (op == "M")
            {
                int x = readi(), k = readi(), b = readi();

                update(x, k, b);
            }
            if (op == "Q")
            {
                int l = readi(), r = readi(), x = readi();

                write(query(l, r).calc(x));
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