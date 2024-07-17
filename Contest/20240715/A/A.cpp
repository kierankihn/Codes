/**
 * @author Kieran Kihn
 * @date 2024.07.15
 * @name A
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

    constexpr int MAXN = 3e5 + 5;

    int n, q;

    int a[MAXN], pos[MAXN];

    int b[MAXN];
    int sum[MAXN];
    int lowbit(int x)
    {
        return x & (-x);
    }
    int query(int x)
    {
        int res = 0;
        while (x > 0)
        {
            res += sum[x], x -= lowbit(x);
        }
        return res;
    }
    void update(int x, int v)
    {
        while (x <= n)
        {
            sum[x] += v, x += lowbit(x);
        }
    }
    void modify(int x, int v)
    {
        update(x, -b[x]), update(x, b[x] = v);
    }

    int main()
    {
        read(n);
        for (int i = 1; i <= n; i++)
        {
            pos[a[i] = readi()] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            if (pos[i] < pos[i - 1])
            {
                update(i, b[i] = 1);
            }
        }

        read(q);
        for (int i = 1; i <= q; i++)
        {
            int op = readi();
            if (op == 1)
            {
                int l = readi(), r = readi();
                write(query(r) - query(l) + 1);
            }
            if (op == 2)
            {
                int x = readi(), y = readi();

                pos[a[x]] = y, pos[a[y]] = x;

                modify(a[x], pos[a[x]] < pos[a[x] - 1]), modify(a[x] + 1, pos[a[x] + 1] < pos[a[x]]);
                modify(a[y], pos[a[y]] < pos[a[y] - 1]), modify(a[y] + 1, pos[a[y] + 1] < pos[a[y]]);

                std::swap(a[x], a[y]);
            }
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
} // Hydro