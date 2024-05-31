/**
 * @author Kieran Kihn
 * @date 2024.05.31
 * @name CF1934D1
 * @link https://codeforces.com/contest/1934/problem/D1
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

    int t;
    i64 n, m;

    int main()
    {
        read(t);
        while (t--)
        {
            read(n, m);

            i64 x01 = 0, x10 = 0, top = 0;
            for (i64 i = 63; i >= 1; i--)
            {
                i64 np = (n >> (i - 1)) & 1, mp = (m >> (i - 1)) & 1;

                if (np == 0 && mp == 1)
                {
                    x01 |= (1LL << (i - 1));
                }
                if (np == 1 && mp == 0)
                {
                    x10 |= (1LL << (i - 1));
                    top = std::max(top, i);
                }
            }

            if (x01 != 0)
            {
                if (top == 0)
                {
                    write(-1);
                    continue;
                }
                else
                {
                    if ((x01 | (1LL << (top - 1))) >= n || (n ^ (x01 | (1LL << (top - 1)))) >= n)
                    {
                        write(-1);
                        continue;
                    }
                    else
                    {
                        if ((x10 ^ (1LL << (top - 1))) != 0)
                        {
                            write(2);
                            write(n, (n ^ (x01 | (1LL << (top - 1)))), m);
                        }
                        else
                        {
                            write(1);
                            write(n, m);
                        }
                    }
                }
            }
            else
            {
                write(1);
                write(n, m);
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

/**
 * 0110 1011
 * 0000 1010
*/