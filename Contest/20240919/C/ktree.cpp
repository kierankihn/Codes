/**
 * @author Kieran Kihn
 * @date 2024.09.19
 * @name ktree
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

    constexpr int MAXN = 1e5 + 5;
    constexpr int INF  = 0x3f3f3f3f;

    int t;

    int n, k, m, len = 1;

    std::vector<pii> restriction;

    int op[MAXN];

    int a[MAXN];
    int sum[MAXN];

    int ans = 0;

    bool check_once()
    {
        for (int i = 1; i <= len; i++)
        {
            sum[i] = sum[i - 1] + a[i];
        }
        for (int i = 2, j = k; i <= k; i++, j *= k)
        {
            int max = -INF, min = INF;
            for (int l = 1; l <= len; l += j)
            {
                min = std::min(min, sum[l + k - 1] - sum[l - 1]);
                max = std::max(max, sum[l + k - 1] - sum[l - 1]);
            }

            if (max - min > 1)
            {
                return false;
            }
        }

        return true;
    }

    bool check()
    {
        for (auto i : restriction)
        {
            if (op[i.first] != i.second)
            {
                return false;
            }
        }

        for (int i = 1; i <= len; i++)
        {
            a[i] = 0;
        }

        for (int i = 1; i <= len; i++)
        {
            a[op[i]]++;
            if (check_once() == false)
            {
                return false;
            }
        }

        return true;
    }

    int main()
    {
        read(t);
        while (t--)
        {
            len = 1, ans = 0, restriction.clear();

            read(k, n, m);
            for (int i = 1; i <= n; i++)
            {
                len *= k;
            }

            for (int i = 1; i <= m; i++)
            {
                int x = readi(), y = readi();
                restriction.push_back({x, y});
            }

            for (int i = 1; i <= len; i++)
            {
                op[i] = i;
            }

            do
            {
                if (check())
                {
                    ans++;
                }
            } while (std::next_permutation(op + 1, op + len + 1));

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