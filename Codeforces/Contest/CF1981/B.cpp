/**
 * @author Kieran Kihn
 * @date 2024.05.29
 * @name CF1981B
 * @link https://codeforces.com/contest/1981/problem/B
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

    constexpr i64 MAX1 = (1LL << 50LL) - 1;

    int t;

    i64 n, m;

    i64 ans = 0;

    i64 lowbit(i64 x)
    {
        return x & (-x);
    }

    i64 get(i64 x)
    {

        return (MAX1 - ((1LL << (x - 1)) - 1));
    }

    int main()
    {
        read(t);
        while (t--)
        {
            ans = 0;
            read(n, m);
            for (int i = 1; i <= 32; i++)
            {
                if (n & (1LL << (i - 1)))
                {
                    ans |= (1LL << (i - 1));
                }
                if (std::abs(n - ((n | (1LL << (i - 1))) & get(i))) <= m)
                {
                    ans |= (1LL << (i - 1));
                }
                if (lowbit(n & get(i)) != 0 && std::abs(n - ((n ^ lowbit(n & get(i))) | ((lowbit(n & get(i))) - 1))) <= m)
                {
                    ans |= (1LL << (i - 1));
                }
            }

            write(ans);
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}

/**
 * 1000 - 10 =
 */