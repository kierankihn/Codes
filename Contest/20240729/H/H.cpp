/**
 * @author Kieran Kihn
 * @date 2024.07.29
 * @name DEBUG
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

    constexpr int MAXN = 100 + 5;

    int k;
    int n, m;

    std::set<int> e[MAXN];

    void solve()
    {
        if (k & 1)
        {
            n = k + 1;
            for (int i = 1; i <= n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    e[i].insert(j);
                }
            }
            e[1].erase(n);

            e[n].insert(n + 1), n++;
            for (int i = 1; i * 2 + 1 <= k; i++)
            {
                int u = i * 2 - 1, v = i * 2;
                e[u].erase(v);
                e[u].insert(n), e[v].insert(n);
            }

            write("YES");
            write(2 * n, n * k);
            write(1, n + 1);
            for (int u = 1; u <= n; u++)
            {
                for (auto v : e[u])
                {
                    write(u, v);
                }
            }
            for (int u = 1; u <= n; u++)
            {
                for (auto v : e[u])
                {
                    write(u + n, v + n);
                }
            }
        }
        else
        {
            write("NO");
        }
    }

    int main()
    {
        read(k);

        if (k == 1)
        {
            write("YES");
            write(2, 1);
            write(1, 2);
        }
        else
        {
            solve();
        }

        return 0;
    }
}  // namespace solution
int main()
{
    solution::main();
    return 0;
}