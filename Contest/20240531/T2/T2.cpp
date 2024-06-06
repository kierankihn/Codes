/**
 * @author Kieran Kihn
 * @date 2024.05.31
 * @name CF1841D
 * @link https://codeforces.com/contest/1841/problem/D
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
    typedef std::pair<int, int> pii;

    constexpr int MAXN  = 2e3 + 5;
    constexpr int MAXN2 = 4e6 + 5;

    int t;

    int n;
    int a[MAXN], b[MAXN];

    int size = 0;
    pii l[MAXN2];

    int ans = 0, prev = -1;

    int main()
    {
        read(t);
        while (t--)
        {
            read(n);
            for (int i = 1; i <= n; i++)
            {
                read(a[i], b[i]);
            }

            size = 0;
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (i == j)
                    {
                        continue;
                    }

                    if ((a[i] <= a[j] && b[i] >= a[j]) || (a[i] <= b[j] && b[i] >= b[j]))
                    {
                        l[++size] = {std::min(a[i], a[j]), std::max(b[i], b[j])};
                    }
                }
            }

            std::sort(l + 1, l + size + 1, [](const pii &a, const pii &b)
                      { return a.second < b.second; });

            ans = 0, prev = -1;
            for (int i = 1; i <= size; i++)
            {
                if (l[i].first > prev)
                {
                    ans++, prev = l[i].second;
                }
            }

            write(n - ans * 2);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}