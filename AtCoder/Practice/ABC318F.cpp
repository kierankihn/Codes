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

    const int MAXN  = 2e2 + 5;
    const int MAXN2 = 4e4 + 5;

    int n;
    i64 a[MAXN], l[MAXN];

    i64 ans = 0;

    std::vector<i64> p;

    bool check(i64 x)
    {
        std::sort(a + 1, a + n + 1, [&](const i64 &a1, const i64 &a2)
                  { return std::abs(a1 - x) < std::abs(a2 - x); });

        for (int i = 1; i <= n; i++)
        {
            if (std::abs(a[i] - x) > l[i])
            {
                return false;
            }
        }

        return true;
    }

    int main()
    {
        read(n);
        readAll(a + 1, a + n + 1), std::sort(a + 1, a + n + 1);
        readAll(l + 1, l + n + 1), std::sort(l + 1, l + n + 1);

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                p.push_back(a[i] - l[j] - 1), p.push_back(a[i] + l[j]);
            }
        }

        std::sort(p.begin(), p.end());

        for (std::size_t i = 1; i < p.size(); i++)
        {
            if (check(p[i]))
            {
                ans += p[i] - p[i - 1];
            }
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