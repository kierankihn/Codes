/**
 * @author Kieran Kihn
 * @date 2024.07.06
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
    typedef std::pair<std::pair<int, int>, int> p3i;

    constexpr int MAXN = 2e5 + 5;

    int n, q;
    int a[MAXN], pos[MAXN];

    std::vector<int> b[MAXN];

    std::vector<p3i> qs[MAXN];

    i64 ans[MAXN];

    i64 sum[MAXN];

    int lowbit(int x)
    {
        return x & (-x);
    }
    void update(int x, i64 v)
    {
        while (x <= n)
        {
            sum[x] += v, x += lowbit(x);
        }
    }
    i64 query(int x)
    {
        i64 res = 0;
        while (x > 0)
        {
            res += sum[x], x -= lowbit(x);
        }
        return res;
    }

    int main()
    {
        read(n, q);
        for (int i = 1; i <= n; i++)
        {
            pos[a[i] = readi()] = i;
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; i * j <= n; j++)
            {
                b[pos[i]].push_back(pos[i * j]);
            }
        }

        for (int i = 1; i <= q; i++)
        {
            int l = readi(), r = readi();
            qs[l - 1].push_back({{l - 1, 1}, i});
            qs[l - 1].push_back({{r, -1}, i});
            qs[r].push_back({{l - 1, -1}, i});
            qs[r].push_back({{r, 1}, i});
        }

        for (int i = 1; i <= n; i++)
        {
            for (auto j : b[i])
            {
                update(j, 1);
            }

            for (auto qi : qs[i])
            {
                ans[qi.second] += query(qi.first.first) * qi.first.second;
            }
        }

        for (int i = 1; i <= q; i++)
        {
            write(ans[i]);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}