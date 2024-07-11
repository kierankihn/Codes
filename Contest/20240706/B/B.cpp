/**
 * @author Kieran Kihn
 * @date 2024.07.06
 * @name B
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
    typedef std::pair<int, std::pair<int, int>> p3i;

    constexpr int MAXN = 300 + 5;
    constexpr int MAXM = 2e5 + 5;

    i64 n, m, d;
    p3i a[MAXN];

    int prev = 0, now = 1;
    i64 dp[2][MAXM];

    int main()
    {
        read(m, n, d);
        for (int i = 1; i <= n; i++)
        {
            read(a[i].second.first, a[i].second.second, a[i].first);
        }

        std::sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            std::deque<int> s;

            i64 len = std::min(m, (a[i].first - a[i - 1].first) * d);
            for (int j = 1; j <= len; j++)
            {
                while (s.empty() == false && dp[prev][j] >= dp[prev][s.back()])
                {
                    s.pop_back();
                }
                s.push_back(j);
            }

            for (int j = 1; j <= m; j++)
            {
                if (s.empty() == false && s.front() < j - len)
                {
                    s.pop_front();
                }
                if (j + len <= m)
                {
                    while (s.empty() == false && dp[prev][j + len] >= dp[prev][s.back()])
                    {
                        s.pop_back();
                    }
                    s.push_back(j + len);
                }

                dp[now][j] = a[i].second.second - std::abs(a[i].second.first - j) + dp[prev][s.front()];
            }

            std::swap(prev, now);
        }

        dp[prev][0] = -1e18;
        for (int i = 1; i <= m; i++)
        {
            dp[prev][0] = std::max(dp[prev][0], dp[prev][i]);
        }

        write(dp[prev][0]);

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}