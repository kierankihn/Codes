/**
 * @author Kieran Kihn
 * @date 2024.07.15
 * @name E
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
    typedef std::pair<int, int> pii;

    constexpr int MAXM  = 8 + 5;
    constexpr int MAXN  = 3e5 + 5;
    constexpr int MAX2M = (1 << 8) + 5;

    int n, m;
    int a[MAXN][MAXM];

    int bucket[MAX2M];

    pii check(int x)
    {
        for (auto &i : bucket)
        {
            i = 0;
        }

        for (int i = 1; i <= n; i++)
        {
            int umask = 0;
            for (int j = 1; j <= m; j++)
            {
                if (a[i][j] >= x)
                {
                    umask |= 1 << (j - 1);
                }
            }
            bucket[umask] = i;
        }

        for (int i = 0; i < (1 << m); i++)
        {
            for (int j = 0; j < (1 << m); j++)
            {
                if ((i | j) == (1 << m) - 1)
                {
                    if (bucket[i] && bucket[j])
                    {
                        return {bucket[i], bucket[j]};
                    }
                }
            }
        }

        return {0, 0};
    }


    int main()
    {
        read(n, m);
        for (int i = 1; i <= n; i++)
        {
            readAll(a[i] + 1, a[i] + m + 1);
        }

        int l = 0, r = 1e9;
        while (l < r)
        {
            int mid = std::ceil((l + r) / 2.0);
            if (check(mid) != pii{0, 0})
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }

        auto ans = check(l);

        write(ans.first, ans.second);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
} // Hydro