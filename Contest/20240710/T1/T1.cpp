/**
 * @author Kieran Kihn
 * @date 2024.07.10
 * @name T1
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

    constexpr int MAXN = 1e5 + 5;

    int n, k;
    i64 a[MAXN];

    i64 ans = 0;

    bool check3(std::vector<i64> x)
    {
        return x[0] + x[1] > x[2];
    }
    bool check6(std::vector<i64> x)
    {
        for (int umask = 0; umask < (1 << 6); umask++)
        {
            if (__builtin_popcount(umask) == 3)
            {
                std::vector<i64> a, b;
                for (int j = 1; j <= 6; j++)
                {
                    if (umask & (1 << (j - 1)))
                    {
                        a.push_back(x[j - 1]);
                    }
                    else
                    {
                        b.push_back(x[j - 1]);
                    }
                }

                if (check3(a) && check3(b))
                {
                    return true;
                }
            }
        }

        return false;
    }
    bool check9(std::vector<i64> x)
    {
        for (int umask = 0; umask < (1 << 9); umask++)
        {
            if (__builtin_popcount(umask) == 3)
            {
                std::vector<i64> a, b;
                for (int j = 1; j <= 9; j++)
                {
                    if (umask & (1 << (j - 1)))
                    {
                        a.push_back(x[j - 1]);
                    }
                    else
                    {
                        b.push_back(x[j - 1]);
                    }
                }

                if (check3(a) && check6(b))
                {
                    return true;
                }
            }
        }

        return false;
    }

    i64 solve3()
    {
        i64 kk = k, res = 0;
        for (int i = n; i >= 3; i--)
        {
            if (check3({a[i - 2], a[i - 1], a[i]}))
            {
                kk--, res += a[i] + a[i - 1] + a[i - 2], i -= 2;
            }
            if (kk == 0)
            {
                return res;
            }
        }

        return -1;
    }
    i64 solve6()
    {
        for (int i = n; i >= 6; i--)
        {
            if (check6({a[i - 5], a[i - 4], a[i - 3], a[i - 2], a[i - 1], a[i]}))
            {
                return a[i] + a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4] + a[i - 5];
            }
        }

        return -1;
    }
    i64 solve36()
    {
        i64 res = 0, flag = 0;
        for (int i = n; i >= 3; i--)
        {
            if (flag == 0 && i < 6)
            {
                return -1;
            }
            if (flag == 0 && check6({a[i - 5], a[i - 4], a[i - 3], a[i - 2], a[i - 1], a[i]}))
            {
                flag = 1;
                res += a[i] + a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4] + a[i - 5];
                i -= 5;
                continue;
            }
            if (flag == 1 && check3({a[i - 2], a[i - 1], a[i]}))
            {
                return res += a[i] + a[i - 1] + a[i - 2];
            }
        }

        return -1;
    }
    i64 solve63()
    {
        i64 res = 0, flag = 0;
        for (int i = n; i >= 6; i--)
        {
            if (flag == 0 && check3({a[i - 2], a[i - 1], a[i]}))
            {
                flag = 1;
                res += a[i] + a[i - 1] + a[i - 2];
                i -= 2;
                continue;
            }
            if (flag == 1 && check6({a[i - 5], a[i - 4], a[i - 3], a[i - 2], a[i - 1], a[i]}))
            {
                return res += a[i] + a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4] + a[i - 5];
            }
        }

        return -1;
    }
    i64 solve9()
    {
        for (int i = n; i >= 9; i--)
        {
            if (check9({a[i - 8], a[i - 7], a[i - 6], a[i - 5], a[i - 4], a[i - 3], a[i - 2], a[i - 1], a[i]}))
            {
                return a[i] + a[i - 1] + a[i - 2] + a[i - 3] + a[i - 4] + a[i - 5] + a[i - 6] + a[i - 7] + a[i - 8];
            }
        }

        return -1;
    }

    int main()
    {
        read(n, k);
        readAll(a + 1, a + n + 1);

        std::sort(a + 1, a + n + 1);

        if (n > 100)
        {
            for (int i = 1; i <= 100; i++)
            {
                a[i] = a[n - 100 + i];
            }
            n = 100;
        }

        if (k == 1)
        {
            write(solve3());
        }
        if (k == 2)
        {
            write(std::max({solve3(), solve6()}));
        }
        if (k == 3)
        {
            write(std::max({solve3(), solve36(), solve63(), solve9()}));
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}