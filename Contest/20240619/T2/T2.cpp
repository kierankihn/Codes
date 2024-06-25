/**
 * @author Kieran Kihn
 * @date 2024.06.19
 * @name T2
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

    constexpr int P    = 2e5;
    constexpr int MAXN = 2e5 + 5;

    struct Node
    {
        int sum;
        int lson, rson;
    };

    int n, q;
    int a[MAXN];

    int size = 0;
    int root[MAXN];
    Node node[MAXN * 40];

    void pushup(int o)
    {
        node[o].sum = node[node[o].lson].sum + node[node[o].rson].sum;
    }
    void update(int x, int v, int &o, int l = 1, int r = P)
    {
        node[++size] = node[o], o = size;
        if (l == r)
        {
            node[o].sum += v;
            return;
        }

        int mid = (l + r) >> 1;
        if (x <= mid)
        {
            update(x, v, node[o].lson, l, mid);
        }
        if (x > mid)
        {
            update(x, v, node[o].rson, mid + 1, r);
        }

        pushup(o);
    }
    int query(int ql, int qr, int o, int l = 1, int r = P)
    {
        if (o == 0)
        {
            return 0;
        }
        if (ql <= l && r <= qr)
        {
            return node[o].sum;
        }

        int mid = (l + r) >> 1;
        if (mid >= ql && mid < qr)
        {
            return query(ql, qr, node[o].lson, l, mid) + query(ql, qr, node[o].rson, mid + 1, r);
        }
        if (mid >= ql)
        {
            return query(ql, qr, node[o].lson, l, mid);
        }
        if (mid < qr)
        {
            return query(ql, qr, node[o].rson, mid + 1, r);
        }

        return 0;
    }

    int solve(int left, int right)
    {
        int l = 1, r = P;
        while (l < r)
        {
            int mid = std::ceil((l + r) / 2.0);

            if (query(mid, P, root[right]) - query(mid, P, root[left - 1]) >= mid)
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        return l;
    }

    int main()
    {
        read(n, q);
        for (int i = 1; i <= n; i++)
        {
            read(a[i]);
            update(a[i], 1, root[i] = root[i - 1]);
        }

        for (int i = 1; i <= q; i++)
        {
            int l = readi(), r = readi();
            write(solve(l, r));
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}